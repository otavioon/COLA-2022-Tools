#include <iostream>
#include <vector>
#include <algorithm>
#include <stdlib.h>
using namespace std;

int N, Q;
int adj[200001][200001] = {{0}};
vector<int> v;
vector<bool> f;

void rec (int node) {
	if (node>N)
		return;
	f.at(node) = true;
	for (int i=2; i<=N; i++) {
		if (adj[node][i]==1 && !f.at(i)) {
			v.at(i)	+= v.at(node);
			rec (i);
		}
	}
}

int main () {
	cin >> N >> Q;
	for (int i=1; i<N; i++) {
		int a, b;
		cin >> a >> b;
		adj[a][b] = adj[b][a] = 1;
	}
	for (int i=0; i<Q; i++) {
		int p, x;
		cin >> p >> x;
		v.at(p) += x;
	}
	rec (1);

	for (int i=1; i<=N; i++)
		cout << v.at(i) << " ";
	cout << endl;
	return 0;
}