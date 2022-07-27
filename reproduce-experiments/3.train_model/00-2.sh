SCRIPT_FILE="$(realpath ../../scripts/classify_2.py)"
REPRESENTATION_DIR=../../datasets/representations
DATASET_DIR=../../datasets/src
RESULT_DIR=../../results
DATASETS=('optz/codenet')
REPRESENTATION='prog2image'

# for DATASET in ${DATASETS[@]}
# do
#   python3 $SCRIPT_FILE ${REPRESENTATION_DIR}/${DATASET}/${REPRESENTATION} \
#           ${DATASET_DIR}/${DATASET}/dataset_description.yaml \
#           ${RESULT_DIR}/${DATASET}/${REPRESENTATION} \
#           --model dcnn \
#           --representation prog2image \
#           --stats \
#           --rounds 10 \
#           --batch_size 32 \
#           --dtype int8
# done

DATASETS=('loop/anghabench')

for DATASET in ${DATASETS[@]}
do
  python3 $SCRIPT_FILE ${REPRESENTATION_DIR}/${DATASET}/${REPRESENTATION} \
          ${DATASET_DIR}/${DATASET}/dataset_description_2C.yaml \
          ${RESULT_DIR}/${DATASET}_2C/${REPRESENTATION} \
          --model dcnn \
          --representation prog2image \
          --stats \
          --rounds 10 \
          --batch_size 16 \
          --dtype int8
done
