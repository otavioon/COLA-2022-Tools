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
        for filepath in representation_dir.rglob("test_metrics*.yaml"):
            try:
                accuracy = read_accuracy(filepath)
                representation = representation_dir.stem
                results[representation].append(accuracy)
            except Exception as e:
                print(f"Error for {filepath}: {e.__class__.__name__}: {e}")
                continue

    return dict(results)

def plot_v_box_plot(results, output_filename: Path = None, rename_map: dict = None):
    fig, ax = plt.subplots(figsize =(8, 4))

    # Collect data
    sorted_results = list(results.items())
    sorted_results.sort()
    labels = []
    datasets = []
    for result_label, res in sorted_results:
        if rename_map:
            labels.append(rename_map[result_label]) # Cut three first digits
        else:
            labels.append(result_label)
        datasets.append(res)

    # Vertical Box Plor
    bplot1 = ax.boxplot(datasets, vert=True, patch_artist=True, showfliers=False, manage_ticks=True)

    ax.set_ylim([0, 1])
    ax.set_yticks(np.linspace(0, 1, 11))
    ax.set_ylabel('Accuracy')
    ax.yaxis.set_major_formatter(mtick.PercentFormatter(1.0))
    #ax.set_title('CHART TITLE')
    ax.grid()
    ax.set_xticklabels(labels, fontname="Times New Roman")
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
    parser.add_argument("--rename", action="store_true", help="Perform renaming of labels")
    args = parser.parse_args()

    import matplotlib
    matplotlib.rcParams['pdf.fonttype'] = 42
    matplotlib.rcParams['ps.fonttype'] = 42
    matplotlib.rc('font',**{'family':'serif','serif':['Times New Roman']})
    #rc('text', usetex=True)

    results = collect_results(Path(args.results_directory), args.dataset)
    renames = {
        "cdfg_compact_histogram_IR_O0": "cdfg_c : histogram",
        "cdfg_compact_inst2vec_IR_O0": "cdfg_c : inst2vec",
        "cdfg_compact_ir2vec_IR_O0": "cdfg_c : ir2vec",
        "cdfg_histogram_IR_O0": "cdfg : histogram",
        "cdfg_inst2vec_IR_O0": "cdfg : inst2vec",
        "cdfg_ir2vec_IR_O0": "cdfg : ir2vec",
        "cdfg_plus_histogram_IR_O0": "cdfg+ : histogram",
        "cdfg_plus_inst2vec_IR_O0": "cdfg+ : inst2vec",
        "cdfg_plus_ir2vec_IR_O0": "cdfg+ : ir2vec",
        "cfg_compact_histogram_IR_O0": "cfg_c : histogram",
        "cfg_compact_inst2vec_IR_O0": "cfg_c : inst2vec",
        "cfg_compact_ir2vec_IR_O0": "cfg_c : ir2vec",
        "cfg_histogram_IR_O0": "cfg : histogram",
        "cfg_inst2vec_IR_O0": "cfg : inst2vec",
        "cfg_ir2vec_IR_O0": "cfg : ir2vec",
        "histogram_IR_O0": "histogram",
        "ir2vec_IR_O0": "ir2vec",
        "inst2vec_IR_O0": "inst2vec",
        "milepost_IR_O0": "milepost",
        "programl_histogram_IR_O0": "programl : histogram",
        "programl_inst2vec_IR_O0": "programl : inst2vec",
        "programl_ir2vec_IR_O0": "programl : ir2vec",
        "lbpeq": "lbpeq",
        "lbpif": "lbpif",
        "prog2image": "prog2img"
    }

    if not args.rename:
        renames = None

    plot_v_box_plot(results, Path(args.filename), rename_map=renames)
