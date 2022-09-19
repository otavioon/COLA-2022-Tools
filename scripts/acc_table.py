#! /usr/bin/env python3
import sys
import numpy as np
import yaml
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
        # print(f"Looking at {representation_dir}....")
        for filepath in representation_dir.rglob("test_metrics*.yaml"):
            try:
                accuracy = read_accuracy(filepath)
                representation = representation_dir.stem
                results[representation].append(accuracy)
            except Exception as e:
                print(f"Error for {filepath}: {e.__class__.__name__}: {e}")
                continue

    return dict(results)

def plot_v_box_plot(results, rename_map: dict = None, order: list = None):
    # Collect data
    if rename_map:
        results = {
            rename_map[k]: v for k, v in results.items()
        }

    if not order:
        order = list(results.keys())

    for label in order:
        values = results.get(label, None)
        if values is not None:
            median = np.median(values)
            print(f"{label.ljust(32)} & {median*100:.1f}")
        else:
            print(f"{label.ljust(32)} & -")

if __name__ == '__main__':
    parser = argparse.ArgumentParser()
    parser.add_argument("-r", "--results_directory", help="Results directory")
    parser.add_argument("-d", "--dataset", help="Dataset subdirectory name")
    parser.add_argument("--rename", action="store_true", help="Perform renaming of labels")
    args = parser.parse_args()

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

    order = [
        # cfg
        "cfg : histogram",
        "cfg : inst2vec",
        "cfg : ir2vec",
        # cfg compact
        "cfg_c : histogram",
        "cfg_c : inst2vec",
        "cfg_c : ir2vec",
        # cdfg
        "cdfg : histogram",
        "cdfg : inst2vec",
        "cdfg : ir2vec",
        #cdfg compact
        "cdfg_c : histogram",
        "cdfg_c : inst2vec",
        "cdfg_c : ir2vec",
        # cdfg+
        "cdfg+ : histogram",
        "cdfg+ : inst2vec",
        "cdfg+ : ir2vec",
        # programl
        "programl : histogram",
        "programl : inst2vec",
        "programl : ir2vec",
        # others
        "ir2vec",
        "inst2vec",
        "milepost",
        "histogram",
        "lbpif", #LBP
        "lbpeq", # RBP
        "prog2img"
    ]

    if not args.rename:
        renames = None

    plot_v_box_plot(results, rename_map=renames, order=order)
