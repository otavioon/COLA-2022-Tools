#!/bin/bash

source vars.sh
$CONTAINER_CMD build -t $CONTAINER_IMAGE -f Dockerfile.gpu . 
