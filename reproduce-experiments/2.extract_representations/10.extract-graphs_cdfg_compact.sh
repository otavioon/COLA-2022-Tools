EXTRACTOR_SCRIPT="$(realpath ../../scripts/extract_graphs.py)"
ROOT_DIR="$(realpath ../../datasets/obj)"
OUTPUT_DIR="$(realpath ../../datasets/representations)"
DATASETS=('algo/poj' 'algo/codenet' 'loop/anghabench' 'optz/anghabench' 'optz/poj' 'optz/poj_s' 'optz/codenet')
# DATASETS=('loop/anghabench')
IR_LEVELS=('IR_O0')
GRAPH_TYPES=('cdfg_compact')
#GRAPH_TYPES=('cfg' 'cfg_compact' 'cdfg' 'cdfg_compact' 'cdfg_plus' 'programl')


for GTYPE in ${GRAPH_TYPES[@]}
do
  for IR in ${IR_LEVELS[@]}
  do
      for DATASET in ${DATASETS[@]}
      do
        python3 $EXTRACTOR_SCRIPT $ROOT_DIR/$DATASET $OUTPUT_DIR/$DATASET \
            --ir-dir $IR --graph-type $GTYPE
      done
  done
done
