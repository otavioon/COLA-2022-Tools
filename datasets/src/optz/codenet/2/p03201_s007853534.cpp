#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <string.h>
#include <algorithm>
#include <set>
#include <map>
#include <vector>
#include <math.h>
#include <cmath>
#include <queue>
#include <stack>
#include <list>
#include <functional>
#include <numeric>
#include <iostream>
#include <string>
#include <time.h>

using namespace std;
typedef long long ll;
#define rep(i, n) for (ll i = 0; i < (n); ++i)

struct Bipartite_Matching
{
	vector< vector< int > > graph;
	vector< int > match, alive, used;
	int timestamp;

	Bipartite_Matching(int n)
	{
		timestamp = 0;
		graph.resize(n);
		alive.assign(n, 1);
		used.assign(n, 0);
		match.assign(n, -1);
	}

	void add_edge(int u, int v)
	{
		graph[u].push_back(v);
		graph[v].push_back(u);
	}

	bool dfs(int v)
	{
		used[v] = timestamp;
		for (int i = 0; i < graph[v].size(); i++) {
			int u = graph[v][i], w = match[u];
			if (alive[u] == 0) continue;
			if (w == -1 || (used[w] != timestamp && dfs(w))) {
				match[v] = u;
				match[u] = v;
				return (true);
			}
		}
		return (false);
	}

	int bipartite_matching()
	{
		int ret = 0;
		for (int i = 0; i < graph.size(); i++) {
			if (alive[i] == 0) continue;
			if (match[i] == -1) {
				++timestamp;
				ret += dfs(i);
			}
		}
		return (ret);
	}
};



int N, A[212345];

int main() {

	scanf("%d", &N);
	rep(i, N) scanf("%d", &A[i]);

	Bipartite_Matching graph(N);

	vector<int> A_vec(N);
	rep(i, N) A_vec[i] = A[i];

	sort(A_vec.begin(), A_vec.end());
	for (int i = 0; i < N; ++i) {
		for (int b = 1; ; b <<= 1) {
			if (b - A_vec[i] >= 1) {
				int pos = lower_bound(A_vec.begin(), A_vec.end(), b - A_vec[i]) - A_vec.begin();
				if (pos == i) pos++;
				for (; pos > i && pos < A_vec.size() && A_vec[pos] == b - A_vec[i]; pos++) {
					graph.add_edge(i, pos);
				}
			}
			if (b == 1 << 30) break;
		}
	}

	printf("%d\n", graph.bipartite_matching());


	return 0;
}