EXTRACTOR_SCRIPT="../scripts/extract_llvm_ir.py"
ROOT_DIR="../datasets/src"
OUTPUT_DIR="../datasets/obj"
DATASETS=('algo/poj' 'algo/codenet' 'loop/anghabench' 'optz/poj' 'optz/codenet' 'optz/anghabench')
OPT_LEVELS=('O0' 'O1' 'O2' 'O3' 'Os' 'Oz')

for OPT in ${OPT_LEVELS[@]}
do
  for DATASET in ${DATASETS[@]}
  do
      python3 $EXTRACTOR_SCRIPT $ROOT_DIR/$DATASET $OUTPUT_DIR/$DATASET --level $OPT
  done
done
