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

from absl import app, flags, logging

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

    for phase, phase_data in description_dataset.items():
        for label, samples in phase_data.items():
            int_label = int(label)
            labels.append(int_label)
            data_directory = dataset_directory / str(label)
            for sample in samples:
                filename = data_directory / f"{sample}.npz"
                representation = np.load(filename)
                representation = representation['values']
                Y[phase].append(int_label)
                X[phase].append(representation)

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

    for phase, phase_data in description_dataset.items():
        for label, samples in phase_data.items():
            int_label = int(label)
            labels.append(int_label)
            data_directory = dataset_directory / str(label)
            for sample in samples:
                filename = data_directory / f"{sample}.pk"
                with filename.open("rb") as f:
                    representation = pickle.load(f)

            Y[phase].append(int_label)
            Y_index[phase].append(len(X))
            X.append(representation)

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



def execute(argv):
  """Execute DGCNN."""
  del argv

  FLAGS = flags.FLAGS

  #
  # local flags
  #
  # CNN or GNN?
  flags_sequence_datasets = ['histogram_IR_O0',
                             'inst2vec',
                             'ir2vec',
                             'milepost',
                             'histogram',
                             'lbpeq',
                             'lbpif',
                             'prog2image']

  # CNN 1d or CNN 2d?
  flags_2d_sequence_datasets = ['inst2vec', 'prog2image']

  # Breakdown the runtime
  flags_times = {}

  #
  # Initialize the execution
  #

  # Measure the initial time
  initial_time = time.time()

  #
  # Load the dataset
  #
  print('\nLoading the dataset ...')
  start = time.time()

  if is_graph_dataset(FLAGS.dataset_directory):
    idx = FLAGS.dataset_directory.rfind('/')
    embeddings = FLAGS.dataset_directory[idx + 1:]

    graph_name = FLAGS.dataset_directory.replace('/{}'.format(embeddings), '')
    graph_name = graph_name[graph_name.rfind('/') + 1:]
    dataset_name = '{}_{}'.format(graph_name, embeddings)
  else:
    idx = FLAGS.dataset_directory.rfind('/')
    dataset_name = FLAGS.dataset_directory[idx + 1:]

  print(f"Dataset name: {dataset_name}")

  if dataset_name in flags_sequence_datasets:
    print("---------------")
    X_train, Y_train, X_val, Y_val, X_test, Y_test, FLAGS_labels = load_sequence_dataset(FLAGS.dataset_directory,
                                                                                         FLAGS.dataset_description)
  else:
    X, Y_train, Y_val, Y_test, FLAGS_labels = load_graph_dataset(FLAGS.dataset_directory,
                                                                 FLAGS.dataset_description)

  end = time.time()

  # Store load time
  flags_times['loading'] = end - start

  #
  # Prepare the dataset
  #
  print('\nPreparing the dataset ...')
  if dataset_name in flags_sequence_datasets:

    # 1D Model
    if dataset_name not in flags_2d_sequence_datasets:
      X_train = X_train.reshape(X_train.shape[0], X_train.shape[1], 1)
      X_val = X_val.reshape(X_val.shape[0], X_val.shape[1], 1)
      X_test = X_test.reshape(X_test.shape[0], X_test.shape[1], 1)
    else:
      # 2D Model
      if FLAGS.model != 'lstm':
        X_train = X_train.reshape(X_train.shape[0], X_train.shape[1], X_train.shape[2], 1)
        X_val = X_val.reshape(X_val.shape[0], X_val.shape[1], X_val.shape[2], 1)
        X_test = X_test.reshape(X_test.shape[0], X_test.shape[1], X_test.shape[2], 1)

  else:

    # Graph
    gen = PaddedGraphGenerator(graphs=X)

    train_gen = gen.flow(list(Y_train.index),
                         targets=Y_train.values,
                         batch_size=50,
                         symmetric_normalization=False)
    val_gen = gen.flow(list(Y_val.index),
                       targets=Y_val.values,
                       batch_size=1,
                       symmetric_normalization=False)
    test_gen = gen.flow(list(Y_test.index),
                        targets=Y_test.values,
                        batch_size=1,
                        symmetric_normalization=False)

  #
  # Create the model
  #
  if dataset_name in flags_sequence_datasets:
    # Sequence
    model_type = '1d' if dataset_name not in flags_2d_sequence_datasets else '2d'

    input_shape = X_train[0].shape
    embedding_dim =  X_train[0].shape[0] if model_type == '1d' else X_train[0].shape[1]

    if FLAGS.model == 'lstm':
      model = create_model_lstm(FLAGS_labels,
                                input_shape,
                                embedding_dim)
    elif FLAGS.model == 'dcnn':
      model = create_model_dcnn(FLAGS_labels,
                                input_shape,
                                model_type)
    else:
      logging.error('Model error.')
      sys.exit(1)

  else:
    # Graph

    if FLAGS.model == 'gcn':
      model = create_model_gcn(FLAGS_labels,
                               X)
    elif FLAGS.model == 'dgcnn':
      model = create_model_dgcnn(FLAGS_labels,
                                 X)
    else:
      logging.error('Model error.')
      sys.exit(1)

  model.compile(optimizer=Adam(learning_rate=0.0001),
                loss=categorical_crossentropy,
                metrics=['accuracy'])

  if FLAGS.print_model:
    print()
    model.summary()

  #
  # Create the output directory
  #
  os.makedirs(FLAGS.results_directory, exist_ok=True)

  #
  # Training
  #
  for round_ in range(FLAGS.rounds):
    print('\n\n**** ROUND:', round_)

    print('\nTraining ...')
    if FLAGS.verbose:
      print()

    start = time.time()

    es_callback = EarlyStopping(monitor="val_accuracy",
                                patience=FLAGS.patience,
                                restore_best_weights=True)

    if dataset_name in flags_sequence_datasets:
      history = model.fit(X_train,
                          Y_train,
                          validation_data=(X_val, Y_val),
                          epochs=FLAGS.epochs,
                          verbose=1 if FLAGS.verbose else 0,
                          shuffle=True,
                          callbacks=[es_callback])
    else:
      history = model.fit(train_gen,
                          validation_data=val_gen,
                          epochs=FLAGS.epochs,
                          verbose=1 if FLAGS.verbose else 0,
                          shuffle=True,
                          callbacks=[es_callback])

    end = time.time()

    # Store the training time
    flags_times['training'] = end - start

    #
    # Testing
    #
    print('\nTesting ...\n')
    start = time.time()

    if dataset_name in flags_sequence_datasets:
      test_metrics = model.evaluate(X_test, Y_test)
    else:
      test_metrics = model.evaluate(test_gen)

    end = time.time()

    # Store the testing time
    flags_times['evaluating'] = end - start

    # Print test metrics
    test_metrics_dict = {}
    for name, val in zip(model.metrics_names, test_metrics):
      print('{}: {:0.4f}'.format(name, val), flush=True)
      test_metrics_dict[name] = val

    #
    # Predicting
    #
    print('\nPredicting ...')
    start = time.time()

    if dataset_name in flags_sequence_datasets:
      predicted = model.predict(X_test)
    else:
      predicted = model.predict(test_gen)

    end = time.time()

    # Store the predicting time
    flags_times['predicting'] = end - start

    #
    # Statistic
    #
    print('\nCalculating statistics ...')
    pred_y = predicted.argmax(axis=-1)
    cm = confusion_matrix(Y_test.idxmax(axis=1), pred_y)
    cr = classification_report(Y_test.idxmax(axis=1), pred_y)

    if FLAGS.print_cm:
      print('\nConfusion matrix')
      print(cm)

    if FLAGS.print_cr:
      print('\nClassification report')
      print(cr)

    #
    # Finalize the execution
    #

    # Measure the final time
    final_time = time.time()

    flags_times['elapsed'] = final_time - initial_time

    # Create the output directory
    print('\nStoring the results ...')

    # Store the history
    fout = open('{}/history_{}.yaml'.format(FLAGS.results_directory, round_), 'w')
    yl.dump(history.history, fout)
    fout.close()

    # Store the test metrics
    fout = open('{}/test_metrics_{}.yaml'.format(FLAGS.results_directory, round_), 'w')
    yl.dump(test_metrics_dict, fout)
    fout.close()

    # Store the description of the dataset
    if dataset_name in flags_sequence_datasets:
      np.savez_compressed('{}/y_train_{}.npz'.format(FLAGS.results_directory, round_), values=Y_train)
      np.savez_compressed('{}/y_val_{}.npz'.format(FLAGS.results_directory, round_), values=Y_val)
      np.savez_compressed('{}/y_test_{}.npz'.format(FLAGS.results_directory, round_), values=Y_test)
    else:
      Y_train.to_pickle('{}/train_graphs_{}.pkl'.format(FLAGS.results_directory, round_))
      Y_val.to_pickle('{}/val_graphs_{}.pkl'.format(FLAGS.results_directory, round_))
      Y_test.to_pickle('{}/test_graphs_{}.pkl'.format(FLAGS.results_directory, round_))

    # Store the prediction
    np.savez_compressed('{}/predicted_{}'.format(FLAGS.results_directory, round_), values=predicted)

    # Store the confusion matrix
    np.savez_compressed('{}/confusion_matrix_{}'.format(FLAGS.results_directory, round_), values=cm)

    # Store the classification report
    fout = open('{}/classification_report_{}.pk'.format(FLAGS.results_directory, round_), 'wb')
    pk.dump(cr, fout)
    fout.close()

    # Store the elapsed time
    fout = open('{}/elapsed_time_{}.yaml'.format(FLAGS.results_directory, round_), 'w')
    yl.dump(flags_times, fout)
    fout.close()

    print('\nElapsed time:', flags_times['elapsed'], '(s)')

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

    sequence_representations_2d = ['inst2vec', 'prog2image']

    times = dict()

    # ------------ Load representation ------------

    initial_time = time.time()
    start = time.time()

    if representation in sequence_representations:
        X_train, Y_train, X_val, Y_val, X_test, \
        Y_test, labels = load_sequence_dataset(
            dataset_directory=root_dataset_dir,
            dataset_description=description_file
        )
        if representation not in sequence_representations_2d:
            X_train = X_train.reshape(X_train.shape[0], X_train.shape[1], 1)
            X_val = X_val.reshape(X_val.shape[0], X_val.shape[1], 1)
            X_test = X_test.reshape(X_test.shape[0], X_test.shape[1], 1)
        elif model != "lstm":
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
        X, Y_train, Y_val, Y_test, FLAGS_labels = load_graph_dataset(
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

    if representation in sequence_representations:
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
        if model_type == "gcn" or model_type == "dgcnn":
            model = create_model_gcn(labels, X)

    model.compile(optimizer=Adam(learning_rate=0.0001),
                  loss=categorical_crossentropy,
                  metrics=['accuracy'])

    times["model creation"] = time.time()-start

    if print_model:
        model.summary()

    for round in range(rounds):
        callbacks = []
        if patience > 0:
            es_callback = EarlyStopping(
                monitor="val_accuracy", patience=patience,
                restore_best_weights=True
            )
            callbacks.append(es_callback)

        if representation in sequence_representations:
            start = time.time()
            history = model.fit(
                X_train, Y_train, validation_data=(X_val, Y_val),
                epochs=epochs, verbose=False if silent else True,
                shuffle=True, callbacks=callbacks, batch_size=batch_size)
            times[f"train round {round}"] = time.time()-start

            start = time.time()
            test_metrics = model.evaluate(X_test, Y_test)
            times[f"test eval round {round}"] = time.time()-start

            start = time.time()
            predicted = model.predict(X_test)
            times[f"test predict round {round}"] = time.time()-start

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
            predicted = model.predict(X_test)
            times[f"test predict round {round}"] = time.time()-start


        pred_y = predicted.argmax(axis=-1)
        conf_matrix = confusion_matrix(Y_test.idxmax(axis=1), pred_y)
        class_report = classification_report(Y_test.idxmax(axis=1), pred_y)

        if stats:
            print(conf_matrix)
            print(class_report)


    times["total"] = time.time()-initial_time
    print(times)
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
