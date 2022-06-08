#include "bits/stdc++.h"
//#include <intrin.h>  //AtCoder (gcc) 上ではこれがあると動かない。__popcnt用のincludeファイル。
using namespace std;

typedef long long ll;
typedef long double ld;


#define int long long
#define rep(i, n) for(long long i = 0; i < (n); i++)
#define sqrt(d) pow((long double) (d), 0.50)

const int INF = 2000000000; //2e9
const long long INF2 = 1000000000000000000; //1e18
const long double PI = acos(-1);

const int large_P = 1000000007; //1e9 + 7
//const int large_P = 1000000009; //1e9 + 9
//const int large_P = 998244353;



//繰り返し2乗法
//N^aの、Mで割った余りを求める。
ll my_pow(ll N, ll a, ll M) {
	ll tempo;
	if (a == 0) {
		return 1;
	}
	else {
		if (a % 2 == 0) {
			tempo = my_pow(N, a / 2, M);
			return (tempo * tempo) % M;
		}
		else {
			tempo = my_pow(N, a - 1, M);
			return (tempo * N) % M;
		}
	}
}




//N_C_a を M で割った余り
ll my_combination(ll N, ll a, ll M) {
	ll answer = 1;

	rep(i, a) {
		answer *= (N - i);
		answer %= M;
	}

	rep(i, a) {
		answer *= my_pow(i + 1, M - 2, M);
		answer %= M;
	}

	return answer;
}


//N_C_i を M で割った余りを、v.at(i) に代入する。
void my_combination_table(ll N, ll M, vector<ll>& v) {
	v.assign(N + 1, 1);

	for (int i = 1; i <= N; i++) {
		v.at(i) = v.at(i - 1) * (N - (i - 1));
		v.at(i) %= M;

		v.at(i) *= my_pow(i, M - 2, M);
		v.at(i) %= M;
	}
}



ll factorial(ll x, vector<ll>& dp) {
	if (x == 0) return dp.at(x) = 1;
	if (dp.at(x) != -1 && dp.at(x) != 0) return dp.at(x);
	return dp.at(x) = x * factorial(x - 1, dp);
}




ll my_gcd(ll& a, ll& b) {
	if (b == 0) return a;
	ll temp = a % b;
	return my_gcd(b, temp);
}




// base を底としたときの、n の i桁目を、v.at(i) に入れる。(桁数は n に応じて自動で設定する。)
void ll_to_vector(signed base, long long n, deque<signed>& v) {
	long long tempo = n;
	long long tempo2 = n;

	signed n_digit = 1;
	while (tempo2 >= 10LL) {
		tempo2 /= 10LL;
		n_digit++;
	}

	v.assign(n_digit, 0);

	//ll n_digit = v.size();  // v のサイズをそのままにする場合。

	for (signed i = 0; i < n_digit; i++) {
		v.at(i) = tempo / (ll)pow(base, n_digit - 1 - i);
		tempo -= v.at(i) * (ll)pow(base, n_digit - 1 - i);
	}
}




int char_to_int(char c) {
	switch (c) {
	case '0': return 0; case '1': return 1; case '2': return 2; case '3': return 3; case '4': return 4;
	case '5': return 5; case '6': return 6; case '7': return 7; case '8': return 8; case '9': return 9;
	default: return 0;
	}
}




//エラトステネスの篩で、prime で ないところに false を入れる。
//true で初期化された vector を代入する必要がある。
void prime_judge(vector<bool>& prime_or_not) {

	prime_or_not.at(0) = false;
	prime_or_not.at(1) = false;

	ll n = prime_or_not.size() - 1;
	ll region = (ll)sqrt(n) + 1;

	for (ll i = 2; i <= n / 2; i++) {
		prime_or_not.at(2 * i) = false;
	}


	for (ll i2 = 1; i2 < n / 2; i2++) {
		ll i = 2 * i2 + 1;  //ここからは奇数のみ探索
		if (i < region && prime_or_not.at(i)) {
			ll j = i * i;
			while (j < n + 1) {
				prime_or_not.at(j) = false;
				j += 2 * i;
			}
		}
	}
};




map<ll, ll> divide_to_prime(int target) {
	map<ll, ll> res;

	//sqrt(target) まで調べる。
	ll upper_lim = ceil(sqrt(target));
	vector<bool> prime_or_not(upper_lim + 1, true);

	if (upper_lim < 20) prime_or_not.assign(25, true);
	prime_judge(prime_or_not);

	ll tempo = target;
	rep(i, (upper_lim + 1)) {
		if (prime_or_not.at(i)) {
			while (tempo % i == 0) {
				tempo /= i;
				res[i]++;
			}
		}
	}

	if (tempo != 1) res[tempo]++; //sqrt(target) より大きな素因数は高々1つしかない。



	return res;
}




void BFS_labyrinth(queue<pair<int, int>>& que, vector<vector<int>>& dist, int& area) {
	int n = dist.size();
	int m = dist.at(0).size();

	while (!que.empty()) {
		int h, w;
		pair<int, int> tempo = que.front(); que.pop();

		h = tempo.first;
		w = tempo.second;
		//cout << temp_i << " " << temp_j << endl;

		for (int dh = -1; dh <= 1; dh++) {
			for (int dw = -1; dw <= 1; dw++) {
				if (h + dh < 0 || n <= h + dh) continue;  //範囲外
				if (w + dw < 0 || m <= w + dw) continue;  //範囲外
				if (dh == 0 && dw == 0) continue; //動いていない
				if (dh * dw != 0) continue; //右上など。八近傍の場合は消す。
				if (dist.at(h + dh).at(w + dw) != -1) continue; //行けない領域に、既に INF などが代入されている場合はこの条件だけで ok

				dist.at(h + dh).at(w + dw) = dist.at(h).at(w) + 1;
				que.push(make_pair(h + dh, w + dw));
			}
		}

		//何か所も領域がある場合だけ必要
		if (que.empty()) {
			rep(i, n) {
				rep(j, m) {
					if (dist.at(i).at(j) == -1) {
						que.push(make_pair(i, j));
						dist.at(i).at(j) = 0;
						area++;
						break;
					}
				}
				if (!que.empty()) break;
			}
		}
	}
}




void BFS01_labyrinth(deque<pair<int, int>>& que, vector<vector<int>>& dist, vector<vector<int>>& cost) {
	int n = dist.size();
	int m = dist.at(0).size();

	while (!que.empty()) {
		int h, w;
		pair<int, int> tempo = que.front(); que.pop_front();

		h = tempo.first;
		w = tempo.second;
		//cout << temp_i << " " << temp_j << endl;

		for (int dh = -1; dh <= 1; dh++) {
			for (int dw = -1; dw <= 1; dw++) {
				if (h + dh < 0 || n <= h + dh) continue;  //範囲外
				if (w + dw < 0 || m <= w + dw) continue;  //範囲外
				if (dh == 0 && dw == 0) continue; //動いていない
				if (dh * dw != 0) continue; //右上など。八近傍の場合は消す。
				if (dist.at(h + dh).at(w + dw) != -1) continue; //行けない領域に、既に INF などが代入されている場合はこの条件だけで ok

				dist.at(h + dh).at(w + dw) = dist.at(h).at(w) + cost.at(h + dh).at(w + dw);

				if (cost.at(h + dh).at(w + dw) == 0) {//コストが低い場合
					que.push_front(make_pair(h + dh, w + dw));
				}
				else {//コストが高い場合
					que.push_back(make_pair(h + dh, w + dw));
				}

			}
		}
	}
}




void dfs(const vector<vector<int>>& G, vector<bool>& seen, int v) {
	seen.at(v) = true;

	for (int next_v : G.at(v)) {
		if (seen.at(next_v)) continue;
		dfs(G, seen, next_v);
	}
}



class edge {
public:
	int to;
	int cost;
};

void dijkstra(int s, const vector<vector<edge>> G, vector<int>& dist) {
	int V = dist.size(); //頂点数
	dist.assign(V, INF);

	//first が最短距離、second が頂点番号。
	priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> que;
	dist.at(s) = 0; que.push(make_pair(0, s));

	while (!que.empty()) {
		pair<int, int> p = que.top(); que.pop();
		int v = p.second;
		if (dist.at(v) < p.first) continue;  //最短距離がすでに更新されているので無視。

		for (int i = 0; i < G.at(v).size(); i++) {
			edge e = G.at(v).at(i);
			//for (auto&& e : G.at(v)) {  // ← なぜか、やや遅いので。
			if (dist.at(e.to) > dist.at(v) + e.cost) {
				dist.at(e.to) = dist.at(v) + e.cost;
				que.push(make_pair(dist.at(e.to), e.to));
			}
		}
	}
}

const int Vmax2 = 1;
int dp_warshall[Vmax2][Vmax2];

//G.at(i).at(j) は i から j への移動コスト。隣接行列。
void warshall_floyd(int V, const vector<vector<int>> G) {
	rep(i, V) {
		rep(j, V) {
			dp_warshall[i][j] = G.at(i).at(j);  //初期化
		}
	}

	rep(k, V) {
		rep(i, V) {
			rep(j, V) {
				dp_warshall[i][j] = min(dp_warshall[i][j], dp_warshall[i][k] + dp_warshall[k][j]);
			}
		}
	}
}




class UnionFind {
public:
	vector<int> parent;
	vector<int> rank;

	UnionFind(int N) : parent(N), rank(N, 0) {
		rep(i, N) {
			parent.at(i) = i;
		}
	}

	int root(int x) {
		if (parent.at(x) == x) return x;
		return parent.at(x) = root(parent.at(x));
	}

	void unite(int x, int y) {
		int rx = root(x);
		int ry = root(y);

		if (rx == ry) return; //xの根とyの根が同じなので、何もしない。
		if (rank.at(rx) < rank.at(ry)) {
			parent.at(rx) = ry;
		}
		else {
			parent.at(ry) = rx;
			if (rank.at(rx) == rank.at(ry)) rank.at(rx)++;
		}
	}

	bool same(int x, int y) {
		return (root(x) == root(y));
	}


};




class wUnionFind {
public:
	vector<int> parent;
	vector<int> diff_weight; //親との差分。
	vector<int> rank;

	wUnionFind(int N) : parent(N), diff_weight(N, 0), rank(N, 0) {
		rep(i, N) {
			parent.at(i) = i;
		}
	}

	int root(int x) {
		if (parent.at(x) == x) return x;

		int r = root(parent.at(x));
		diff_weight.at(x) += diff_weight.at(parent.at(x)); //累積和
		return parent.at(x) = r;
	}

	//x の重みを出力する関数。
	int weight(int x) {
		root(x);
		return diff_weight.at(x);
	}

	//weight.at(y) - weight.at(x) == w となるようにする。
	bool unite(int x, int y, int w) {
		int rx = root(x);
		int ry = root(y);
		int diff_weight_to_ry_from_rx = w + weight(x) - weight(y);

		if (rx == ry) return false; //xの根とyの根が同じなので、何もしない。
		if (rank.at(rx) < rank.at(ry)) {
			parent.at(rx) = ry;
			diff_weight.at(rx) = -diff_weight_to_ry_from_rx;
		}
		else {
			parent.at(ry) = rx;
			diff_weight.at(ry) = diff_weight_to_ry_from_rx;
			if (rank.at(rx) == rank.at(ry)) rank.at(rx)++;
		}

		return true;
	}

	bool same(int x, int y) {
		return (root(x) == root(y));
	}


};



//転倒数を返す (comp = less<int>() の場合)。
//comp = greater<int>() の場合は、N_C_2 - 転倒数 を返すことになる。
int my_merge(vector<int>& A, vector<int>& B, int left, int mid, int right, function <bool(int, int)> comp) {
	int i = left; //Aを分割したときの、左側の配列を差す配列。
	int j = mid;  //Bを分割したときの、左側の配列を差す配列。
	int k = 0;  //分割した後の配列 (一時的に) B に保存。

	int res = 0;

	while (i < mid && j < right) {
		if(comp(A.at(i), A.at(j))) B.at(k++) = A.at(i++);
		else {
			B.at(k++) = A.at(j++);
			res += mid - i;
		}
	}

	//左側をBに移動し尽くしたので、右側を順に入れていく。
	if (i == mid) {
		while (j < right) {
			B.at(k++) = A.at(j++);
		}
	}
	else { //右側をBに移動し尽くしたので、左側を順に入れていく。
		while (i < mid) {
			B.at(k++) = A.at(i++);
		}
	}

	//Aに値を戻す。
	rep(l, k) {
		A.at(left + l) = B.at(l);
	}

	return res;
}


int my_merge_sort(vector<int>& target, vector<int>& tempo, int left, int right, function <bool(int, int)> comp) {

	int mid, res = 0;
	if (left == right || left == right - 1) return res;

	mid = (left + right) / 2;
	res += my_merge_sort(target, tempo, left, mid, comp);
	res += my_merge_sort(target, tempo, mid, right, comp);
	res += my_merge(target, tempo, left, mid, right, comp);
	return res;
}




signed main() {
	int N, K;
	cin >> N >> K;
	
	vector<int> D(K);
	rep(i, K) cin >> D.at(i);
	//sort(D.begin(), D.end());

	vector<bool> judge(10, true);
	rep(i, K) {
		judge.at(D.at(i)) = false;
	}

	vector<int> ok;
	rep(i, 10) {
		if (judge.at(i)) ok.push_back(i);
	}

	
	deque<signed> v;
	ll_to_vector(10, N, v);

	
	for (int i = v.size() - 1; i >= 1; i--) {
		if (v.at(i) == 10) {
			v.at(i) = 0;
			v.at(i - 1)++;
		}

		while (!judge.at(v.at(i))) {
			if(v.at(i) != 9) v.at(i)++;
			else {
				v.at(i) = 0;
				v.at(i - 1)++;
			}
		}
	}

	
	if (v.at(0) == 10) {
		v.push_front(1);
		v.at(1) = 0;
	}

	while (v.at(0) < 9 && !judge.at(v.at(0))) {
		v.at(0)++;
	}
	
	if (v.at(0) == 9 && !judge.at(v.at(0))) {
		v.push_front(1);
		v.at(1) = 0;
	}

	while (!judge.at(v.at(1))) {
		v.at(1)++;
	}
	while (!judge.at(v.at(0))) {
		v.at(0)++;
	}


	rep(i, v.size()) {
		cout << v.at(i);
	}
	cout << endl;


	rep(i, 10 - K) {
		//cout << ok.at(i) << endl;
	}
}