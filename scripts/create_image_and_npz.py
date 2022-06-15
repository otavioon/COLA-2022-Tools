import argparse, os, yaml, glob, math, sys
import numpy as np
from PIL import Image
from yacos.info.image import bit2vec



def bin2mat(binary_name,output_image,output_file,columns,desired_lines,np_missing_values=-1.0,img_miising_values=128):
	'''
		recieves a binary file, converts it in a matrix 
		where each position is a bit and save it as image 
		and npz file
	
		binary_name: str
			the binary file name to be converted
		output_image: str
			the image file name that will be created 
			(the image will be in shades of grey)
		output_file: str
			the npz file that will be created
		columns: int
			the number of columns in the matrix
		desired_lines: int
			the number of DESIRED lines in the matrix
			if this number is lower than the needed to
			put all bits in the matrix, it will be ignored
		np_missing_values: real
			number that the missing positions of the
			matrix will be filled with to store in npz
		img_miising_values: int
			number that the missing positions of the
			matrix will be filled with to store in the image
	'''
	vector = bit2vec.get_array(binary_name)
	b2v = bit2vec(vector)
	b2v.columns = columns
	b2v.desired_lines = desired_lines
	npz_matrix = b2v.create_npz(output_file,fill_np=np_missing_values)
	img_matrix = b2v.create_img(output_image,fill_img=img_miising_values)

	return npz_matrix,img_matrix

parser = argparse.ArgumentParser()
parser.add_argument('-i','--image-directory', dest='image_directory', help='directory to store images')
parser.add_argument('-z','--npz-direcory',dest='npz_directory', help='directory to store npz')
parser.add_argument('-p','--process-directory', dest='process_directory')
parser.add_argument('-c','--columns',dest='columns', type=int, default=256, help='number of bits for each column in matrix')
parser.add_argument('-l','--lines', dest='lines', type=int, default=0, help='number of lines (-1 for number of lines equal the greater size;'+
																			'0 for ideal size for image; any positive interger)')
parser.add_argument('-y','--yaml', dest='yaml_file', default=None, help='Yaml file name with programs (no file will do for all directory')
parser.add_argument('-s','--max-size', dest='max_size', default=None, help='Maximun binary size (in bytes) to create files')
parser.add_argument('-e', '--ext', dest='process_ext', default='ll', help='extension of files to be precessed')
parser.add_argument('-n', '--npz-fill', dest='npz_fill', default=-1.0, help='value to fill npz matrix')
parser.add_argument('-m', '--img-fill', dest='img_fill', default=128, help='value to fill image matrix')
args = parser.parse_args()

image_directory = args.image_directory
npz_directory = args.npz_directory
process_directory = args.process_directory
columns = args.columns 
lines = args.lines
yaml_file = args.yaml_file
max_size = args.max_size
process_ext = args.process_ext
npz_fill = args.npz_fill
img_fill = args.img_fill

if not os.path.exists(image_directory):
	sys.exit("image directory does not exists")
if not os.path.exists(npz_directory):
	sys.exit("npz directory does not exists")
if not os.path.exists(process_directory):
	sys.exit("process directory does not exists")
files = []

if yaml_file==None:
	files_with_ext = glob.glob('{0}/*/*.{1}'.format(process_directory,process_ext))
	files = []
	for fe in files_with_ext:
		fne, ext = os.path.splitext(fe)
		files.append(fne)
else:
	f=open(yaml_file)
	yaml_data=yaml.load(f)
	f.close()
	for d in yaml_data:
		programs = yaml_data[d]
		for p in programs:
			obj_p = p
			program_path=os.path.join(process_directory,str(d),obj_p)
			files.append(program_path)

if max_size != None:
	max_size=int(max_size)
	new_files = []
	for f in files:
		name_with_ext = f+'.'+process_ext
		if os.path.getsize(name_with_ext) <= max_size:
			new_files.append(f)
	files = new_files

sizes=[]
if lines == -1:
	for prog in files:
		prog_complete_name=prog+'.'+process_ext
		size_obj = os.path.getsize(prog_complete_name)
		sizes.append((size_obj,prog_complete_name))
	greater=max(sizes)[0]
	lines=math.ceil((greater*8)/columns)

print(files)
print(lines)

tuplas = []
for f in files:
	binary_file = f+'.'+process_ext
	if os.path.exists(binary_file):
		print(binary_file)
		directory, name = os.path.split(f)
		root_dir, collection_dir = os.path.split(directory)
		img_dir = os.path.join(image_directory,collection_dir)
		img_file = os.path.join(img_dir,name)
		img_file = img_file+'.png'

		npz_dir = os.path.join(npz_directory, collection_dir)
		npz_file = os.path.join(npz_dir, name)
		npz_file = npz_file+'.npz'

		if not os.path.exists(img_dir):
			os.system('mkdir {0}'.format(img_dir))
		if not os.path.exists(npz_dir):
			os.system('mkdir {0}'.format(npz_dir))
		bin2mat(binary_file,img_file,npz_file,columns,lines,np_missing_values=npz_fill,img_miising_values=img_fill)
		
	else:
		print('====================================')
		print('>>> file {0} not found <<<'.format(binary_file))
		print('====================================')
