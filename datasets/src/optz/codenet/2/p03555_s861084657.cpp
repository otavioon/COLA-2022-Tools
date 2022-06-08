////////////////////////////////////////////////////////////////////
// This source code is for Visual Studio
////////////////////////////////////////////////////////////////////
#include <iostream>
#include <string>
#include <vector>
#include <list>
#include <queue>
#include <map>
#include <set>
#include <algorithm>
#include <sstream>
#include <iterator>
#include <stack>
#include <functional>
#include <iomanip>
#include <string>
#include <cstring>
#include <deque>
#include <math.h>

#define	numberof(a)	(sizeof(a) / sizeof(a[0]))
#define	INF		UINT64_MAX
#define Rep(i,n) for(int i = 0; i < (n); ++i )

using namespace std;

typedef vector< vector<int> > MAT;
typedef pair<int, int> PINT;
typedef long long ll;
typedef uint32_t u32;
typedef uint64_t u64;
typedef int32_t s32;
typedef int64_t s64;

//constant
//--------------------------------------------
const double EPS = 1e-10;
const double PI  = acos(-1.0);

struct edge
{
	ll from;
	ll to;
	ll cost;
};

bool edge_comp(const edge& e1, const edge& e2)
{
	return e1.cost < e2.cost;
}

////////////////////
// UnionFind
////////////////////
class UnionFind
{
public:
	vector<int> parent;
	vector<int> rank;

	UnionFind(int n)
	{
		Rep(i, n) {
			parent.push_back(i);
			rank.push_back(1);
		}
	}
	int root(int x)
	{
		if (parent[x] != x) parent[x] = root(parent[x]);
		return parent[x];
	}
	// is same union between x and y
	bool same(int x, int y)
	{
		return root(x) == root(y);
	}
	void unite(int x, int y)
	{
		int rx = root(x);
		int ry = root(y);
		if (rx == ry) return;
		if (rank[rx] > rank[ry]) {
			parent[ry] = rx;
			rank[rx] += rank[ry];
		}
		if (rank[rx] <= rank[ry]) {
			parent[rx] = ry;
			rank[ry] += rank[rx];
		}
	}
};

////////////////////
// kruskal(最小全域木)
////////////////////
vector< edge > shortest_edges;
ll kruskal(vector<edge> & edges, ll V)	// edgesは辺の集合、Vは頂点数
{
	UnionFind uf(V);// Union-Findの初期化
	ll res = 0;

	sort(edges.begin(), edges.end(), edge_comp); // edge.costの小さい順

	for (int i = 0; i < edges.size(); i++)
	{
		edge e = edges[i];
		if (!uf.same(e.from, e.to)) {
			uf.unite(e.from, e.to);
			res += e.cost;

			// save
			shortest_edges.push_back(e);
		}
	}

	return res;	// 最小の重み
}

////////////////////
// 回文判定 O(N)
////////////////////
bool isPalindrome(string input_str)
{
	bool ret = true;
	ll i = 0;
	ll j = input_str.length() - 1;

	while (ret && i <= j) {
		ret = ret & (input_str[i] == input_str[j]);
		i++;
		j--;
	}
	return ret;
}

// 数学：		最大公約数、最小公倍数、素因数分解
// 探索：		貪欲法(全探索)、2分探索、ソート
//				BFS(幅優先探索)、DFS(深さ優先探索)
// データ構造：	スタック、キュー、deque
//				ハッシュ、map、リスト
// DP:			桁DP、ビットDP、メモ化再帰
// グラフ:		最短経路(ダイクストラ、ベルマンフォード、ワーシャルフロイト)
//				最小全域木(クラスカル法、プリム法、Union-Find)
//				三角不等式
// その他：		最大フロー、マッチング問題
//				セグメント木、RMQ、BIT、平方分割、しゃくとり法
// 
int main()
{
	string C1 = "";
	string C2 = "";
	string ret = "YES";

	cin >> C1 >> C2;
	ll len = C1.length();

	Rep( i, len) {
		if ( C1[i] != C2[len - i - 1] ) {
			ret = "NO";
			break;
		}
	}

	cout << ret << endl;

	return 0;
}



