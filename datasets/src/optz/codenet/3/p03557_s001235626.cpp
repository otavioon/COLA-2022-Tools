// ConsoleApplication1.cpp : このファイルには 'main' 関数が含まれています。プログラム実行の開始と終了がそこで行われます。
//

#include <iostream>
#include <cmath>
#include <climits>
#include <stdio.h>
#include <stdlib.h>
#include <vector>
#include <string>
#include <stack>
#include <algorithm>
#include <map>
#include <numeric>
#include <set>
#include <queue>
#include <bitset>
using namespace std;

#define ll long long
#define ld long double
#define pi 3.14159265359;
// %llu %lf

// v:vector  type:型  order:greater(大きい順) or less(小さい順)
#define _sort(v,type,order) do { sort(v.begin(),v.end(),order<type>()); } while(0)
/*
	pairでもソートは可能 pair.first 値でのソート、pair.secondは関係ない
	vector<pair<int32_t, int32_t>> pr(4);
	sort(pr.begin(), pr.end());
*/
// vector 要素の総和算出
// v:vector  default_value:初期値
#define _sum(v,default_value) accumulate(v.begin(),v.end(),default_value )
// vector 最大値( return ite )
#define _max_element(v) max_element(v.begin(),v.end())
// vector 最小値( return ite )
#define _min_element(v) min_element(v.begin(),v.end())
// vector 最大値が格納されている要素値
#define _max_element_number(v) distance(v.begin(),max_element(v.begin(),v.end()))
// 特定コンテナの中から特定の値をカウントする
#define _count(v,value) count(v.begin(),v.end(),value)

//set<uint32_t> member;	// 重複するデータを保持する事はできない member.insert(2) member.insert(2) ⇒ member.count(2)は1
//                                                              member.emplace(2)とかも同じ member.size()で確認すると同じ値の挿入ではサイズ変化はない
//multiset<uint32_t> v;	// 重複するデータも保持する事はできる   member.insert(2) member.insert(2) ⇒ member.count(2)は2

// 丸め
#define _round(v) round(v)
// 2乗 / 3乗
#define _square(v) pow(v,2)
#define _cube(v)   pow(v,3)
// 大小判定
#define _max(x,y) max(x,y)
#define _min(x,y) min(x,y)
template <class T> inline bool chmax(T &a, T b) { if (a < b) { a = b; return true; } return false; }
template <class T> inline bool chmin(T &a, T b) { if (a > b) { a = b; return true; } return false; }

// string ⇒ int
#define _stringtoi(s) stoi(s)
// double 平方根
#define _sqrt(x) sqrt(x)
// double 引数 x 以上で最小の整数値 ex) 3.30303 ⇒ 4
#define _ceil(x) ceil(x)
// 指定された要素以上の値が現れる最初の位置のイテレータを取得する
#define _lower_bound(v,min) lower_bound(v.begin(), v.end(), min)
// 指定された要素より大きい値が現れる最初の位置のイテレータを取得する
#define _upper_bound(v,min) upper_bound(v.begin(), v.end(), min)

// 順列 n個の数が与えられる
// 0,1,2,...,n-1
// 全ての並べ方を1行ごとに出力する
// ex 0 1 2 / 0 2 1 / 1 0 2 / 1 2 0 / 2 0 1 / 2 1 0
#define _next_permutation(v) do {   \
	for (auto num : v) {            \
		printf("%d ", num);         \
	}                               \
	printf("\n");                   \
} while (next_permutation(v.begin(), v.end()))

// 絶対値
template<typename T>
static T _abs(const T x) { return  (x > 0 ? x : -x); }

// 最大公約数
int64_t gcd(int64_t a, int64_t b) { while (b) { int64_t c = b; b = a % b; a = c; } return a; }
// 最小公倍数
int64_t lcm(int64_t a, int64_t b) { if (!a || !b) return 0; return a * b / gcd(a, b); }

// 多次元 std::vector 生成
template<class T>
vector<T> make_vec(size_t a) { return vector<T>(a); }
template<class T, class... Ts>
auto make_vec(size_t a, Ts... ts) { return vector<decltype(make_vec<T>(ts...))>(a, make_vec<T>(ts...)); }
// ex) auto dp = make_vec<uint64_t>(SIZE + 1, 2, 2);

// pair
// vector<vector<pair<int32_t,int32_t>>> f(n);
// ⇒ 挿入 f[i].push_back(make_pair(x, y));

// Union Find Tree
class UnionFind
{
public:
	vector <int32_t> par; // 各元の親を表す配列
	vector <int32_t> siz; // 素集合のサイズを表す配列(1 で初期化)

	// Constructor 初期では親は自分自身
	UnionFind(int32_t sz_) : par(sz_), siz(sz_, 1LL) { for (int32_t i = 0; i < sz_; ++i) par[i] = i; }

	void init(int32_t sz_)
	{
		par.resize(sz_);
		siz.assign(sz_, 1LL);  // resize だとなぜか初期化されなかった
		for (int32_t i = 0; i < sz_; ++i) par[i] = i; // 初期では親は自分自身
	}

	// Find
	int32_t root(int32_t x)
	{
		// x の親の親を x の親とする
		while (par[x] != x) {
			x = par[x] = par[par[x]];
			//			printf("%d\n", x);
		}
		return x;
	}

	// Union(Unite, Merge)
	bool merge(int32_t x, int32_t y)
	{
		x = root(x);
		y = root(y);
		if (x == y) return false;
		// merge technique（データ構造をマージするテク．小を大にくっつける）
		if (siz[x] < siz[y]) swap(x, y);
		siz[x] += siz[y];
		par[y] = x;
		return true;
	}

	// 連結判定
	bool is_same(int32_t x, int32_t y) { return root(x) == root(y); }

	// 素集合のサイズ
	int32_t size(int32_t x) { return siz[root(x)]; }

	// 参照
	void view(void) {
		for (size_t i = 0; i < par.size(); i++) {
			printf("%d\n", par[i]);
		}
	}

};


// ■
// UINT32_MAX
// 4294967295 ≒ 4 * 1e9

// ■
// 割り算した結果との比較での丸め対処時 
// ABC 161 B
// https://atcoder.jp/contests/abc161/tasks/abc161_b
// double   border = _sum(v, 0 / (double)(4 * m);
//            ↓
// uint32_t border = (_sum(v, 0) + (4 * m) - 1) / (4 * m);


/*************************************************************/
// ABC 077
// C - Snuke Festival
// https://atcoder.jp/contests/abc077/tasks/arc084_a
/*
	■問題文
	今年もすぬけ祭の季節がやってきました。りんごさんは、まず手始めにすぬけ君召喚の儀式を執り行おうと思っています。
	儀式には祭壇が必要で、祭壇は上部、中部、下部の 3 つのカテゴリーのパーツ 1 つずつからなります。
	祭壇の 3 カテゴリーのパーツがそれぞれ N 個ずつあります。
	i 個目の上部のパーツのサイズは Ai 、i 個目の中部のパーツのサイズは Bi 、i 個目の下部のパーツのサイズは Ci です。
	祭壇を作るにあたっては、中部のパーツのサイズは上部のパーツのサイズより真に大きく、下部のパーツのサイズは中部のパーツのサイズより 真に大きくなければなりません。
	逆に、この条件を満たす任意の 3 つのピースを組み合わせて祭壇を作ることができます。
	りんごさんが作ることのできる祭壇は何種類あるでしょうか。
	ただし、2 つの祭壇が異なるとは、上部、中部、下部に使われるピースのうち 少なくとも 1 つが異なることを言います。

	■制約
	-

	■入力
	N
	A1 ... AN
	B1 ... BN
	C1 ... CN

	■出力
	りんごさんが作ることのできる祭壇の種類数を出力せよ。

	■入力例
	2
	1 5
	2 4
	3 6

	■出力例
	3

	上部に 1 個目、中部に 1 個目、下部に 1 個目のパーツを使った祭壇
	上部に 1 個目、中部に 1 個目、下部に 2 個目のパーツを使った祭壇
	上部に 1 個目、中部に 2 個目、下部に 2 個目のパーツを使った祭壇
*/


int main()
{
	int32_t n;
	cin >> n;
	vector<int32_t> a(n);
	vector<int32_t> b(n);
	vector<int32_t> c(n);

	for (int32_t i = 0; i < n; i++) {
		cin >> a[i];
	}
	for (int32_t i = 0; i < n; i++) {
		cin >> b[i];
	}
	for (int32_t i = 0; i < n; i++) {
		cin >> c[i];
	}
	_sort(a, int32_t, less);
	_sort(b, int32_t, less);
	_sort(c, int32_t, less);

	int32_t result = 0;
	for (int32_t i = 0; i < n; i++) {
		auto ite_b = _upper_bound(b, a[i]);
		for (auto _ite_b = ite_b; _ite_b != b.end(); ++_ite_b) {
			auto ite_c = _upper_bound(c, *_ite_b);
			result += distance(ite_c, c.end());
		}
	}

	cout << result << endl;
	return 0;
}

// プログラムの実行: Ctrl + F5 または [デバッグ] > [デバッグなしで開始] メニュー
// プログラムのデバッグ: F5 または [デバッグ] > [デバッグの開始] メニュー

// 作業を開始するためのヒント: 
//    1. ソリューション エクスプローラー ウィンドウを使用してファイルを追加/管理します 
//   2. チーム エクスプローラー ウィンドウを使用してソース管理に接続します
//   3. 出力ウィンドウを使用して、ビルド出力とその他のメッセージを表示します
//   4. エラー一覧ウィンドウを使用してエラーを表示します
//   5. [プロジェクト] > [新しい項目の追加] と移動して新しいコード ファイルを作成するか、[プロジェクト] > [既存の項目の追加] と移動して既存のコード ファイルをプロジェクトに追加します
//   6. 後ほどこのプロジェクトを再び開く場合、[ファイル] > [開く] > [プロジェクト] と移動して .sln ファイルを選択します
