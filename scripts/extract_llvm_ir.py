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

import os
import sys
import glob
import subprocess
from tqdm.contrib.concurrent import thread_map
import argparse
from pathlib import Path
from typing import List

from yacos.essential import IO
from yacos.essential import Sequence
from yacos.info import compy as R
from yacos.info.compy.extractors import LLVMDriver


def emit_llvm(filename: Path, output_file: Path):
    """Generate bitcode."""
    if str(filename).endswith('.c'):
        compiler = 'clang'
    elif str(filename).endswith('.cpp'):
        compiler = 'clang++'
    else:
        return None

    cmdline = f'{compiler} -S -c -Xclang -disable-O0-optnone -w -emit-llvm {filename} -o {output_file}'
    subprocess.run(cmdline, shell=True, check=True, capture_output=False)

def optimize(filename, sequence):
    """Optimize."""
    cmdline = f'opt {filename} -S {Sequence.name_pass_to_string(sequence)} -o {filename}'
    subprocess.run(cmdline, shell=True, check=True, capture_output=False)


def do_extract_and_optimize(args):
    source_file = args[0]
    output_file = args[1]
    level_str = args[2]
    try:
        emit_llvm(source_file, output_file)
        optimize(output_file, [level_str])
    except Exception as e:
        print(f"Error extracting LLVM IR from: '{source_file}'. {e.__class__.__name__}: {e}")

def main(dataset_dir: Path, root_output_dir: Path, level: str, workers: int = None):
    if not dataset_dir.is_dir():
        raise FileNotFoundError(dataset_dir)

    folders = [p for p in dataset_dir.glob("*") if p.is_dir()]

    # Generate LLVM IR
    for folder in folders:
        output_dir = root_output_dir / f"IR_{level}" / folder.stem
        output_dir.mkdir(parents=True, exist_ok=True)
        # create a map
        args = [
            (source, output_dir / f"{source.stem}.ll" , f"-{level}")
            for source in folder.glob('*')
        ]
        # Run thread map
        output_files = thread_map(
            do_extract_and_optimize, args, max_workers=workers,
            desc=f"Extracting LLVM IR from: '{folder}' to '{output_dir}'"
        )

    return 0

if __name__ == '__main__':
    parser = argparse.ArgumentParser(
        description='Extract LLVM IR from a dataset',
        formatter_class=argparse.ArgumentDefaultsHelpFormatter)
    parser.add_argument("dataset_dir", action="store", type=str,
                        help="Directory to search CPP files")
    parser.add_argument("output_dir", action="store", type=str,
                        help="Directory where .ll files will be outputed")
    parser.add_argument("--level", type=str, default='O0',
                        choices=['O0', 'O1', 'O2', 'O3', 'Os', 'Oz'],
                        help="Compiler optimization level")
    parser.add_argument("--workers", type=int, default=None,
                        help="Number of concurrent processes to extract IR")
    args = parser.parse_args()
    print(args)

    dataset_dir = Path(args.dataset_dir)
    output_dir =  Path(args.output_dir)

    ret_code = main(
        dataset_dir=dataset_dir, root_output_dir=output_dir,
        level=args.level, workers=args.workers
    )
    sys.exit(ret_code)
