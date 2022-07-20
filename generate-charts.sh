#python3 scripts/plot_accuracy-v1.py -r results-v1 -d POJ-5_TVT -f figures-v1/POJ-5_acc.pdf
#python3 scripts/plot_accuracy-v1.py -r results-v1 -d AnghaLoops_TVT -f figures-v1/AnghaLoops_acc.pdf

python3 scripts/plot_accuracy-v1.py --rename -r results/algo -d poj -f figures/algo/figure10_poj.pdf
python3 scripts/plot_accuracy-v1.py --rename -r results/algo -d codenet -f figures/algo/figure11_codenet.pdf
python3 scripts/plot_accuracy-v1.py --rename -r results/loop -d anghabench -f figures/loop/figure12_anghabench.pdf
python3 scripts/plot_accuracy-v1.py --rename -r results/loop -d anghabench_2C -f figures/loop/figure13_anghabench_2C.pdf
python3 scripts/plot_accuracy-v1.py --rename -r results/optz -d poj -f figures/optz/figure14_poj.pdf
python3 scripts/plot_accuracy-v1.py --rename -r results/optz -d codenet -f figures/optz/figure15_codenet.pdf
python3 scripts/plot_accuracy-v1.py --rename -r results/optz -d anghabench -f figures/optz/figure16_angabench.pdf
python3 scripts/plot_accuracy-v1.py --rename -r results/optz -d poj_s -f figures/optz/figure17_poj_s.pdf
