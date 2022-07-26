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
import yaml as yl
import pickle as pk
import numpy as np
import pandas as pd
import subprocess
import datetime

os.environ['TF_CPP_MIN_LOG_LEVEL'] = '3'

from absl import app, flags, logging
import tqdm


from sklearn import model_selection
from sklearn.metrics import confusion_matrix, classification_report

from stellargraph.mapper import PaddedGraphGenerator
from stellargraph.layer import DeepGraphCNN
from stellargraph import StellarDiGraph

from tensorflow.keras import Model
from tensorflow.keras.models import Sequential
from tensorflow.keras.optimizers import Adam
from tensorflow.keras.layers import Dense, Conv2D, Conv1D, MaxPool2D, MaxPool1D, Dropout, Flatten
from tensorflow.keras.losses import categorical_crossentropy
from tensorflow.keras.callbacks import EarlyStopping


#
# Functions
#
def create_model_lstm(labels, input_shape, embedding_dim):
  dense_layer_size = 32
  inp = Input(shape=input_shape, dtype="float32", name="code_in")
  x = LSTM(embedding_dim, implementation=1, return_sequences=True, name="lstm_1")(inp)
  x = LSTM(embedding_dim, implementation=1, name="lstm_2")(x)

  # Heuristic model: outputs 1-of-num_classes prediction
  x = BatchNormalization()(x)
  x = Dense(dense_layer_size, activation="relu")(x)
  outputs = Dense(labels, activation="softmax")(x)

  return Model(inputs=inp, outputs=outputs)

def create_model_dcnn(labels, input_shape, model_type='1d'):
  """Create the model."""
  layer_sizes = [3]
  model = Sequential()

  if model_type == '1d':
    # padronizado com o GNN
    model.add(Conv1D(filters=16,
                     kernel_size=sum(layer_sizes),
                     strides=sum(layer_sizes),
                     activation="relu",
                     padding='same',
                     input_shape=input_shape))
    model.add(MaxPool1D(pool_size=2,
                        strides=2))
    model.add(Conv1D(filters=32,
                     kernel_size=5,
                     strides=1,
                     activation="relu"))
    model.add(Flatten())
    model.add(Dense(units=128,
                    activation="relu"))
    model.add(Dropout(rate=0.5))
    model.add(Dense(units=labels,
                    activation = 'softmax'))
  elif model_type == '2d':
    # modelo 1
    # padronizado com o GNN
    model.add(Conv2D(filters=16,
                     kernel_size=(sum(layer_sizes), sum(layer_sizes)),
                     strides=(sum(layer_sizes), sum(layer_sizes)),
                     activation="relu",
                     padding='same',
                     input_shape=input_shape))
    model.add(MaxPool2D(pool_size=(2, 2),
                        strides=(2, 2)))
    model.add(Conv2D(filters=32,
                     kernel_size=(5, 5),
                     strides=(1, 1),
                     activation="relu"))
    model.add(Flatten())
    model.add(Dense(units=128,
                    activation="relu"))
    model.add(Dropout(rate=0.5))
    model.add(Dense(units=labels,
                    activation = 'softmax'))
  else:
    print('Model type error')
    sys.exit(1)

  return model

def create_model_gcn(labels, graphs):
  generator = PaddedGraphGenerator(graphs=graphs)

  gc_model = GCNSupervisedGraphClassification(
    layer_sizes=[64, 64],
    activations=["relu", "relu"],
    generator=generator,
    dropout=0.5,
  )
  x_inp, x_out = gc_model.in_out_tensors()
  predictions = Dense(units=32, activation="relu")(x_out)
  predictions = Dense(units=16, activation="relu")(predictions)
  predictions = Dense(units=labels, activation="softmax")(predictions)

  # Let's create the Keras model and prepare it for training
  model = Model(inputs=x_inp, outputs=predictions)
  return model

def create_model_dgcnn(labels, graphs):
  generator = PaddedGraphGenerator(graphs=graphs)

  k = 35  # the number of rows for the output tensor
  layer_sizes = [32, 32, 32, 1]

  dgcnn_model = DeepGraphCNN(
    layer_sizes=layer_sizes,
    activations=["tanh", "tanh", "tanh", "tanh"],
    k=k,
    bias=False,
    generator=generator,
  )
  x_inp, x_out = dgcnn_model.in_out_tensors()

  # Add the convolutional, max pooling, and dense layers
  x_out = Conv1D(filters=16,
                 kernel_size=sum(layer_sizes),
                 strides=sum(layer_sizes),
                 activation="relu")(x_out)
  x_out = MaxPool1D(pool_size=2,
                    strides=2)(x_out)
  x_out = Conv1D(filters=32,
                 kernel_size=5,
                 strides=1,
                 activation="relu")(x_out)
  x_out = Flatten()(x_out)
  x_out = Dense(units=128,
                activation="relu")(x_out)
  x_out = Dropout(rate=0.5)(x_out)
  outputs = Dense(units=labels,
                  activation="softmax")(x_out)

  #
  # Create the model and prepare it for training by specifying the loss and optimization algorithm
  #
  model = Model(inputs=x_inp, outputs=outputs)

  return model

def load_sequence_dataset(dataset_directory,
                          dataset_description):

  fin = open(dataset_description, 'r')
  description_dataset = yl.load(fin, Loader=yl.FullLoader)
  fin.close()

  idx = dataset_directory.rfind('/')
  dataset_name = dataset_directory[idx + 1:]

  X = {'training': [], 'validation': [], 'test': []}
  Y = {'training': [], 'validation': [], 'test': []}

  labels = []
  errors = []

  for phase, phase_data in description_dataset.items():

    vals = []

    for label, samples in tqdm.tqdm(phase_data.items(), desc=f"Loading {phase} data..."):

      int_label = int(label)

      labels.append(int_label)

      data_directory = os.path.join(dataset_directory, label)

      for sample in samples:

        try:
          # print(f"Loading from {data_directory}/{sample}.npz")
          representation = np.load('{}/{}.npz'.format(data_directory, sample), allow_pickle=True)
        except Exception as e:
          # print('Erro load', data_directory, sample, flush=True)
          # raise
          errors.append(sample)
          continue

        representation = representation['values']

        Y[phase].append(int_label)
        vals.append(representation)

    X[phase] = np.array(vals)

  if len(errors) != 0:
      print(f"There are {len(errors)} errored files!")

  labels = list(dict.fromkeys(labels))

  X_train = X['training']
  X_val = X['validation']
  X_test = X['test']

  Y_train = Y['training']
  Y_val = Y['validation']
  Y_test = Y['test']

  del X, Y

  Y_train = pd.get_dummies(Y_train)
  Y_val = pd.get_dummies(Y_val)
  Y_test = pd.get_dummies(Y_test)

  return X_train, Y_train, X_val, Y_val, X_test, Y_test, len(labels)

def load_graph_dataset(dataset_directory,
                       dataset_description):

  fin = open(dataset_description, 'r')
  description_dataset = yl.load(fin, Loader=yl.FullLoader)
  fin.close()

  X = []
  Y = {'training': [], 'validation': [], 'test': []}
  Y_index = {'training': [], 'validation': [], 'test': []}

  labels = []

  for phase, phase_data in description_dataset.items():

    for label, samples in phase_data.items():

      int_label = int(label)

      labels.append(int_label)

      data_directory = os.path.join(dataset_directory, label)

      for sample in samples:

        try:
          filename = '{}/{}.pk'.format(data_directory, sample)
          print(f"Loading from {filename}")
          fin = open(filename, 'rb')
          representation = pk.load(fin)
          fin.close()
        except:
          print('Erro load', data_directory, sample, flush=True)
          raise

        Y[phase].append(int_label)
        Y_index[phase].append(len(X))
        X.append(representation)

  labels = list(dict.fromkeys(labels))

  Y_train = pd.Series(Y['training'], index=Y_index['training'], name='label', dtype="category")
  Y_val = pd.Series(Y['validation'], index=Y_index['validation'], name='label', dtype="category")
  Y_test = pd.Series(Y['test'], index=Y_index['test'], name='label', dtype="category")

  Y_train = pd.get_dummies(Y_train)
  Y_val = pd.get_dummies(Y_val)
  Y_test = pd.get_dummies(Y_test)

  return X, Y_train, Y_val, Y_test, len(labels)

def is_graph_dataset(dataset_directory):
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

  if dataset_name.split("_")[0] in flags_sequence_datasets:
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
  if dataset_name.split("_")[0] in flags_sequence_datasets:

    # 1D Model
    if dataset_name.split("_")[0] not in flags_2d_sequence_datasets:
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
  if dataset_name.split("_")[0] in flags_sequence_datasets:
    # Sequence
    model_type = '1d' if dataset_name.split("_")[0] not in flags_2d_sequence_datasets else '2d'

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

    if dataset_name.split("_")[0] in flags_sequence_datasets:
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

    if dataset_name.split("_")[0] in flags_sequence_datasets:
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

    if dataset_name.split("_")[0] in flags_sequence_datasets:
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
    if dataset_name.split("_")[0] in flags_sequence_datasets:
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


# Execute
if __name__ == '__main__':
    # app
    flags.DEFINE_string('dataset_directory',
                        None,
                        'Dataset directory')
    flags.DEFINE_string('dataset_description',
                        None,
                        'Dataset description filename (yaml)')

    flags.DEFINE_string('results_directory',
                        None,
                        'Results directory')

    flags.DEFINE_enum('model',
                      'dcnn',
                      [
                          'lstm',
                          'dcnn',
                          'gcn',
                          'dgcnn'
                      ],
                      'The model')
    flags.DEFINE_integer('patience',
                         20,
                        'Number of epochs without improvement')
    flags.DEFINE_integer('epochs',
                         200,
                        'Number of epochs')
    flags.DEFINE_integer('rounds',
                         10,
                         'Rounts')
    flags.DEFINE_boolean('verbose',
                         True,
                        'Verbose the training phase')

    flags.DEFINE_boolean('print_model',
                         False,
                         'Print the model')

    flags.DEFINE_boolean('print_cm',
                         False,
                         'Print the confustion matrix')
    flags.DEFINE_boolean('print_cr',
                         False,
                         'Print the classification report')

    flags.mark_flag_as_required('dataset_directory')
    flags.mark_flag_as_required('dataset_description')
    flags.mark_flag_as_required('results_directory')

    app.run(execute)
