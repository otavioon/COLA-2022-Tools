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
# Extract inst2vec representation from IR.
#

import os
import sys
import numpy as np

from pathlib import Path
from tqdm.contrib.concurrent import thread_map
from collections import defaultdict
import argparse
import tqdm

from yacos.info.ncc import Inst2Vec

def do_save_embeddings(args):
    try:
        filename = args[0]
        padding = args[1]
        np.savez_compressed(filename, values=padding)
    except Exception as e:
        print(f"Error saving embeddings from: '{filename}'. {e.__class__.__name__}: {e}")


def main(root_dataset_dir: Path, root_output_dir: Path, ir_dir: str, workers: int = None):
    root_dataset_dir = root_dataset_dir / ir_dir

    if not root_dataset_dir.is_dir():
        raise FileNotFoundError(dataset_dir)

    folders = [p for p in root_dataset_dir.glob("*") if p.is_dir()]

    # Extract int2vec
    inst2vec = defaultdict(dict)
    max_length = []

    for folder in tqdm.tqdm(folders, desc="Extracting Inst2Vec"):
        Inst2Vec.prepare_benchmark(str(folder))
        rep = Inst2Vec.extract(data_type="index")
        for bench, indexes in rep.items():
            inst2vec[folder][bench] = indexes
            max_length.append(len(indexes))
        Inst2Vec.remove_data_directory()

    # Padding
    max_length = max(max_length)
    unk_idx, _ = Inst2Vec.unknown
    embeddings = Inst2Vec.embeddings

    args = []

    for folder, data in inst2vec.items():
        # Create the output directory.
        output_dir = root_output_dir / f"inst2vec_{ir_dir}" / folder.stem
        output_dir.mkdir(parents=True, exist_ok=True)

        for bench, indexes in data.items():
            padding = [list(embeddings[idx]) for idx in indexes]
            for i in range(len(indexes), max_length):
                padding += list(embeddings[unk_idx])

            filename = output_dir / bench
            args.append((filename, padding))

    thread_map(
        do_save_embeddings, args, max_workers=workers,
        desc=f"Saving compressed files..."
    )

# Execute
if __name__ == '__main__':
    parser = argparse.ArgumentParser(
        description='Extract Inst2Vec IR from a LLVM IR dataset',
        formatter_class=argparse.ArgumentDefaultsHelpFormatter)
    parser.add_argument("root_dataset_dir", action="store", type=str,
                        help="Directory to search CPP files")
    parser.add_argument("output_dir", action="store", type=str,
                        help="Directory where representation files will be outputed")
    parser.add_argument("--ir-dir", type=str, required=True,
                        help="IR directory")
    parser.add_argument("--workers", type=int, default=None,
                        help="Number of concurrent processes to extract IR")
    args = parser.parse_args()
    print(args)

    root_dataset_dir = Path(args.root_dataset_dir)
    output_dir = Path(args.output_dir)

    ret_code = main(
        root_dataset_dir=root_dataset_dir, root_output_dir=output_dir,
        ir_dir=args.ir_dir, workers=args.workers
    )
    sys.exit(ret_code)
