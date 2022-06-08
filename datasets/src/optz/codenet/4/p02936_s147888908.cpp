#include<iostream>
#include <set>

using namespace std;

struct node {int parent; set<int> children; long count; };

struct node nd[200001];

void add(int ni, int val) {
	nd[ni].count += val;
	for (auto itr = nd[ni].children.begin(); itr != nd[ni].children.end(); itr++) {
		add(*itr, val);
	}
}

long value(int ni) {
	long sum=nd[ni].count;
	for (int i=nd[ni].parent; i>0; i=nd[i].parent) {
		sum += nd[i].count;
	}
	return sum;
}

int main()
{
    // 整数の入力
    int N, Q;
    cin >> N >> Q;

	int i, a, b;
	for (i=1; i<N; i++) {
		cin >> a >> b;
		nd[b].parent = a;
		nd[a].children.insert(b);
	}

	int p, x;
	for (i=1; i<=Q; i++) {
		cin >> p >> x;
		nd[p].count += x;
	}

    // 出力
	for (i=1; i<=N; i++) {
		cout << value(i) << " ";
	}
	cout << endl;
//    cout << (a+b+c) << " " << s << endl;
    return 0;
}
