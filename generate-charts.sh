#python3 scripts/plot_accuracy-v1.py -r results-v1 -d POJ-5_TVT -f figures-v1/POJ-5_acc.pdf
#python3 scripts/plot_accuracy-v1.py -r results-v1 -d AnghaLoops_TVT -f figures-v1/AnghaLoops_acc.pdf

python3 scripts/plot_accuracy-v1.py -r results/algo -d poj -f figures-v2/algo/figure10_poj.pdf
python3 scripts/plot_accuracy-v1.py -r results/algo -d codenet -f figures-v2/algo/figure11_codenet.pdf
python3 scripts/plot_accuracy-v1.py -r results/loop -d angabench -f figures-v2/loop/figure12_anghabench.pdf
python3 scripts/plot_accuracy-v1.py -r results/optz -d poj -f figures-v2/optz/figure14_poj.pdf
python3 scripts/plot_accuracy-v1.py -r results/optz -d codenet -f figures-v2/optz/figure15_codenet.pdf
python3 scripts/plot_accuracy-v1.py -r results/optz -d angabench -f figures-v2/optz/figure16_angabench.pdf
