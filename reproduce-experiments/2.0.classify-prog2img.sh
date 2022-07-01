ALG_DIR=../scripts
REPRESENTATION_DIR=../datasets/representations
RESULT_DIR=../results_rep
DATASETS=('algo/poj' 'algo/codenet' 'loop/anghabench' 'optz/anghabench' 'optz/poj' 'optz/codenet')
REPRESENTATION='prog2image'
DATASET_DIR=../datasets/src



mkdir ${RESULT_DIR}
for p in 'algo' 'optz' 'loop'
do
    mkdir ${RESULT_DIR}/$p
done

DATASET='loop/anghabench'

mkdir ${RESULT_DIR}/${DATASET}
mkdir ${RESULT_DIR}/${DATASET}_2C/${REPRESENTATION}

python3 $ALG_DIR/classify.py --dataset_directory=${REPRESENTATION_DIR}/${DATASET}/${REPRESENTATION} \
                --dataset_description=${DATASET_DIR}/${DATASET}/dataset_description_2C_small.yaml \
                --results_directory=${RESULT_DIR}/${DATASET}_2C/${REPRESENTATION} --rounds=1 --epochs=10

for DATASET in ${DATASETS[@]}
do
    mkdir ${RESULT_DIR}/${DATASET}
    mkdir ${RESULT_DIR}/${DATASET}/${REPRESENTATION}
    python3 $ALG_DIR/classify.py --dataset_directory=${REPRESENTATION_DIR}/${DATASET}/${REPRESENTATION} \
            --dataset_description=${DATASET_DIR}/${DATASET}/dataset_description_small.yaml \
            --results_directory=${RESULT_DIR}/${DATASET}/${REPRESENTATION} --rounds=1 --epochs=10
done