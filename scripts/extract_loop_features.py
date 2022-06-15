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
# Extract loop features from IR.
#

import os
import sys
import glob
import numpy as np
import yaml as yl
import subprocess

os.environ['LD_LIBRARY_PATH'] = '/home/anderson/Trabalhos/loop-extractor/build/lib'

from absl import app, flags, logging

def execute_cmd(cmdline):
    try:
        subprocess.run(cmdline,
                       shell=True,
                       check=True,
                       capture_output=False)
    except subprocess.CalledProcessError:
        return False
    return True

def build_loop_features(filename):
    """Find program representation."""
    keys = ['f01_loopWithWR',
            'f02_loopWRarray',
            'f03_loopWRarrayDisj',
            'f04_loopWRarraySame',
            'f05_isFlowDep',
            'f06_isAntiDep',
            'f07_isInputDep',
            'f08_isOutputDep',
            'f09_simpleLoop',
            'f10_complexLoop',
            'f11_loopRAW',
            'f12_loopWAR',
            'f13_loopWAW',
            'f14_loopRAR',
            'f15_indepLoopDep',
            'f16_loopSelfDep',
            'f17_numOfLoops']

    extract_features = 'opt -load=libLoopFeatures.so -loop-features -disable-output {} 2> features.yaml'.format(
        filename
    )
    remove_features_file = 'rm -rf features.yaml'
    
    ret = execute_cmd(extract_features)
    if not ret:
        execute_cmd(remove_features_file)
        return None

    fin = open('features.yaml', 'r')
    data = yl.load(fin, Loader=yl.FullLoader)
    fin.close()

    values = []
    for _, features in data.items():
        values.append([features[key] for key in keys])

    execute_cmd(remove_features_file)
    
    return [sum(x) for x in zip(*values)]


def extract(argv):
    """Extract a graph representation."""

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
    
    # Load data from all folders
    for folder in folders:
        # Create the output directory.
        outdir = os.path.join(folder.replace(last_folder,
                              '{}_loop_features'.format(last_folder)))
        os.makedirs(outdir, exist_ok=True)

        # Extract "loop features" from the file
        sources = glob.glob('{}/*.ll'.format(folder))

        for source in sources:
            try:
                features = build_loop_features(source)
            except Exception:
                logging.error('Exception {}.'.format(source))
                continue

            if features is None:
                logging.error('Error {}.'.format(source))
                continue
            
            filename = source.replace(folder, outdir)
            filename = filename[:-3]
            np.savez_compressed(filename, values=features)


# Execute
if __name__ == '__main__':
    # app
    flags.DEFINE_string('dataset_directory',
                        None,
                        'Dataset directory')
    flags.mark_flag_as_required('dataset_directory')

    app.run(extract)
