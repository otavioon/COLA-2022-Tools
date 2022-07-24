#! /usr/bin/env python3
# -*- coding: utf-8 -*-

"""
Copyright 2021 Anderson Faustino da Silva.

Licensed under the Apache License, Version 2.0 (the "License");
you may not use this file except in compliance with the License.
You may obtain a copy of the License at

http://www.apache.org/licenses/LICENSE-2.0

Unless required by applicable law or agreed to in writing, software
distributed under the License is distributed on an "AS IS" BASIS,
WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
See the License for the specific language governing permissions and
limitations under the License.
"""

#
# Imports
#
import os
import sys
import glob
import time
import wandb
import yaml
import pickle
import numpy as np
import pandas as pd
import subprocess
import datetime
import argparse

from pathlib import Path

os.environ['TF_CPP_MIN_LOG_LEVEL'] = '3'

# from absl import app, flags, logging

from sklearn import model_selection
from sklearn.metrics import confusion_matrix, classification_report

from stellargraph.mapper import PaddedGraphGenerator
from stellargraph.layer import DeepGraphCNN
from stellargraph import StellarDiGraph

from tensorflow.keras.optimizers import Adam
from tensorflow.keras.losses import categorical_crossentropy
from tensorflow.keras.callbacks import EarlyStopping

from models import create_model_lstm, create_model_dcnn, create_model_gcn, create_model_dgcnn


def load_sequence_dataset(dataset_directory: Path, dataset_description: Path):
    with dataset_description.open("r") as f:
        description_dataset = yaml.load(f, Loader=yaml.FullLoader)

    dataset_name = dataset_directory.stem

    X = {'training': [], 'validation': [], 'test': []}
    Y = {'training': [], 'validation': [], 'test': []}
    labels = []
    errors = []

    for phase, phase_data in description_dataset.items():
        for label, samples in phase_data.items():
            int_label = int(label)
            labels.append(int_label)
            data_directory = dataset_directory / str(label)
            for sample in samples:
                try:
                    filename = data_directory / f"{sample}.npz"
                    representation = np.load(filename, allow_pickle=True)
                    representation = representation['values']
                    Y[phase].append(int_label)
                    X[phase].append(representation)
                except FileNotFoundError:
                    errors.append(sample)
                    continue

    if errors:
        print(f"There are {len(errors)} errored files")

    labels = list(dict.fromkeys(labels))

    # Divide into train, validation and test
    X_train, Y_train = np.array(X['training']), np.array(Y['training'])
    X_val, Y_val = np.array(X['validation']), np.array(Y['validation'])
    X_test, Y_test = np.array(X['test']), np.array(Y['test'])

    Y_train = pd.get_dummies(Y_train)
    Y_val = pd.get_dummies(Y_val)
    Y_test = pd.get_dummies(Y_test)

    return X_train, Y_train, X_val, Y_val, X_test, Y_test, len(labels)

def load_graph_dataset(dataset_directory: Path, dataset_description: Path):
    with dataset_description.open("r") as f:
        description_dataset = yaml.load(f, Loader=yaml.FullLoader)

    X = []
    Y = {'training': [], 'validation': [], 'test': []}
    Y_index = {'training': [], 'validation': [], 'test': []}
    labels = []
    errors = list()

    for phase, phase_data in description_dataset.items():
        for label, samples in phase_data.items():
            int_label = int(label)
            labels.append(int_label)
            data_directory = dataset_directory / str(label)
            for sample in samples:
                filename = data_directory / f"{sample}.pk"
                try:
                    with filename.open("rb") as f:
                        representation = pickle.load(f)
                except FileNotFoundError as e:
                    # print(f"Invalid file: {e}")
                    errors.append(e)
                    continue

                Y[phase].append(int_label)
                Y_index[phase].append(len(X))
                X.append(representation)

    if errors:
        print(f"There are {len(errors)} errored files")
        # raise Exception("Error files")

    labels = list(dict.fromkeys(labels))

    Y_train = pd.Series(
        Y['training'], index=Y_index['training'],
        name='label', dtype="category"
    )
    Y_val = pd.Series(
        Y['validation'], index=Y_index['validation'],
        name='label', dtype="category"
    )
    Y_test = pd.Series(
        Y['test'], index=Y_index['test'],
        name='label', dtype="category"
    )

    Y_train = pd.get_dummies(Y_train)
    Y_val = pd.get_dummies(Y_val)
    Y_test = pd.get_dummies(Y_test)

    return X, Y_train, Y_val, Y_test, len(labels)


def is_graph_dataset(dataset_dir):
    dataset_directory = str(dataset_dir)
    if 'cfg' in dataset_directory:
        return True
    if 'cfg_compact' in dataset_directory:
        return True
    if 'cdfg' in dataset_directory:
        return True
    if 'cdfg_compact' in dataset_directory:
        return True
    if 'cdfg_plus' in dataset_directory:
        return True
    if 'programl' in dataset_directory:
        return True
    return False


def main(
        root_dataset_dir: Path, description_file: Path, output_dir: Path,
        model_type: str, representation: str, epochs: int =200,
        patience: int = 20, rounds: int = 1, silent: bool = False,
        print_model: bool = False, stats: bool = False, batch_size: int = 64):
    sequence_representations = [
        'inst2vec', 'ir2vec', 'milepost', 'histogram',
        'lbpeq', 'lbpif', 'prog2image'
    ]
    graph_dataset = is_graph_dataset(root_dataset_dir)
    print(f"Is graph dataset: {graph_dataset}")

    sequence_representations_2d = ['inst2vec', 'prog2image']

    times = dict()

    # ------------ Load representation ------------

    initial_time = time.time()
    start = time.time()

    if not graph_dataset:
        X_train, Y_train, X_val, Y_val, X_test, \
        Y_test, labels = load_sequence_dataset(
            dataset_directory=root_dataset_dir,
            dataset_description=description_file
        )
        if representation not in sequence_representations_2d:
            X_train = X_train.reshape(X_train.shape[0], X_train.shape[1], 1)
            X_val = X_val.reshape(X_val.shape[0], X_val.shape[1], 1)
            X_test = X_test.reshape(X_test.shape[0], X_test.shape[1], 1)
        elif model_type != "lstm":
            print(f"shape of X_train: {X_train.shape}")
            X_train = X_train.reshape(
                X_train.shape[0], X_train.shape[1], X_train.shape[2], 1
            )
            X_val = X_val.reshape(
                X_val.shape[0], X_val.shape[1], X_val.shape[2], 1
            )
            X_test = X_test.reshape(
                X_test.shape[0], X_test.shape[1], X_test.shape[2], 1
            )

    else:
        X, Y_train, Y_val, Y_test, labels = load_graph_dataset(
            dataset_directory=root_dataset_dir,
            dataset_description=description_file
        )
        gen = PaddedGraphGenerator(graphs=X)

        train_gen = gen.flow(list(Y_train.index),
                             targets=Y_train.values,
                             batch_size=batch_size,
                             symmetric_normalization=False)
        val_gen = gen.flow(list(Y_val.index),
                           targets=Y_val.values,
                           batch_size=1,
                           symmetric_normalization=False)
        test_gen = gen.flow(list(Y_test.index),
                            targets=Y_test.values,
                            batch_size=1,
                        symmetric_normalization=False)

    times["load"] = time.time()-start


    # ------------ Create the model ------------

    start = time.time()

    if not graph_dataset:
        model_dim = "2d" if representation in sequence_representations_2d else "1d"
        input_shape = X_train[0].shape
        embedding_dim =  X_train[0].shape[0] if model_type == '1d' else X_train[0].shape[1]

        if model_type == "lstm":
            model = create_model_lstm(labels, input_shape, embedding_dim)
        elif model_type == 'dcnn':
            model = create_model_dcnn(labels, input_shape, model_dim)
        else:
            raise ValueError(f"Invalid model_type: {model_type}")
    else:
        if model_type == "gcn":
            model = create_model_gcn(labels, X)
        elif model_type == "dgcnn":
            model = create_model_dgcnn(labels, X)
        else:
            raise ValueError(f"Invalid model_type: {model_type}")

    model.compile(optimizer=Adam(learning_rate=0.0001),
                  loss=categorical_crossentropy,
                  metrics=['accuracy'])

    times["model creation"] = time.time()-start

    if print_model:
        model.summary()

    # ------------ Do execution ------------
    for round in range(rounds):
        print(f" ------ Start execution of round {round}/{rounds-1} ------ ")
        round_start_time = time.time()
        callbacks = []
        if patience > 0:
            es_callback = EarlyStopping(
                monitor="val_accuracy", patience=patience,
                restore_best_weights=True
            )
            callbacks.append(es_callback)

        # Is sequence or graph representations?
        if not graph_dataset:
            start = time.time()
            history = model.fit(
                X_train, Y_train, validation_data=(X_val, Y_val),
                epochs=epochs, verbose=False if silent else True,
                shuffle=True, callbacks=callbacks, batch_size=batch_size)
            times[f"train"] = time.time()-start

            start = time.time()
            test_metrics = model.evaluate(X_test, Y_test)
            times[f"test eval round {round}"] = time.time()-start

            start = time.time()
            predicted = model.predict(X_test)
            times[f"test predict round {round}"] = time.time()-start

        # Graph
        else:
            start = time.time()
            history = model.fit(
                train_gen, validation_data=val_gen,
                epochs=epochs, verbose=False if silent else True,
                shuffle=True, callbacks=callbacks, batch_size=batch_size)
            times[f"train round {round}"] = time.time()-start

            start = time.time()
            test_metrics = model.evaluate(test_gen)
            times[f"test round {round}"] = time.time()-start

            start = time.time()
            predicted = model.predict(test_gen)
            times[f"test predict round {round}"] = time.time()-start

        pred_y = predicted.argmax(axis=-1)
        conf_matrix = confusion_matrix(Y_test.idxmax(axis=1), pred_y)
        class_report = classification_report(Y_test.idxmax(axis=1), pred_y)

        test_metrics_dict = {
            name: val
            for name, val in zip(model.metrics_names, test_metrics)
        }

        if stats:
            print(conf_matrix)
            print(class_report)
            print(f"Accuracy: {history.history['accuracy'][-1]}")
            print(f"Test metrics: {test_metrics_dict}")

        round_output_dir = output_dir / f"round{round+1}"
        round_output_dir.mkdir(parents=True, exist_ok=True)
        # Save all the files
        history_file = round_output_dir / f"history.yaml"
        with history_file.open("w") as f:
            yaml.dump(history.history, f)
        print(f"History saved to {history_file}")

        test_metrics_file = round_output_dir / f"test_metrics.yaml"
        with test_metrics_file.open("w") as f:
            yaml.dump(test_metrics_dict, f)
        print(f"Test metrics saved to {test_metrics_file}")

        if not graph_dataset:
            np.savez_compressed(round_output_dir / f"y_train.npz", values=Y_train)
            np.savez_compressed(round_output_dir / f"y_val.npz", values=Y_val)
            np.savez_compressed(round_output_dir / f"y_test.npz", values=Y_test)
        else:
            Y_train.to_pickle(round_output_dir / f"train_graphs.npz")
            Y_val.to_pickle(round_output_dir / f"val_graphs.npz")
            Y_test.to_pickle(round_output_dir / f"test_graphs.npz")

        np.savez_compressed(round_output_dir / f"predicted", values=predicted)
        np.savez_compressed(round_output_dir / f"confusion_matrix", values=conf_matrix)

        class_report_file = round_output_dir / f"classification_report.pk"
        with class_report_file.open("wb") as f:
            pickle.dump(class_report, f)
        print(f"Classification report saved to {class_report_file}")

        round_end_time = time.time()-round_start_time
        times[f"full loop round {round}"] = round_end_time
        print(f'Round {round} took {round_end_time:.3f} seconds')
        print()


    times["total"] = time.time()-initial_time
    # if stats:
    #     print(" ---- Times ---- ")
    #     print(yaml.dump(times, indent=4, sort_keys=True))

    times_file = output_dir / "elapsed_time.yaml"
    with times_file.open("w") as f:
        yaml.dump(times, f)

    return 0



# Execute
if __name__ == '__main__':
    parser = argparse.ArgumentParser(
        description='Train deep learning model',
        formatter_class=argparse.ArgumentDefaultsHelpFormatter)
    parser.add_argument("root_dataset_dir", action="store", type=str,
                        help="Directory to search for embedding files")
    parser.add_argument("description_file", action="store", type=str,
                        help="File with dataset description")
    parser.add_argument("output_dir", action="store", type=str,
                        help="Directory where representation files will be outputed")
    parser.add_argument("--model", type=str, required=False, default="dcnn",
                        choices=['lstm', 'dcnn', 'gcn', 'dgcnn'],
                        help="Deep learning model to use")
    parser.add_argument("--representation", type=str, required=True,
                        choices=[
                            'inst2vec', 'ir2vec', 'milepost', 'histogram',
                            'lbpeq', 'lbpif', 'prog2image'
                        ],
                        help="Representation used to train the model")
    parser.add_argument("--epochs", type=int, default=200,
                        help="Number of epochs to train")
    parser.add_argument("--patience", type=int, default=20,
                        help="Early stop: number of epochs without improvement")
    parser.add_argument("--batch_size", type=int, default=64,
                        help="Batch size")
    parser.add_argument("--rounds", type=int, default=1,
                        help="Number of times to repeat the experiment")
    parser.add_argument("--silent", action="store_true",
                        help="Do not display training progress")
    parser.add_argument("--print-model", action="store_true",
                        help="Print model before train")
    parser.add_argument("--stats", action="store_true",
                        help="Print summary information (confusion matrix, report)")

    args = parser.parse_args()
    print(args)

    root_dataset_dir = Path(args.root_dataset_dir)
    description_file = Path(args.description_file)
    output_dir = Path(args.output_dir)

    ret_code = main(
        root_dataset_dir=root_dataset_dir,
        description_file=description_file,
        output_dir=output_dir,
        model_type=args.model,
        representation=args.representation,
        epochs=args.epochs,
        patience=args.patience,
        rounds=args.rounds,
        silent=args.silent,
        print_model=args.print_model,
        stats=args.stats,
        batch_size=args.batch_size
    )
    sys.exit(ret_code)
