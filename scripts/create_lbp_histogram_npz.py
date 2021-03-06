import argparse, os, yaml, glob, sys
from tqdm import tqdm
from yacos.info.image import *
from tqdm.contrib.concurrent import thread_map

def save_lbp_histogram_npz(binary_file,npz_file,columns,lines,npz_fill=0):
	array = bit2vec.get_array(binary_file)
	b2v = bit2vec(array,columns=columns,desired_lines=lines)
	b2v_histogram_lbp = b2v.create_normalized_LBP_histogram(output_file=npz_file,fill_value=npz_fill)
	return b2v_histogram_lbp


parser = argparse.ArgumentParser()
parser.add_argument('-z','--npz-direcory',dest='npz_directory', help='directory to store npz')
parser.add_argument('-p','--process-directory', dest='process_directory', help='directory containing the input binaries')
parser.add_argument('-c','--columns',dest='columns', type=int, default=256, help='number of bits for each column in matrix')
parser.add_argument('-l','--lines', dest='lines', type=int, default=0, help='number of lines in folded npz')
parser.add_argument('-y','--yaml', dest='yaml_file', default=None, help='Yaml file name with programs (no file will do for all directories inside process-directory)')
parser.add_argument('-s','--max-size', dest='max_size', default=None, help='Maximun binary size (in bytes) to create files')
parser.add_argument('-e', '--ext', dest='process_ext', default='ll', help='extension of files to be precessed')
parser.add_argument('-n', '--npz-fill', dest='npz_fill', default=-1.0, help='value to fill matrix')
parser.add_argument("--workers", type=int, default=None, help="Number of concurrent processes")
args = parser.parse_args()

npz_directory = args.npz_directory
process_directory = args.process_directory
columns = args.columns
lines = args.lines
yaml_file = args.yaml_file
max_size = args.max_size
process_ext = args.process_ext
npz_fill = args.npz_fill

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
			obj_p, obj_ext = os.path.splitext(p)
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

def process(f: str):
	try:
		binary_file = f+'.'+process_ext
		#print(binary_file)
		directory, name = os.path.split(f)
		root_dir, collection_dir = os.path.split(directory)

		npz_dir = os.path.join(npz_directory, collection_dir)
		npz_file = os.path.join(npz_dir, name)
		npz_file = npz_file+'.npz'

		if not os.path.exists(npz_dir):
			os.system('mkdir {0}'.format(npz_dir))

		npz_lbp_histogram = save_lbp_histogram_npz(binary_file,npz_file,columns,lines,npz_fill=npz_fill)
	except Exception as e:
		print(f"Error: {e.__class__.__name__}: {e}")

tuplas = []
thread_map(process, files, desc="Extracting lbp histograms...", max_workers=args.workers)
# for f in tqdm(files):
# 	binary_file = f+'.'+process_ext
# 	#print(binary_file)
# 	if os.path.exists(binary_file):
# 		directory, name = os.path.split(f)
# 		root_dir, collection_dir = os.path.split(directory)
#
# 		npz_dir = os.path.join(npz_directory, collection_dir)
# 		npz_file = os.path.join(npz_dir, name)
# 		npz_file = npz_file+'.npz'
#
# 		if not os.path.exists(npz_dir):
# 			os.system('mkdir {0}'.format(npz_dir))
#
# 		npz_lbp_histogram = save_lbp_histogram_npz(binary_file,npz_file,columns,lines,npz_fill=npz_fill)
# 	else:
# 		print('====================================')
# 		print('>>> file {0} not found <<<'.format(binary_file))
# 		print('====================================')
