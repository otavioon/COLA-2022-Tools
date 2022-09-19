echo "PROB-P"
python3 scripts/acc_table.py --rename -r results/algo -d poj
echo ""

echo "PROB-C"
python3 scripts/acc_table.py --rename -r results/algo -d codenet
echo ""

echo "LOOP-2"
python3 scripts/acc_table.py --rename -r results/loop -d anghabench_2C
echo ""

echo "LOOP-4"
python3 scripts/acc_table.py --rename -r results/loop -d anghabench
echo ""

echo "OPTZ-A"
python3 scripts/acc_table.py --rename -r results/optz -d anghabench
echo ""

echo "OPTZ-C"
python3 scripts/acc_table.py --rename -r results/optz -d codenet
echo ""

echo "OPTZ-P"
python3 scripts/acc_table.py --rename -r results/optz -d poj
echo ""

echo "OPTZ-P-sp"
python3 scripts/acc_table.py --rename -r results/optz -d poj_s
echo ""
