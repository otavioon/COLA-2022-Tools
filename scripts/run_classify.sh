#! /bin/bash

dataset_top_dir=$1
dataset_name=$2
dataset_description=$3

for rep in 'inst2vec' 'ir2vec' 'histogram' 'milepost'; do
    ./classify.py --dataset_directory ${dataset_top_dir}/${dataset_name}_${rep} \
		  --dataset_description ${dataset_description} \
		  --results_directory ${dataset_top_dir}/${dataset_name}_${rep}_results \
		  --model dcnn
done

for rep in 'cfg' 'cfg_compact' 'cdfg' 'cdfg_compact' 'cdfg_plus' 'programl'; do
   for node_emb in 'histogram' 'inst2vec' 'ir2vec'; do 
       ./classify.py --dataset_directory ${dataset_top_dir}/${dataset_name}_${rep}_${node_emb} \
		     --dataset_description ${dataset_description} \
		     --results_directory ${dataset_top_dir}/${dataset_name}_${rep}_${node_emb}_results \
		     --model dgcnn
   done
done

   
