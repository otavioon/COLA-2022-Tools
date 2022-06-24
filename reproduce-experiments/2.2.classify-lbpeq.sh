ALG_DIR=../scripts
REPRESENTATION_DIR=../datasets/representations
RESULT_DIR=../results_rep
DATASETS=('algo/poj' 'algo/codenet' 'loop/anghabench' 'optz/anghabench' 'optz/poj' 'optz/codenet')
REPRESENTATIONS=('lbpeq')
DATASET_DIR=../datasets/src



mkdir ${RESULT_DIR}
for p in 'algo' 'optz' 'loop'
do
    mkdir ${RESULT_DIR}/$p
done

for DATASET in ${DATASETS[@]}
do
    for REPRESENTATION in ${REPRESENTATIONS[@]}
    do
        mkdir ${RESULT_DIR}/${DATASET}
        mkdir ${RESULT_DIR}/${DATASET}/${REPRESENTATION}
        python3 $ALG_DIR/classify.py --dataset_directory=${REPRESENTATION_DIR}/${DATASET}/${REPRESENTATION} \
                --dataset_description=${DATASET_DIR}/${DATASET}/dataset_description.yaml \
                --results_directory=${RESULT_DIR}/${DATASET}/${REPRESENTATION}
    done
done