SCRIPT_FILE="$(realpath ../../scripts/classify_2.py)"
REPRESENTATION_DIR=../../datasets/representations
DATASET_DIR=../../datasets/src
RESULT_DIR=../../results
DATASETS=('algo/poj' 'algo/codenet' 'loop/anghabench' 'optz/anghabench' 'optz/poj' 'optz/poj_s' 'optz/codenet')
REPRESENTATIONS=('ir2vec_IR_O0')

for DATASET in ${DATASETS[@]}
do
    for REPRESENTATION in ${REPRESENTATIONS[@]}
    do
        python3 $SCRIPT_FILE ${REPRESENTATION_DIR}/${DATASET}/${REPRESENTATION} \
                ${DATASET_DIR}/${DATASET}/dataset_description.yaml \
                ${RESULT_DIR}/${DATASET}/${REPRESENTATION} \
                --model dcnn \
                --representation ir2vec \
                --stats \
                --rounds 10
    done
done

###
DATASETS=('loop/anghabench')

for DATASET in ${DATASETS[@]}
do
    for REPRESENTATION in ${REPRESENTATIONS[@]}
    do
        python3 $SCRIPT_FILE ${REPRESENTATION_DIR}/${DATASET}/${REPRESENTATION} \
                ${DATASET_DIR}/${DATASET}/dataset_description_2C.yaml \
                ${RESULT_DIR}/${DATASET}_2C/${REPRESENTATION} \
                --model dcnn \
                --representation ir2vec \
                --stats \
                --rounds 10
    done
done
