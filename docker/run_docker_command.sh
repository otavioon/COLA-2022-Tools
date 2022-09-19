#!/bin/bash

# Script utilizado para execução do playbook configure.yaml nas máquinas do inventorio.
# Este script não deve ser alterado

source ./vars.sh

$CONTAINER_CMD run --interactive --tty --rm \
  --gpus all \
  --env "HOME=$VOLUME_DIR" \
  --env "SHELL=/bin/bash" \
  --workdir $VOLUME_DIR \
  --volume $VOLUME_DIR:$VOLUME_DIR \
  $CONTAINER_IMAGE "$@"
