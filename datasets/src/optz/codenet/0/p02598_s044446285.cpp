#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ld  = long double;
using pll = pair<ll, ll>;
using pld = pair<ld, ld>;
const int INF=1e9+7;
const ll LINF=9223372036854775807;
const ll MOD=1e9+7;
const ld PI=acos(-1);
const ld EPS = 1e-10; //微調整用（EPSより小さいと0と判定など）

int ii() { int x; if (scanf("%d", &x)==1) return x; else return 0; }
long long il() { long long x; if (scanf("%lld", &x)==1) return x; else return 0; }
string is() { string x; cin >> x; return x; }
char ic() { char x; cin >> x; return x; }
void oi(int x) { printf("%d ", x); }
void ol(long long x) { printf("%lld ", x); }
void od_nosp(double x) { printf("%.15f", x); } // 古い問題用
void od(double x) { printf("%.15f ", x); }
// long doubleで受け取り、fをLfなどに変えて出力すると、変な数値が出る
// それをなんとかするには独自の出力を作らなければならなそう
void os(const string &s) { printf("%s ", s.c_str()); }
void oc(const char &c) { printf("%c ", c); }
#define o_map(v){cerr << #v << endl; for(const auto& xxx: v){cout << xxx.first << " " << xxx.second << "\n";}} //動作未確認
void br() { putchar('\n'); }

// #define gcd __gcd //llは受け取らない C++17~のgcdと違うので注意
// int lcm(int a, int b){return a / gcd(a, b) * b;}
#define begin_end(a) a.begin(),a.end() //sort(begin_end(vec));
#define REP(i,m,n) for(ll i=(ll)(m) ; i < (ll)(n) ; i++ )
#define DREP(i,m,n) for(ll i=(ll)(m) ; i > (ll)(n) ; i-- )
#define rep(i,n) REP(i,0,n)
#define m_p(a,b) make_pair(a,b)
#define SORT_UNIQUE(c) (sort(c.begin(),c.end()), c.resize(distance(c.begin(),unique(c.begin(),c.end()))))
#define GET_POS(c,x) (lower_bound(c.begin(),c.end(),x)-c.begin())
#define p_b push_back
#define SZ(x) ((int)(x).size) //size()がunsignedなのでエラー避けに


// coutによるpairの出力（空白区切り）
template<typename T1, typename T2> ostream& operator<<(ostream& s, const pair<T1, T2>& p) {return s << "(" << p.first << " " << p.second << ")";}
// coutによるvectorの出力（空白区切り）
template<typename T> ostream& operator<<(ostream& s, const vector<T>& v) {
  int len = v.size();
  for (int i = 0; i < len; ++i) {
    s << v[i]; if (i < len - 1) s << " "; //"\t"に変えるとTabで見やすく区切る
  }
  return s;
}
// coutによる多次元vectorの出力（空白区切り）
template<typename T> ostream& operator<<(ostream& s, const vector< vector<T> >& vv) {
  int len = vv.size();
  for (int i = 0; i < len; ++i) {
    s << vv[i] << endl;
  }
  return s;
}

//最大値、最小値の更新。更新したor等しければtrueを返す
template<typename T>
bool chmax(T& a, T b){return (a = max(a, b)) == b;}
template<typename T>
bool chmin(T& a, T b){return (a = min(a, b)) == b;}

//4近傍（上下左右） rep(i, 2) にすると右・下だけに進む
vector<int> dx_4 = {1, 0, -1, 0};
vector<int> dy_4 = {0, 1, 0, -1};

// -------- template end - //


// - library ------------- //


ll N, K;
// 昇順ソートされている
vector<ll> as;

// 決め打ち二分探索 with めぐる式二分探索

// ゼロ除算エラーの対策をしていないので注意
// 関数の引数の評価順序が未規定のため、ceil_divide(ii(), ii())はNG
ll ceil_divide(ll a, ll b) {
  return (a + b - 1) / b;
}

// 評価関数
// K 回以内のカット数で、全てkey（整数）以下の長さにできるかどうか
bool canMake(ll key){
  if (key == 0) return false;
  // key <= 1 の場合
  ll need = 0; // 各木をkey以下の長さにするために必要な手数を足していく
  for (ll a : as){
    // a を key以下の長さにするためには、 ceil(a/key)等分する必要がある = ceil(a/key)-1回 切る必要がある
    // a < key の場合も、+= 0 なので問題無い
    need += ceil_divide(a, key) - 1;
  }
  if (need <= K) return true;
  else return false;
}

// 答えを key としたときに、問題が求める条件を満たせるかどうか
bool isOK(ll key) {
  // okを適当に大きめの値に設定した場合、配列外参照やコーナーケースに注意

  if (canMake(key)){
    return true;
  }
  else{
    return false;
  }

}

// 汎用的な二分探索のテンプレ
ll BinarySearch() {
  ll ng = 0; //「index = 0」が条件を満たすこともあるので、初期値は -1
  ll ok = as[0]; // K=0の場合こうなる
  // okは"1つも満たさない"場合があることに注意して設定。ex) = (ll)vec.size();
  // 二分探索はO(logN)なので大きめでもいいが、配列外参照やコーナーケースは注意

  // ok と ng のどちらが大きいかわからないことを考慮
  while (abs(ok - ng) > 1) {
    ll mid = (ok + ng) / 2;

    if (isOK(mid)) ok = mid;
    else ng = mid;
  }
  return ok;
}

// --------- library end - //


int main(){

  cin >> N >> K;
  rep(i, N){
    as.push_back(il());
  }
  sort(begin_end(as));
  reverse(begin_end(as));

  // 決め打ちにぶたん
  // 問題文では「小数点以下」と言っているが、これは結局「決め打ちにぶたんの key は整数のみ考えればよい」と言い換えられるので、決め打ちにぶたんは整数で行う
  cout << BinarySearch() << endl;


}