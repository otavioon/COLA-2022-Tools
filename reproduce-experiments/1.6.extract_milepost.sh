EXTRACTOR_SCRIPT="$(realpath ../scripts/extract_milepost.py)"
ROOT_DIR="$(realpath ../datasets/obj)"
OUTPUT_DIR="$(realpath ../datasets/representations)"
DATASETS=('algo/poj' 'algo/codenet' 'loop/anghabench' 'optz/poj' 'optz/codenet' 'optz/anghabench')
#IR_LEVELS=('IR_O0' 'IR_O1' 'IR_O2' 'IR_O3' 'IR_Os' 'IR_Oz')
IR_LEVELS=('IR_O0')

for IR in ${IR_LEVELS[@]}
do
  for DATASET in ${DATASETS[@]}
  do
      python3 $EXTRACTOR_SCRIPT $ROOT_DIR/$DATASET $OUTPUT_DIR/$DATASET --ir-dir $IR
  done
done
