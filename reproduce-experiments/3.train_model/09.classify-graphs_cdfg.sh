SCRIPT_FILE="$(realpath ../../scripts/classify_2.py)"
REPRESENTATION_DIR=../../datasets/representations
DATASET_DIR=../../datasets/src
RESULT_DIR=../../results
DATASETS=('optz/codenet')
REPRESENTATIONS=('ir2vec')
IRDIR="IR_O0"
REPTYPE="cdfg"
MODEL="dgcnn"

for DATASET in ${DATASETS[@]}
do
    for REPRESENTATION in ${REPRESENTATIONS[@]}
    do
        python3 $SCRIPT_FILE ${REPRESENTATION_DIR}/${DATASET}/${REPTYPE}_${REPRESENTATION}_${IRDIR} \
                ${DATASET_DIR}/${DATASET}/dataset_description.yaml \
                ${RESULT_DIR}/${DATASET}/${REPTYPE}_${REPRESENTATION}_${IRDIR} \
                --model $MODEL \
                --representation $REPRESENTATION \
                --stats \
                --rounds 10 \
                --batch_size 1
    done
done

###
# DATASETS=('loop/anghabench')
#
# for DATASET in ${DATASETS[@]}
# do
#     for REPRESENTATION in ${REPRESENTATIONS[@]}
#     do
#         python3 $SCRIPT_FILE ${REPRESENTATION_DIR}/${DATASET}/${REPTYPE}_${REPRESENTATION}_${IRDIR} \
#                 ${DATASET_DIR}/${DATASET}/dataset_description_2C.yaml \
#                 ${RESULT_DIR}/${DATASET}_2C/${REPTYPE}_${REPRESENTATION}_${IRDIR} \
#                 --model $MODEL \
#                 --representation $REPRESENTATION \
#                 --stats \
#                 --rounds 10
#     done
# done
