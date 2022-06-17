if [ ! -d ../datasets/obj ]
then
    mkdir ../datasets/obj
fi

DATASETS=('poj' 'codenet')
BASE_DIR=../datasets/src/algo
ALG_DIR=../scripts/
OUTPUT_DIR=../datasets/obj/algo

echo "algo"
if [ ! -d $OUTPUT_DIR ]
then
    mkdir $OUTPUT_DIR
fi

for DATASET in ${DATASETS[@]}
do
    python3 $ALG_DIR/extract_llvm_ir.py --dataset_directory=$BASE_DIR/$DATASET
    mv ${BASE_DIR}/${DATASET}_IR_O0 ${OUTPUT_DIR}/${DATASET}
done


DATASETS=('anghabench')
BASE_DIR=../datasets/src/loop
ALG_DIR=../scripts/
OUTPUT_DIR=../datasets/obj/loop

echo "loop"
if [ ! -d $OUTPUT_DIR ]
then
    mkdir $OUTPUT_DIR
fi

for DATASET in ${DATASETS[@]}
do
    python3 $ALG_DIR/extract_llvm_ir.py --dataset_directory=$BASE_DIR/$DATASET
    mv ${BASE_DIR}/${DATASET}_IR_O0 ${OUTPUT_DIR}/${DATASET}
done

DATASETS=('poj' 'codenet' 'anghabench')
BASE_DIR=../datasets/src/optz
ALG_DIR=../scripts/
OUTPUT_DIR=../datasets/obj/optz

echo "optz"
if [ ! -d $OUTPUT_DIR ]
then
    mkdir $OUTPUT_DIR
fi

for DATASET in ${DATASETS[@]}
do
    python3 $ALG_DIR/extract_llvm_ir.py --dataset_directory=$BASE_DIR/$DATASET
    mv ${BASE_DIR}/${DATASET}_IR_O0 ${OUTPUT_DIR}/${DATASET}
done
