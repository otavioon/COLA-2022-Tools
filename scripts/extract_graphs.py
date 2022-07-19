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
# Extract graph representations from IR.
#

import os
import sys
import glob
import numpy as np
from tqdm.contrib.concurrent import thread_map
import argparse
from pathlib import Path
from typing import List
import pandas as pd
import pickle as pk

os.environ['TF_CPP_MIN_LOG_LEVEL'] = '3'

from stellargraph import StellarDiGraph

from yacos.info import compy as R
from yacos.info.compy.extractors import LLVMDriver


def extract_graph_data(graph):
    """Extract edges, nodes and embeddings."""
    nodes = {}
    nodes['histogram'] = graph.get_nodes_histogram_embeddings('ir')
    nodes['inst2vec'] = graph.get_nodes_inst2vec_embeddings()
    nodes['ir2vec'] = graph.get_nodes_ir2vec_embeddings()
    edges = graph.get_edges_str_dataFrame()
    return edges, nodes


def do_generate_graph_and_save(args):
    """Extract edges, nodes and embeddings."""
    try:
        visitors = {
            'cfg': R.LLVMCFGCallNoRootVisitor,
            'cfg_compact': R.LLVMCFGCallCompactSingleEdgeNoRootVisitor,
            'cdfg': R.LLVMCDFGCallNoRootVisitor,
            'cdfg_compact': R.LLVMCDFGCallCompactSingleEdgeNoRootVisitor,
            'cdfg_plus': R.LLVMCDFGPlusNoRootVisitor,
            'programl': R.LLVMProGraMLNoRootVisitor
        }

        source_file: Path = args[0]
        root_output_dir: Path = args[1]
        builder = args[2]
        graph_type = args[3]
        ir_dir: str = args[4]
        folder: str = args[5]

        extractionInfo = builder.ir_to_info(str(source_file))
        graph = builder.info_to_representation(extractionInfo, visitors[graph_type])
        edges, nodes_data = extract_graph_data(graph)

        for feat, feat_data in nodes_data.items():
            indexes = []
            embeddings = []
            for idx, _, emb in feat_data:
                indexes.append(idx)
                embeddings.append(emb)
            nodes = pd.DataFrame(embeddings, index=indexes)

            stellar_graph = StellarDiGraph(
                nodes=nodes, edges=edges, edge_type_column="type")

            output_dir = root_output_dir / f"{graph_type}_{feat}_{ir_dir}" / folder.stem
            output_dir.mkdir(parents=True, exist_ok=True)

            output_file = output_dir / f"{source_file.stem}.pk"
            with output_file.open("wb") as f:
                pk.dump(stellar_graph, f)
    except Exception as e:
        print(f"Error extracting graph '{graph_type}' from: '{source_file}'. {e.__class__.__name__}: {e}")

def main(
        root_dataset_dir: Path, root_output_dir: Path, ir_dir: str,
        graph_type: str, workers: int = None):

    root_dataset_dir = root_dataset_dir / ir_dir

    if not root_dataset_dir.is_dir():
        raise FileNotFoundError(dataset_dir)
    """Extract the representation from the source code."""

    # Instantiate the LLVM driver.
    driver = LLVMDriver()
    # Define the builder
    builder = R.LLVMGraphBuilder(driver)

    folders = [p for p in root_dataset_dir.glob("*") if p.is_dir()]

    args = [
        (source, root_output_dir, builder, graph_type, ir_dir, folder)
        for folder in folders for source in folder.glob("*.ll")
    ]

    output_files = thread_map(
        do_generate_graph_and_save, args, max_workers=workers,
        desc=f"Extracting graph type '{graph_type}' from LLVM '{ir_dir}' to: '{output_dir}'"
    )
    return 0


# Execute
if __name__ == '__main__':
    parser = argparse.ArgumentParser(
        description='Extract graph representations from a LLVM IR dataset',
        formatter_class=argparse.ArgumentDefaultsHelpFormatter)
    parser.add_argument("root_dataset_dir", action="store", type=str,
                        help="Directory to search for embeddings files")
    parser.add_argument("output_dir", action="store", type=str,
                        help="Directory where representation files will be outputed")
    parser.add_argument("--ir-dir", type=str, required=True,
                        help="IR directory")
    parser.add_argument("--graph-type", type=str, required=True, default="cfg",
                        choices=[
                            'cfg', 'cfg_compact', 'cdfg', 'cdfg_compact',
                            'cdfg_plus', 'programl'
                        ],
                        help="Graph representation to extract")
    parser.add_argument("--workers", type=int, default=None,
                        help="Number of concurrent processes")
    args = parser.parse_args()
    print("Extracting graph representation....")
    print(args)

    root_dataset_dir = Path(args.root_dataset_dir)
    output_dir = Path(args.output_dir)

    ret_code = main(
        root_dataset_dir=root_dataset_dir, root_output_dir=output_dir,
        ir_dir=args.ir_dir, graph_type=args.graph_type, workers=args.workers
    )
    sys.exit(ret_code)
