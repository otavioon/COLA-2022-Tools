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

from absl import app, flags, logging

def merge_features(source1, source2):
    try:
        data1 = np.load(source1)
        data2 = np.load(source2)
        return np.concatenate((data1['values'], data2['values']))
    except Exception:
        return None
    
def merge(argv):
    """Extract a graph representation."""

    FLAGS = flags.FLAGS

    # Verify datset directory.
    if not os.path.isdir(FLAGS.dataset_directory1):
        logging.error('Dataset directory 1 {} does not exist.'.format(
            FLAGS.dataset_directory1)
        )
        sys.exit(1)

    # Verify datset directory.
    if not os.path.isdir(FLAGS.dataset_directory2):
        logging.error('Dataset directory 2 {} does not exist.'.format(
            FLAGS.dataset_directory2)
        )
        sys.exit(1)
        
    folders = [
                os.path.join(FLAGS.dataset_directory1, subdir)
                for subdir in os.listdir(FLAGS.dataset_directory1)
                if os.path.isdir(os.path.join(FLAGS.dataset_directory1, subdir))
              ]
    
    # Load data from all folders
    for folder in folders:

        idx = folder.rfind('/')
        last_folder = folder[idx+1:]
    
        # Create the output directory.
        outdir = os.path.join(FLAGS.output_directory, last_folder)
        os.makedirs(outdir, exist_ok=True)

        # Extract "loop features" from the file
        sources = glob.glob('{}/*.npz'.format(folder))

        for source1 in sources:
            source2 = source1.replace(FLAGS.dataset_directory1, FLAGS.dataset_directory2)

            idx = source1.rfind('/')
            source_name = source1[idx+1:]
            
            features = merge_features(source1, source2)

            if features is None:
                logging.error('Error {}.'.format(source_name))
                continue
            
            filename = source1.replace(folder, outdir)
            filename = filename[:-4]
            np.savez_compressed(filename, values=features)


# Execute
if __name__ == '__main__':
    # app
    flags.DEFINE_string('dataset_directory1',
                        None,
                        'Dataset directory1')
    flags.mark_flag_as_required('dataset_directory1')
    flags.DEFINE_string('dataset_directory2',
                        None,
                        'Dataset directory2')
    flags.DEFINE_string('output_directory',
                        'new_feature',
                        'Output directory')
    
    flags.mark_flag_as_required('dataset_directory1')
    flags.mark_flag_as_required('dataset_directory2')

    app.run(merge)
