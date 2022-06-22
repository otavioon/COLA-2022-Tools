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
# Extract milepost representation from IR.
#

import os
import sys
import glob
import numpy as np
from tqdm.contrib.concurrent import thread_map
import argparse
from pathlib import Path
from typing import List

from yacos.info import compy as R
from yacos.info.compy.extractors import LLVMDriver


def build_milepost(functionInfos):
    """Find program representation."""
    keys = ['ft01_BBInMethod',
            'ft02_BBWithOneSuccessor',
            'ft03_BBWithTwoSuccessors',
            'ft04_BBWithMoreThanTwoSuccessors',
            'ft05_BBWithOnePredecessor',
            'ft06_BBWithTwoPredecessors',
            'ft07_BBWithMoreThanTwoPredecessors',
            'ft08_BBWithOnePredOneSuc',
            'ft09_BBWithOnePredTwoSuc',
            'ft10_BBWithTwoPredOneSuc',
            'ft11_BBWithTwoPredTwoSuc',
            'ft12_BBWithMoreTwoPredMoreTwoSuc',
            'ft13_BBWithInstructionsLessThan15',
            'ft14_BBWithInstructionsIn[15-500]',
            'ft15_BBWithInstructionsGreaterThan500',
            'ft16_EdgesInCFG',
            'ft17_CriticalEdgesInCFG',
            'ft18_AbnormalEdgesInCFG',
            'ft19_DirectCalls',
            'ft20_ConditionalBranch',
            'ft21_AssignmentInstructions',
            'ft22_ConditionalBranch',
            'ft23_BinaryIntOperations',
            'ft24_BinaryFloatPTROperations',
            'ft25_Instructions',
            'ft26_AverageInstruction',
            'ft27_AveragePhiNodes',
            'ft28_AverageArgsPhiNodes',
            'ft29_BBWithoutPhiNodes',
            'ft30_BBWithPHINodesIn[0-3]',
            'ft31_BBWithMoreThan3PHINodes',
            'ft32_BBWithArgsPHINodesGreaterThan5',
            'ft33_BBWithArgsPHINodesGreaterIn[1-5]',
            'ft34_SwitchInstructions',
            'ft35_UnaryOperations',
            'ft36_InstructionThatDoPTRArithmetic',
            'ft37_IndirectRefs',
            'ft38_AdressVarIsTaken',
            'ft39_AddressFunctionIsTaken',
            'ft40_IndirectCalls',
            'ft41_AssignmentInstructionsWithLeftOperandIntegerConstant',
            'ft42_BinaryOperationsWithOneOperandIntegerConstant',
            'ft43_CallsWithPointersArgument',
            'ft44_CallsWithArgsGreaterThan4',
            'ft45_CallsThatReturnPTR',
            'ft46_CallsThatReturnInt',
            'ft47_ConstantZero',
            'ft48_32-bitIntegerConstants',
            'ft49_ConstantOne',
            'ft50_64-bitIntegerConstants',
            'ft51_ReferencesLocalVariables',
            'ft52_DefUseVariables',
            'ft53_LocalVariablesReferred',
            'ft54_ExternVariablesReferred',
            'ft55_LocalVariablesPointers',
            'ft56_VariablesPointers']

    values = []
    for data in functionInfos:
        values.append([data.features[key] for key in keys])

    return [sum(x) for x in zip(*values)]

def do_extract_and_save(args):
    source_file = args[0]
    output_file = args[1]
    builder = args[2]

    try:
        extractionInfo = builder.ir_to_info(str(source_file))
        info = build_milepost(extractionInfo.functionInfos)
        np.savez_compressed(output_file, values=info)
    except Exception as e:
        print(f"Error extracting milepost from: '{source_file}'. {e.__class__.__name__}: {e}")


def main(root_dataset_dir: Path, root_output_dir: Path, ir_dir: str, workers: int = None):
    root_dataset_dir = root_dataset_dir / ir_dir

    if not root_dataset_dir.is_dir():
        raise FileNotFoundError(dataset_dir)

    # Instantiate the LLVM driver.
    driver = LLVMDriver([])
    # Instantiate the builder.
    builder = R.LLVMMSFBuilder(driver)

    folders = [p for p in root_dataset_dir.glob("*") if p.is_dir()]

    for folder in folders:
        output_dir = root_output_dir / f"milepost_{ir_dir}" / folder.stem
        output_dir.mkdir(parents=True, exist_ok=True)

        args = [
            (source, output_dir/f"{source.stem}", builder)
            for source in folder.glob("*.ll")
        ]

        # Run thread map
        output_files = thread_map(
            do_extract_and_save, args, max_workers=workers,
            desc=f"Extracting milepost from LLVM IR to: '{output_dir}'"
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
