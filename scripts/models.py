from stellargraph.mapper import PaddedGraphGenerator
from stellargraph.layer import DeepGraphCNN

from tensorflow.keras import Model
from tensorflow.keras.models import Sequential
from tensorflow.keras.layers import Dense, Conv2D, Conv1D, MaxPool2D, \
    MaxPool1D, Dropout, Flatten


def create_model_lstm(labels, input_shape: tuple, embedding_dim: int):
  dense_layer_size = 32
  inp = Input(shape=input_shape, dtype="float32", name="code_in")
  x = LSTM(embedding_dim, implementation=1, return_sequences=True, name="lstm_1")(inp)
  x = LSTM(embedding_dim, implementation=1, name="lstm_2")(x)

  # Heuristic model: outputs 1-of-num_classes prediction
  x = BatchNormalization()(x)
  x = Dense(dense_layer_size, activation="relu")(x)
  outputs = Dense(labels, activation="softmax")(x)

  return Model(inputs=inp, outputs=outputs)


def create_model_dcnn(labels, input_shape: tuple, model_type: str = '1d'):
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
      raise ValueError(f"Invalid model_type: {model_type}")

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
  # Create the model and prepare it for training by specifying the loss
  # and optimization algorithm
  #
  model = Model(inputs=x_inp, outputs=outputs)

  return model
