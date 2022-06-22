# Experimental artefact (COLA'22)

This repository contains the experimental artefact used in the paper "Program Representations for Predictive Compilation: State of Affairs in the Early 20’s"

## Contents

The repository is organized hierarchically. The directories are:
- Directory `datasets` contains all datasets used in the experiments;
- Directory `scripts` contains scripts for executing the experiments (extracting features, executing models, plot charts, *etc.*);
- Directory `reproduce-experiments` contains scripts for running the experiments with the pre-defined arguments 
- Directory `results` contains the experimental results;
- Directory `tools` contains the support tools, including the `YaCos` framework;
- Directory `docker` contains the scripts to build and execute a Docker container environment.  

## Installation instructions

A docker environment is given in order to reproduce the experiments. In order to create the environment, you must:

1. Enter in `docker` directory.
2. Run `1.build_docker_image.sh` script which will create the `cola-2022` docker image based on the Dockerfile.
3. Run `2.extract_yacos_data.sh` script which will extract [YaCoS](https://github.com/ComputerSystemsLaboratory/YaCoS/) related data.

Running `run_docker_command.sh` script will start a shell inside artifact's environment.

## Reproducing experiments

The directory `reproduce-experiments` can be used in order to: generate the LLVM IR files, generate the embeddings and run the experiments. Each script starts with a number and must run from minor to major, in order to have an end-to-end pipeline. 
Some notes:
- `0.create-ir.sh` will generate LLVM IR files from source files which is located at `datasets/src/`.
- The scripts starting with prefix `1.*.sh` generates different embeddings based on LLVM IR files. It can be run it order or not.


