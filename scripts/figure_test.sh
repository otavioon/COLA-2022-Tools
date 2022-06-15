#! /bin/bash

# PLACEHOLDER should be an absolute path
TOP_DIR=PLACEHOLDER

PROBLEM='algo'
DATASET='poj_test'
DATASET_DIR=${TOP_DIR}/problems/${PROBLEM}/${DATASET}
FIG_NUMBER='test'

./extract_representations.py \
    --dataset_directory ${DATASET_DIR}

./run_classify.sh \
    ${DATASET_DIR} \
    ${DATASET} \
    ${DATASET_DIR}/dataset_description.yaml

./plot_accuracy.py \
    --results_directory ${DATASET_DIR} \
    --dataset ${DATASET} \
    --filename ${DATASET_DIR}/figure_${FIG_NUMBER}.pdf
