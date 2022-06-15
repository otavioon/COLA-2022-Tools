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
# Plot the accuracies.
#

import sys
import numpy as np
import yaml as yl
import glob as gb
import matplotlib.pyplot as plt

from absl import app, flags, logging


def plot(argv):
    """Plot a bar graph with standard deviation."""
    
    del argv
    
    FLAGS = flags.FLAGS

    #
    # Create the dataset
    #
    height = []
    bars = []
    std = []

    for rep in ['cfg', 'cfg_compact', 'cdfg', 'cdfg_compact', 'cdfg_plus', 'programl']:
        for emb in ['histogram', 'inst2vec', 'ir2vec']:
            acc = []
            
            for test_metric in glob.glob('{}/{}_{}_{}/test_metrics_*.yaml'.format(FLAGS.results_directory, FLAGS.dataset, rep, emb, round_)):
                fin = open(test_metric)
                test_metrics = yl.load(fin, Loader=yl.FullLoader)
                fin.close()

                acc.append(test_metrics['accuracy'])
                
            height.append(np.avg(acc))
            std.append(np.std(acc))

            graph = rep[:-6] if 'compatct' in graph else rep
            bars.append('{}_{}'.format(graph, emb))

    for rep in ['ir2vec', 'inst2vec', 'milepost', 'histogram', 'lbpeq', 'lbpif', 'prog2image']:
        acc = []
        
        for test_metric in glob.glob('{}/{}_{}/test_metrics_*.yaml'.format(FLAGS.results_directory, FLAGS.dataset, rep, round_)):
            fin = open(test_metric)            
            test_metrics = yl.load(fin, Loader=yl.FullLoader)
            fin.close()
            
            acc.append(test_metrics['accuracy'])
            
        height.append(np.avg(acc))
        std.append(np.std(acc))
        bars.append(rep)

    # Labels
    #plt.xlabel("Representations")
    plt.ylabel("Accuracy")

    # Create bars 
    x_pos = np.arange(len(bars))
    plt.ylim(0, 1.0)
    plt.bar(x_pos, height, color=(0.1, 0.1, 0.1, 0.1), edgecolor='blue', yerr=std, ecolor='blue', capsize=3)

    # Create names on the axis
    plt.yticks([i/10 for i in range(0, 11, 1)])
    plt.xticks(x_pos, bars, rotation=90)

    # Save graph
    filename = '{}/{}'.format(FLAGS.results_directory, FLAGS.filename)
    plt.savefig(filename, bbox_inches='tight', pad_inches = 0)


# Execute
if __name__ == '__main__':
    # app
    flags.DEFINE_string('results_directory',
                        None,
                        'Results directory')
    flags.DEFINE_string('dataset',
                        None,
                        'The dataset')
    flags.DEFINE_string('filename',
                        None,
                        'The output filename')
    
    flags.mark_flag_as_required('results_directory')    
    flags.mark_flag_as_required('dataset')
    flags.mark_flag_as_required('filename')

    app.run(plot)
