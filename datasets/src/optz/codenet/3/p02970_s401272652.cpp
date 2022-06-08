#define _USE_MATH_DEFINES
#pragma region include
#include <iostream>
#include <iomanip>
#include <stdio.h>

#include <sstream>
#include <algorithm>
#include <iterator>
#include <cmath>
#include <complex>

#include <string>
#include <cstring>
#include <vector>
#include <bitset>

#include <queue>
#include <set>
#include <map>
#include <stack>
#include <list>

#include <ctime>
////
//#include <random>//
#pragma endregion //#include
/////////

#pragma region typedef
typedef long long LL;
typedef long double LD;
typedef unsigned long long ULL;
#pragma endregion //typedef
////定数
const int INF = (int)1e9;
const LL MOD = (LL)1e9 + 7;
const LL LINF = (LL)4e18 + 20;
const LD PI = acos(-1.0);
const double EPS = 1e-9;
/////////
using namespace::std;
/////////
#pragma region Math
#pragma region
long long ext_gcd(long long a, long long b, long long& x, long long& y) {
	if (b == 0) {
		x = 1; y = 0; return a;
	}
	long long q = a / b;
	long long g = ext_gcd(b, a - q * b, x, y);
	x = x - q * y;
	swap(x, y);
	return g;
}
template<class T>
inline T gcd(T a, T b) { return b ? gcd(b, a % b) : a; }

#pragma endregion // 最大公約数 gcd
#pragma region
template<class T>
inline T lcm(T a, T b) { return a / gcd(a, b) * b; }
#pragma endregion // 最小公倍数 lcm
#pragma region
long long invMod(long long a, long long m = MOD) {
	long long x, y;
	ext_gcd(a, m, x, y);
	x %= m;
	if (x < 0) x += m;
	return x;
}

/*
LL powMod(LL x,LL e,LL mod=MOD){
	LL prod = 1%mod;
	for(int i=63;i>=0;--i){
		prod = prod*prod % mod;
		if(e&1LL<<i)prod=prod*x%mod;
	}
	return prod;
}*/

LL powMod(LL num, LL n, LL mod = (LL)MOD) {//(num**n)%mod
	num %= mod;//
	if (n == 0) {
		return (LL)1;
	}
	LL mul = num;
	LL ans = (LL)1;
	while (n) {
		if (n & 1) {
			ans = (ans * mul) % mod;
		}
		mul = (mul * mul) % mod;
		n >>= 1;
	}
	return ans;
}
/*
LL mod_inverse(LL num,LL mod=MOD){
	return powMod(num,MOD-2,MOD);
}*/
#pragma endregion //繰り返し二乗法 powMod
#pragma region
template<class T>
vector<T> getDivisor(T n) {
	vector<T> v;
	for (int i = 1; i * i <= n; ++i) {
		if (n % i == 0) {
			v.push_back(i);
			if (i != n / i) {//平方数で重複して数えないように
				v.push_back(n / i);
			}
		}
	}
	sort(v.begin(), v.end());
	return v;
}
#pragma endregion //約数列挙 getDivisor(n):O(√n)
#pragma endregion //math
//Utility:便利な奴
#pragma region
template<class T>
void UNIQUE(vector<T>& vec) {
	sort(vec.begin(), vec.end());
	vec.erase(unique(vec.begin(), vec.end()), vec.end());
}
#pragma endregion // sort erase unique
////////////////////////////////
#pragma region 
long long  bitcount64(long long bits)
{
	bits = (bits & 0x5555555555555555) + (bits >> 1 & 0x5555555555555555);
	bits = (bits & 0x3333333333333333) + (bits >> 2 & 0x3333333333333333);
	bits = (bits & 0x0f0f0f0f0f0f0f0f) + (bits >> 4 & 0x0f0f0f0f0f0f0f0f);
	bits = (bits & 0x00ff00ff00ff00ff) + (bits >> 8 & 0x00ff00ff00ff00ff);
	bits = (bits & 0x0000ffff0000ffff) + (bits >> 16 & 0x0000ffff0000ffff);
	return (bits & 0x00000000ffffffff) + (bits >> 32 & 0x00000000ffffffff);
}
#pragma endregion //その他
////////////////////////////////
struct edge_base { int to; LL cost; };
edge_base make_edge_base(int to, LL cost) {
	edge_base ret = { to,cost };
	return ret;
}
#pragma region GRL
#pragma region //グラフ
template<class T, class EDGE>
void dijkstra(int root, int V, vector<T>& dist, vector<int>& prev,
	vector< vector<EDGE> > G) {
	priority_queue<pair<T, int>, vector<pair<T, int> >, greater<pair<T, int> > > que;

	dist.assign(V, LINF);
	prev.assign(V, -1);

	dist[root] = 0;
	que.push(pair<T, int>(0, root));//距離、頂点番号

	while (!que.empty()) {
		pair<T, int> p = que.top(); que.pop();
		int v = p.second;
		if (dist[v] < p.first) continue;
		for (int i = 0; i < (int)G[v].size(); ++i) {
			EDGE e = G[v][i];
			if (dist[e.to] > dist[v] + e.cost) {
				dist[e.to] = dist[v] + e.cost;
				prev[e.to] = v;
				que.push(pair<T, int>(dist[e.to], e.to));
			}
		}
	}
}
//経路復元,dijkstraにprev入れた
//http://ronly.hatenablog.com/entry/2017/06/17/161641
vector<int> get_path(vector<int>& prev, int t) {
	vector<int> path;
	while (t != -1) {
		path.push_back(t);
		t = prev[t];
	}
	reverse(path.begin(), path.end());
	return path;
}
#pragma endregion //ダイクストラ法:O(|E|log|V|)
#pragma region //グラフ
void warshall_floyd(vector<vector<LL> >& dist, int V, const LL inf = LINF) {
	for (int k = 0; k < V; ++k) {
		for (int i = 0; i < V; ++i) {
			if (dist[i][k] >= inf) continue;
			for (int j = 0; j < V; ++j) {
				if (dist[k][j] >= inf)continue;
				dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
			}
		}
	}
}
#pragma endregion //ワーシャルフロイド:O(|V|**3)
#pragma region
namespace FLOW {
	//vector< vector<FLOW:edge> > G;

	struct edge_flow : public edge_base {
		LL cap;//LD cap;//
		int rev;
	};
	edge_flow make_edge_flow(int to, LL cap, int rev, LL cost = 1) {
		//edge_flow make_edge_flow(int to,LD cap,int rev,LL cost=1){
		edge_flow ret;

		ret.to = to;
		ret.cost = cost;
		ret.cap = cap;
		ret.rev = rev;
		return ret;
	}

	//*
	class Graph {
	public:
		int V;
		vector< vector<FLOW::edge_flow> > G;
		vector< LL > dist;
		vector< int > iter;
		vector< bool > used;
		void init(int v) {
			V = v;
			G.resize(V);
		}
		void reset() {
			iter.assign(V, 0);
			used.assign(V, false);
		}
		//directed graph
		void add_edge(int from, int to, LL cap) {
			G[from].push_back(FLOW::make_edge_flow(to, cap, G[to].size()));
			G[to].push_back(FLOW::make_edge_flow(from, 0, G[from].size() - 1));
		}

	private:
		//sから最短距離をBFSで計算する
		void bfs(int s) {//許容量もチェックしている
			queue<int> que;
			dist = vector<LL>(V, -1);
			dist[s] = 0;
			que.push(s);
			while (!que.empty()) {
				int v = que.front(); que.pop();
				for (int i = 0; i < (int)G[v].size(); ++i) {
					edge_flow& e = G[v][i];
					if (e.cap > 0 && dist[e.to] < 0) {
						dist[e.to] = dist[v] + 1;
						que.push(e.to);
					}
				}
			}
		}
	private:
		//増加パスをDFSで探す
		LL dfs(int v, int t, LL f) {
			if (v == t) return f;
			for (int& i = iter[v]; i < (int)G[v].size(); ++i) {//?
				FLOW::edge_flow& e = G[v][i];
				if (e.cap > 0 && dist[v] < dist[e.to]) {
					LL d = this->dfs(e.to, t, min(f, e.cap));
					if (d > 0) {
						e.cap -= d;
						G[e.to][e.rev].cap += d;
						return d;
					}
				}
			}
			return 0;
		}
	public:
		//sからtへの最大流量を求める
		LL max_flow(int s, int t) {
			LL flow = 0;
			for (;;) {
				this->bfs(s);
				if (dist[t] < 0) return flow;
				iter = vector<int>(V, 0);
				LL f = this->dfs(s, t, LINF);
				do {
					flow += f;
					f = this->dfs(s, t, LINF);
				} while (f > 0);
			}
		}
	};
	//*/
}
#pragma endregion //dinic :O(|E||V|^2)
#pragma region //グラフ
bool is_bipartite(int v, int c, vector< vector<int> >& G, vector<int>& Color) {
	Color[v] = c;
	for (int i = 0; i < (int)G[v].size(); ++i) {//隣接グラフ
		if (Color[G[v][i]] == c) return false;
		if (Color[G[v][i]] == 0 &&
			!is_bipartite(G[v][i], -c, G, Color)
			) {
			return false;
		}
	}
	return true;
}
bool is_bipartite(int Root, vector< vector<int> >& Graph) {
	int GraphSize = Graph.size();
	vector<int> Color(GraphSize, 0);
	const int ColorNo = 1;
	return is_bipartite(Root, ColorNo, Graph, Color);
}
#pragma endregion //二部グラフチェック is_bipartite(root,GraphList)
#pragma region
namespace matching {
	//https://beta.atcoder.jp/contests/soundhound2018/tasks/soundhound2018_c
	int V;		//頂点数
	vector< vector<int> > G;//グラフ
	vector<int> match;//match[i]:頂点[i]がどことマッチされているか
	vector<bool > used;//
	void add_edge(int u, int v) {
		G[u].push_back(v);
		G[v].push_back(u);
	}

	bool dfs(int v) {
		/*
		https://mathtrain.jp/bipartitematching
		未マッチ辺・マッチ辺・未マッチ辺
		これを
		マッチ辺・未マッチ辺・マッチ辺
		に変えると
		1マッチが2マッチになる。
		未[済未]
		増加路を求めている。
		*/
		used[v] = true;//dfsのroot前に初期化される
		int size = G[v].size();
		for (int i = 0; i < size; ++i) {
			int u = G[v][i];//
			int w = match[u];//
			if (w < 0 || ((used[w] == false) && dfs(w))) {
				/*
				マッチングされていない||
				使われてない&&
				*/
				match[v] = u;
				match[u] = v;
				return true;
			}
		}
		return false;
	}

	int bipartite_matching() {
		int res = 0;
		match = vector<int>(V, -1);//未マッチ状態に初期化
		for (int v = 0; v < V; ++v) {
			if (match[v] < 0) {
				used = vector<bool>(V, false);
				if (dfs(v)) {
					++res;
				}
			}
		}
		return res;
	}
}
#pragma endregion //二部グラフの最大マッチング bipartite_matching()
#pragma endregion //
#pragma region 
vector< vector<LL> > NCK;//初期値:0
//http://sugarknri.hatenablog.com/entry/2016/07/16/165715
void makeinv(vector<LL>& inv, const LL P) {
	int i;
	//const int varMAX = max(100000,(int)inv.size());
	const int varMAX = max(300010, (int)inv.size());

	inv = vector<LL>(varMAX + 1, 0);
	inv[1] = 1;
	for (i = 2; i <= varMAX; i++) {
		inv[i] = (inv[P % i] * (P - P / i) % P) % P;//OVF
		//inv[i] = powMod(i,P-2,P);
	}
}

LL nCk(LL N, LL k, LL mod = MOD) {
	static vector<LL> inv;//modの逆元
	if (inv.size() == 0) {
		makeinv(inv, mod);//modは素数を入れる
	}
	k = min(k, N - k);
	if (k < 0 || k > N) { return 0; }
	if (k == 0) { return 1; }
	if (k == 1) { return N % mod; }
	LL ret = 1;
	for (int i = 1; i <= k; ++i) {
		ret = (ret * ((N + 1 - i) % mod)) % mod;//ret*N:OVF
		ret = (ret * inv[i]) % mod;
	}
	return ret;
}
LL nCk_once(LL N, LL k, LL mod = MOD) {//modは素数
	k = min(k, N - k);
	if (k < 0 || k > N) { return 0; }
	if (k == 0) { return 1; }
	if (k == 1) { return N % mod; }
	LL ret = 1;
	LL A = 1;
	for (LL i = 0; i < k; ++i) {
		A = (A * ((N - i) % mod)) % mod;
	}
	LL B = 1;
	for (LL i = 2; i <= k; ++i) {
		B = (B * (i % mod)) % mod;
	}
	ret = (A * powMod(B, mod - 2, mod)) % mod;
	return ret;
}
#pragma endregion //組み合わせnCk(,10^5)
#pragma region
LL nCk_base(int N, int K, LL mod = MOD) {
	if (K < 0 || N < K) return 0;//多く取り過ぎ
	K = min(K, N - K);
	if (K == 0) { return 1 % mod; }
	if (K == 1) { return N % mod; }//%MOD;
	if (N <= 10000 && NCK[N][K]) {
		return NCK[N][K];
	}
	//N個目を使わない:nCk(N-1,k)
	//N個目を使う	:nCk(N-1,k-1)
	LL ans = (nCk_base(N - 1, K) + nCk_base(N - 1, K - 1)) % mod;//%MOD;
	if (N <= 10000) {
		NCK[N][K] = ans;
	}
	return ans;
}

#pragma endregion //組み合わせ メモ?

#pragma region DSL
class UnionFind {
public:
	int cNum;//要素数
	vector<int> parent;
	vector<int> count;
	vector< vector<int> > GList;
	UnionFind(int n) {
		cNum = n;
		parent = vector<int>(n);
		count = vector<int>(n, 1);
		GList.resize(n);
		for (int i = 0; i < n; ++i) {
			parent[i] = i;
			GList[i].push_back(i);
		}
	}
	int find(int x) {
		if (parent[x] == x) { return x; }
		return parent[x] = find(parent[x]);
	}
	bool same(int x, int y) { return find(x) == find(y); }
	int Count(int x) { return count[find(x)]; }
	void add(int x, int y) {//union
		x = find(x);
		y = find(y);
		if (x == y)return;
		parent[x] = y;

		count[y] += count[x];
		if (GList[y].size() < GList[x].size()) {
			swap(GList[x], GList[y]);
		}
		GList[y].insert(GList[y].end(),
			GList[x].begin(), GList[x].end());
	}
};
#pragma endregion //UnionFind
#pragma region DSL
class BITree {//1-index
	int N;
	vector<LL> bit;
public:
	BITree(int n) {
		N = n;
		bit = vector<LL>(N + 1, 0);//1-index
	}
	void add(int a, LL w) {//aにwを足す
		if (a <= 0 || N < a) return;//a:[1,N]
		for (int i = a; i <= N; i += i & -i) {
			bit[i] += w;
		}
	}
	LL sum(int a) {//[1,a]の和,a:[1,N]
		/*
		1番目からa番目までの和、1-index
		*/
		LL ret = 0;
		if (a > N) a = N;
		for (int i = a; i > 0; i -= i & -i) {
			ret += bit[i];
		}
		return ret;
	}
};
#pragma endregion //BIndexTree
#pragma region
template <typename T>
class segmentTree {
	int N;//要素数
	vector< T > dat1;
	T VAL_E;//初期値
	T VAL_NULL;//空の値
public:
	segmentTree() {};
	/*segmentTree(int n,T val_E ):N(n),VAL_E(val_E){
		dat1.resize(2*n);
		dat1.assign(2*n,val_E);//初期化
	}*/
	void init(int n, T val_E, T val_N) {
		N = n;
		VAL_E = val_E;
		VAL_NULL = val_N;
		int size = 2;
		while (size < N) {
			size <<= 1;
		}
		N = size;
		dat1.resize(2 * N);
		dat1.assign(2 * N, val_E);
	}
	T SELECT(T L, T R) {//扱う演算子
		T ans;
		ans = max(L, R);//
		return ans;
	}

	//index番目の値をvalに変更,indexは"0-index"
	void update(int i, T val) {
		i += N - 1;
		dat1[i] = val;
		while (i > 0) {
			i = (i - 1) / 2;
			dat1[i] = SELECT(dat1[i * 2 + 1], dat1[i * 2 + 2]);
		}
	}

	//区間[L,R)のSELECT
	/*
	調べている範囲[a,b),階数k,見る場所[L,R)
	*/
	T query(int a, int b, int k, int L, int R) {
		if (R <= a || b <= L) {
			return VAL_E;//交差しない
		}
		if (a <= L && R <= b && dat1[k] != VAL_NULL) {
			return dat1[k];
		}

		T res = VAL_E;
		int mid = (L + R) / 2;
		if (a < mid) res = SELECT(res, query(a, b, k * 2 + 1, L, mid));
		if (mid < b) res = SELECT(res, query(a, b, k * 2 + 2, mid, R));
		return res;
	}
	T query(int L, int R) {
		return query(L, R, 0, 0, N);
	}
};
#pragma endregion //segment_tree

#pragma region 
//行列の積
namespace mymat {
	LL matMOD = MOD;//初期値10^9 + 7
};
template<class T>
vector< vector<T> > operator*(vector<vector<T> >& A, vector< vector<T> >& B) {
	LL mod = mymat::matMOD;
	int R = A.size();
	int cen = A[0].size();
	int C = B[0].size();
	vector< vector<T> > ans(R, vector<T>(C, 0));
	for (int row = 0; row < R; ++row) {
		for (int col = 0; col < C; ++col) {
			for (int inner = 0; inner < cen; ++inner) {
				/*ans[row][col] = (ans[row][col] + A[row][inner]*B[inner][col])%mod;
				//ans[row][col] = (ans[row][col] + A[row][inner]*B[inner][col]);
				ans[row][col] = (ans[row][col] + mod) % mod;
				//負になるときの処理
				*/
				ans[row][col] = (ans[row][col] + A[row][inner] * B[inner][col]) % mod;
			}
		}
	}
return ans;
}

template<class T>
vector< vector<T> > powMod(const vector< vector<T> >& mat, LL N, LL mod = MOD) {
	mymat::matMOD = mod;
	int R = mat.size();
	int C = mat[0].size();
	//R==C
	vector< vector<T> > I(R, vector<T>(C, 0));//単位元
	for (int i = 0; i < R && i < C; ++i) {
		I[i][i] = 1;
	}
	if (N == 0) {
		return I;
	}
	vector< vector<T> > mul(R, vector<T>(C)), ans(R, vector<T>(C));
	ans = I;
	mul = mat;
	while (N) {
		if (N & 1) {
			ans = ans * mul;
		}
		N >>= 1;
		mul = mul * mul;
	}
	return ans;
}
#pragma endregion //行列

#pragma region
#include<time.h>
namespace TIME {

	clock_t start, end;
	void time_start() {
		start = clock();
	}
	void time_set(int t) {
		end = start + t;
	}
	bool check() {
		return clock() < end;
	}

	/*
	unsigned long long get_cycle(){
		return __rdtsc();
	}
	unsigned long long start,limit;
	void time_start(){
		start = get_cycle();
	}
	//あたいをーさぐらないとーだめー
	void time_set(unsigned long long num){limit = num;}
	bool check(){return (get_cycle() < start+limit);}
	*/
}
#pragma endregion //時間計測

#pragma region

namespace RAND {
	unsigned long xor128() {
		static unsigned long x = 123456789, y = 362436069, z = 521288629, w = 88675123;
		unsigned long t;
		t = (x ^ (x << 11)); x = y; y = z; z = w;
		return(w = (w ^ (w >> 19)) ^ (t ^ (t >> 8)));
	}
	LL getRAND(LL P) {
		return ((xor128() % P) + P) % P;
	}
}

#pragma endregion //乱数

#pragma region
#pragma endregion //
////////////////////////
//直大解説-2
void solve() {
	int N, D;
	cin >> N >> D;
	int ren = 2 * D + 1;
	int ans = (N + ren - 1) / ren;
	cout << ans << endl;
}

#pragma region main
signed main(void) {
	std::cin.tie(0);
	std::ios::sync_with_stdio(false);
	std::cout << std::fixed;//小数を10進数表示
	cout << setprecision(16);//小数点以下の桁数を指定//coutとcerrで別	

	solve();
}
#pragma endregion //main()
