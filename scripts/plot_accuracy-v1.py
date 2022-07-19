#! /usr/bin/env python3
import sys
import numpy as np
import yaml
import glob
import matplotlib.pyplot as plt
import matplotlib.ticker as mtick
import argparse

from pathlib import Path
from collections import defaultdict

def read_accuracy(filename: Path):
    with filename.open("r") as f:
        results = yaml.load(f, Loader=yaml.FullLoader)
    return results['accuracy']

def collect_results(results_directory: Path, dataset_dir: str):
    """Plot boxplots for each experiment."""
    search_dir = results_directory / dataset_dir

    # Collect results
    results = defaultdict(list)
    for representation_dir in search_dir.glob("*"):
        print(f"Looking at {representation_dir}....")
        for filepath in representation_dir.rglob("test_metrics.yaml"):
            accuracy = read_accuracy(filepath)
            representation = representation_dir.stem
            results[representation].append(accuracy)

    return dict(results)

def plot_v_box_plot(results, output_filename: Path = None):
    fig, ax = plt.subplots(figsize =(8, 4))

    # Collect data
    sorted_results = list(results.items())
    sorted_results.sort()
    labels = []
    datasets = []
    for resultlabel, res in sorted_results:
        labels.append(resultlabel) # Cut three first digits
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
    if output_filename is not None:
        output_filename.parent.mkdir(parents=True, exist_ok=True)
        plt.savefig(output_filename, transparent=True, bbox_inches='tight')
        print(f"Figure saved to {output_filename}")
    else:
        plt.show()

if __name__ == '__main__':
    parser = argparse.ArgumentParser()
    parser.add_argument("-r", "--results_directory", help="Results directory")
    parser.add_argument("-d", "--dataset", help="Dataset subdirectory name")
    parser.add_argument("-f", "--filename", help="Output filename")
    args = parser.parse_args()

    import matplotlib
    matplotlib.rcParams['pdf.fonttype'] = 42
    matplotlib.rcParams['ps.fonttype'] = 42
    matplotlib.rc('font',**{'family':'serif','serif':['Times']})
    #rc('text', usetex=True)

    results = collect_results(Path(args.results_directory), args.dataset)
    plot_v_box_plot(results, Path(args.filename))
