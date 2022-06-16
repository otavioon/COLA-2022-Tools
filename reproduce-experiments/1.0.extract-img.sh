if [ ! -d ../datasets/representations ]
then
    mkdir ../datasets/representations
fi

DATASETS=('poj' 'codenet')
BASE_DIR=../datasets/obj/algo
ALG_DIR=../scripts
OUTPUT_DIR=../datasets/representations/algo


echo "algo"
if [ ! -d $OUTPUT_DIR ]
then
    mkdir $OUTPUT_DIR
fi


for DATASET in ${DATASETS[@]}
do
    mkdir $OUTPUT_DIR/$DATASET
    mkdir $OUTPUT_DIR/$DATASET/PROG2IMAGE_IMG_one_size 
    mkdir $OUTPUT_DIR/$DATASET/PROG2IMAGE_NPZ_one_size
    echo "IMG and NPZ one size"
    python3 $ALG_DIR/create_image_and_npz.py -z=$OUTPUT_DIR/$DATASET/PROG2IMAGE_NPZ_one_size -i=$OUTPUT_DIR/$DATASET/PROG2IMAGE_IMG_one_size -p=$BASE_DIR/$DATASET -c=256 -l=-1 -e=ll -n=-1.0
done

DATASETS=('anghabench')
BASE_DIR=../datasets/obj/loop
ALG_DIR=../scripts
OUTPUT_DIR=../datasets/representations/loop

echo "loop"
if [ ! -d $OUTPUT_DIR ]
then
    mkdir $OUTPUT_DIR
fi


for DATASET in ${DATASETS[@]}
do
    mkdir $OUTPUT_DIR/$DATASET
    mkdir $OUTPUT_DIR/$DATASET/PROG2IMAGE_IMG_one_size 
    mkdir $OUTPUT_DIR/$DATASET/PROG2IMAGE_NPZ_one_size
    echo "IMG and NPZ one size"
    python3 $ALG_DIR/create_image_and_npz.py -z=$OUTPUT_DIR/$DATASET/PROG2IMAGE_NPZ_one_size -i=$OUTPUT_DIR/$DATASET/PROG2IMAGE_IMG_one_size -p=$BASE_DIR/$DATASET -c=256 -l=-1 -e=ll -n=-1.0
done

DATASETS=('poj' 'codenet' 'anghabench')
BASE_DIR=../datasets/obj/optz
ALG_DIR=../scripts
OUTPUT_DIR=../datasets/representations/optz

echo "optz"
if [ ! -d $OUTPUT_DIR ]
then
    mkdir $OUTPUT_DIR
fi


for DATASET in ${DATASETS[@]}
do
    mkdir $OUTPUT_DIR/$DATASET
    mkdir $OUTPUT_DIR/$DATASET/PROG2IMAGE_IMG_one_size 
    mkdir $OUTPUT_DIR/$DATASET/PROG2IMAGE_NPZ_one_size
    echo "IMG and NPZ one size"
    python3 $ALG_DIR/create_image_and_npz.py -z=$OUTPUT_DIR/$DATASET/PROG2IMAGE_NPZ_one_size -i=$OUTPUT_DIR/$DATASET/PROG2IMAGE_IMG_one_size -p=$BASE_DIR/$DATASET -c=256 -l=-1 -e=ll -n=-1.0
done