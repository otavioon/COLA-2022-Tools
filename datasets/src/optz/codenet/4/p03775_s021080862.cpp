//コンパイラ最適化用
#pragma GCC optimize("Ofast")
#define _GLIBCXX_DEBUG
//インクルード(アルファベット順)
#include<algorithm>//sort,二分探索,など
#include<bitset>//固定長bit集合
#include<chrono>//実行時間計測
#include<cmath>//pow,logなど
#include<complex>//複素数
#include<deque>//両端アクセスのキュー
#include<functional>//sortのgreater
#include<iomanip>//setprecision(浮動小数点の出力の誤差)
#include<iostream>//入出力
#include<iterator>//集合演算(積集合,和集合,差集合など)
#include<map>//map(辞書)
#include<numeric>//iota(整数列の生成),gcdとlcm,accumulate
#include<queue>//キュー
#include<set>//集合
#include<stack>//スタック
#include<string>//文字列
#include<unordered_map>//順序保持しないmap
#include<unordered_set>//順序保持しないset
#include<utility>//pair
#include<vector>//可変長配列
#include<bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<ll, ll> pll;
typedef pair<ll, int> pli;
typedef pair<int, int> pii;
typedef pair<ll, ld> pld;
typedef pair<pii, int> ppiii;
typedef pair<pii, ll> ppiill;
typedef pair<pll, ll> ppllll;
typedef pair<pli, int> pplii;
typedef map<int, int> mii;
typedef deque<ll> dll;
typedef queue<ll> qll;
typedef priority_queue<ll> pqll;
typedef priority_queue<ll, vector<ll>, greater<ll>> pqrll;
typedef vector<int> vint;
typedef vector<ll> vll;
typedef vector<vector<ll>> vvll;
typedef vector<vector<int>> vvint;
typedef vector<vector<pll>> vvpll;

//マクロ
//forループ
//引数は、(ループ内変数,動く範囲)か(ループ内変数,始めの数,終わりの数)、のどちらか
//Dがついてないものはループ変数は1ずつインクリメントされ、Dがついてるものはループ変数は1ずつデクリメントされる
#define REP(i,n) for(ll i=0;i<ll(n);i++)
#define REPD(i,n) for(ll i=n-1;i>=0;i--)
#define FOR(i,a,b) for(ll i=a;i<=ll(b);i++)
#define FORD(i,a,b) for(ll i=a;i>=ll(b);i--)
//xにはvectorなどのコンテナ
#define ALL(x) x.begin(),x.end() 
#define SIZE(x) ll(x.size()) 
//定数
#define INF 1000000000000 //10^12:∞
#define MOD 1000000007 //10^9+7:合同式の法
#define MAXR 100000 //10^5:配列の最大のrange
//略記
#define PB push_back //挿入
#define MP make_pair //pairのコンストラクタ
#define F first //pairの一つ目の要素
#define S second //pairの二つ目の要素
#define cin(x) cin >> x

signed main(){
    //入力の高速化用のコード
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    //入力
    ll N = 0;
    cin >> N;

    //本文
    ll  ans = 0;
    ll RN = sqrt(N);
    ll A = 0;
    for(ll i = 1; i<=RN;i++){
      if(N%i==0){
        A = i;
      }
    }
    ll B = N/A;

    ll Ac = 0, Bc = 0;
    Ac = to_string(A).size();
    Bc = to_string(B).size();
    ans = max(Ac,Bc);



    //出力
    cout << ans << endl;
    //REP(i,N) cout << ans.at(i) <<endl;
  return 0;
}