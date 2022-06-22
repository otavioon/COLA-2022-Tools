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
# Extract histogram from IR.
#

import os
import sys
import glob
import numpy as np
from tqdm.contrib.concurrent import thread_map
import argparse
from pathlib import Path
from typing import List

from absl import app, flags, logging

from yacos.info import compy as R
from yacos.info.compy.extractors import LLVMDriver


def build_histogram(functionInfos):
    keys = ['ret',
            'br',
            'switch',
            'indirectbr',
            'invoke',
            'callbr',
            'resume',
            'catchswitch',
            'catchret',
            'cleanupret',
            'unreachable',
            'fneg',
            'add',
            'fadd',
            'sub',
            'fsub',
            'mul',
            'fmul',
            'udiv',
            'sdiv',
            'fdiv',
            'urem',
            'srem',
            'frem',
            'shl',
            'lshr',
            'ashr',
            'and',
            'or',
            'xor',
            'extractelement',
            'insertelement',
            'sufflevector',
            'extractvalue',
            'insertvalue',
            'alloca',
            'load',
            'store',
            'fence',
            'cmpxchg',
            'atomicrmw',
            'getelementptr',
            'trunc',
            'zext',
            'sext',
            'fptrunc',
            'fpext',
            'fptoui',
            'fptosi',
            'uitofp',
            'sitofp',
            'ptrtoint',
            'inttoptr',
            'bitcast',
            'addrspacecast',
            'icmp',
            'fcmp',
            'phi',
            'select',
            'freeze',
            'call',
            'var_arg',
            'landingpad',
            'catchpad',
            'cleanuppad']

    values = []
    for data in functionInfos:
        values.append([data.instructions[key] for key in keys])

    return [sum(x) for x in zip(*values)]


def do_extract_and_save(args):
    source_file = args[0]
    output_file = args[1]
    builder = args[2]

    try:
        extractionInfo = builder.ir_to_info(str(source_file))
        info = build_histogram(extractionInfo.functionInfos)
        np.savez_compressed(output_file, values=info)
    except Exception as e:
        print(f"Error extracting histogram from: '{source_file}'. {e.__class__.__name__}: {e}")


def main(root_dataset_dir: Path, root_output_dir: Path, ir_dir: str, workers: int = None):
    root_dataset_dir = root_dataset_dir / ir_dir

    if not root_dataset_dir.is_dir():
        raise FileNotFoundError(dataset_dir)

    # Instantiate the LLVM driver.
    driver = LLVMDriver([])
    # Instantiate the builder.
    builder = R.LLVMHistogramBuilder(driver)

    folders = [p for p in root_dataset_dir.glob("*") if p.is_dir()]

    for folder in folders:
        output_dir = root_output_dir / f"histogram_{ir_dir}" / folder.stem
        output_dir.mkdir(parents=True, exist_ok=True)

        args = [
            (source, output_dir/f"{source.stem}", builder)
            for source in folder.glob("*.ll")
        ]

        # Run thread map
        output_files = thread_map(
            do_extract_and_save, args, max_workers=workers,
            desc=f"Extracting histogram from LLVM IR to: '{output_dir}'"
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
