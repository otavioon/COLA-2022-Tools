#! /usr/bin/env python3

"""
Copyright 2021 Anderson Faustino da Silva.

Licensed under the Apache License, Version 2.0 (the "License");
you may not use this file except in compliance with the License.
You may obtain a copy of the License at

http://www.apache.org/licenses/LICENSE-2.0

Unless required by applicable law or agreed to in writing, software
distributed under the License is distributed on an "AS IS" BASIS,
WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
See the License for the specific language governing permissions and
limitations under the License.
"""

#
# Compile a program and extract the number of LLVM instructions.
#

import os
import sys
import glob
import subprocess

from absl import app, flags, logging

from yacos.essential import IO
from yacos.essential import Sequence
from yacos.info import compy as R
from yacos.info.compy.extractors import LLVMDriver

flags.DEFINE_enum('level',
                  'O0',
                  [
                      'O0',
                      'O1',
                      'O2',
                      'O3',
                      'Os',
                      'Oz'
                  ],
                  'Compiler optimization level')

def emit_llvm(filename, outdir, message=''):
    """Generate bitcode."""
    idx = filename.rfind('/')
    new_filename = filename[idx+1:]
    if filename.endswith('.c'):
        compiler = 'clang'
        new_filename = '{}/{}.ll'.format(outdir, new_filename[:-2])
    elif filename.endswith('.cpp'):
        compiler = 'clang++'
        new_filename = '{}/{}.ll'.format(outdir, new_filename[:-4])
    else:
        return None

    cmdline = '{} -S -c -Xclang -disable-O0-optnone -w -emit-llvm {} -o {}'.format(compiler,
                                                                                   filename,
                                                                                   new_filename)

    try:
        subprocess.run(cmdline,
                       shell=True,
                       check=True,
                       capture_output=False)
    except subprocess.CalledProcessError:
        if message:
            logging.error(message)
        return None # sys.exit(1)

    return new_filename


def optimize(filename, sequence, message=''):
    """Optimize."""
    cmdline = 'opt {0} {1} -o {1}'.format(Sequence.name_pass_to_string(sequence),
                                          filename)

    try:
        subprocess.run(cmdline,
                       shell=True,
                       check=True,
                       capture_output=False)
    except subprocess.CalledProcessError:
        if message:
            logging.error(message)
        return None # sys.exit(1)

def extract(argv):
    """Execute."""
    del argv

    FLAGS = flags.FLAGS

    # Verify datset directory.
    if not os.path.isdir(FLAGS.dataset_directory):
        logging.error('Dataset directory {} does not exist.'.format(
            FLAGS.dataset_directory)
        )
        sys.exit(1)

    folders = [
                os.path.join(FLAGS.dataset_directory, subdir)
                for subdir in os.listdir(FLAGS.dataset_directory)
                if os.path.isdir(os.path.join(FLAGS.dataset_directory, subdir))
              ]

    idx = FLAGS.dataset_directory.rfind('/')
    last_folder = FLAGS.dataset_directory[idx+1:]

    # Generate LLVM IR
    for folder in folders:

        # Create the output directory.
        outdir = os.path.join(folder.replace(last_folder,
                                             '{}_IR_{}'.format(last_folder, FLAGS.level)))
        os.makedirs(outdir, exist_ok=True)

        sources = glob.glob('{}/*'.format(folder))
        folder_name = folder.replace('{}/'.format(FLAGS.dataset_directory), '')

        for source in sources:
            print(f"Emitting LLVM for {source}... ", end="")
            filename = emit_llvm(source, outdir)
            optimize(filename, ['-{}'.format(FLAGS.level)])
            print(f"optimized with {FLAGS.level} and saved to {filename}")

# Execute
if __name__ == '__main__':
    # app
    flags.DEFINE_string('dataset_directory',
                        None,
                        'Dataset directory')

    flags.mark_flag_as_required('dataset_directory')

    app.run(extract)
