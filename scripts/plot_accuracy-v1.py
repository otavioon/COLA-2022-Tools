#! /usr/bin/env python3
import sys
import numpy as np
import yaml
import glob 
import matplotlib.pyplot as plt
import matplotlib.ticker as mtick
import argparse

def read_accuracy(filename):
    fin = open(filename)
    results = yaml.load(fin, Loader=yaml.FullLoader)
    fin.close()
    return results['accuracy']

def collect_results(results_directory,dataset_dir):
    """Plot boxplots for each experiment."""

    # Collect results
    results = {}
    search_str = '{}/{}/*'.format(results_directory, dataset_dir)
    for filepath in glob.glob(search_str):
        dirlist = filepath.split('/')
        if len(dirlist) != 3:
            print("Could not decode file path into expected structure: results_dir / dataset / experiment")
            print("Skiping path: ", filepath)
        expID = dirlist[2]
        if expID not in results: results[expID] = []
        exp_search_str = '{}/{}/{}/*/test_metrics.yaml'.format(results_directory, dataset_dir, expID)
        #print("Looking for files at: ",exp_search_str)
        for result_file in glob.glob(exp_search_str):
            dirlist = result_file.split('/')
            results[expID].append(read_accuracy(result_file))

    return results

def plot_v_box_plot(results,outputfilename=None):
    fig, ax = plt.subplots(figsize =(8, 4))
    #fig, ax = plt.subplots()

    # Collect data
    sorted_results = list(results.items())
    sorted_results.sort()
    labels = []
    datasets = []
    for resultlabel, res in sorted_results:
        labels.append(resultlabel[3:]) # Cut three first digits
        datasets.append(res)

    # Vertical Box Plor
    bplot1 = ax.boxplot(datasets, vert = True, patch_artist = True) 

    ax.set_ylim([0, 1])
    ax.set_ylabel('Accuracy')
    ax.yaxis.set_major_formatter(mtick.PercentFormatter(1.0))
    #ax.set_title('CHART TITLE')
    ax.grid()
    ax.set_xticklabels(labels,fontname="Times")
    fig.autofmt_xdate(rotation=45)
    if outputfilename != None:
        plt.savefig(outputfilename,transparent=True,bbox_inches='tight')
    else:
        plt.show()

if __name__ == '__main__':
    parser = argparse.ArgumentParser()
    parser.add_argument("-r", "--results_directory", help="Results directory")
    parser.add_argument("-d", "--dataset", help="Dataset subdirectory name")
    parser.add_argument("-f", "--filename",nargs='?',help="Output filename")
    args = parser.parse_args()

    import matplotlib
    matplotlib.rcParams['pdf.fonttype'] = 42
    matplotlib.rcParams['ps.fonttype'] = 42
    matplotlib.rc('font',**{'family':'serif','serif':['Times']})
    #rc('text', usetex=True)

    results = collect_results(args.results_directory, args.dataset)
    plot_v_box_plot(results, args.filename)
