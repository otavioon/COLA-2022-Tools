EXTRACTOR_SCRIPT="$(realpath ../scripts/extract_graphs.py)"
ROOT_DIR="$(realpath ../datasets/obj)"
OUTPUT_DIR="$(realpath ../datasets/representations)"
DATASETS=('algo/poj' 'algo/codenet' 'loop/anghabench' 'optz/poj' 'optz/codenet' 'optz/anghabench')
#IR_LEVELS=('IR_O0' 'IR_O1' 'IR_O2' 'IR_O3' 'IR_Os' 'IR_Oz')
IR_LEVELS=('IR_O0')
GRAPH_TYPES=('cfg' 'cfg_compact' 'cdfg' 'cdfg_compact' 'cdfg_plus' 'programl')

for IR in ${IR_LEVELS[@]}
do
  for DATASET in ${DATASETS[@]}
  do
      for GTYPE in ${GRAPH_TYPES[@]}
      do
        python3 $EXTRACTOR_SCRIPT $ROOT_DIR/$DATASET $OUTPUT_DIR/$DATASET \
            --ir-dir $IR --graph-type $GTYPE
      done
  done
done
