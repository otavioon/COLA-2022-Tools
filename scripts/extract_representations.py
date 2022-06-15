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
# Extract all representations.
#

import os
import sys

os.environ['TF_CPP_MIN_LOG_LEVEL'] = '3'

import extract_stellar_raph as graph
import extract_histogram as histogram
import extract_inst2vec as inst2vec
import extract_ir2vec as ir2vec
import extract_milepost as milepost
import extract_llvm_ir as llvm_ir

from absl import app, flags, logging

def extract_representations(argv):
    """Extract a graph representation."""
    
    if not os.path.isabs(flags.FLAGS.dataset_directory):
        logging.error('Dataset directory should be an absolute path.')
        sys.exit(1)

    # Generate LLVM IR
    llvm_ir.extract(arg)
    
    # Graphs
    graph.extract(argv)

    # Ir2Vec
    ir2vec.extract(argv)

    # Inst2Vec
    inst2vec.extract(argv)

    # Histogram
    histogram.extract(argv)
    
    # Milepost
    milepost.extract(argv)
    
    
# Execute
if __name__ == '__main__':
    # app
    flags.DEFINE_string('dataset_directory',
                        None,
                        'Dataset directory')
    flags.mark_flag_as_required('dataset_directory')
    
    app.run(extract_representations)
