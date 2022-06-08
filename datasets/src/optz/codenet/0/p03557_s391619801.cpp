#include <bits/stdc++.h>
#define rep(i, n) for (int i=0; i<(int)(n); i++)
#define all(v) v.begin(), v.end()
using namespace std;
using ll = long long;
using Graph = vector<vector<int>>;
const ll MOD = 1000000007;
const ll INF = 10000000000000000;
vector<int> x4 = {0, 1, 0, -1}, x8 = {0, 1, 1, 1, 0, -1, -1, -1};
vector<int> y4 = {1, 0, -1, 0}, y8 = {1, 1, 0, -1, -1, -1, 0, 1};
template<class T> struct edge { int from, to; T cost;};
template<class T> inline bool chmin(T& a, T b){if (a>b){a = b; return true;}return false;}
template<class T> inline bool chmax(T& a, T b){if (a<b){a = b; return true;}return false;}
template<class T> inline T powerM(T a,T b){if (b==0) return 1;
T tmp = powerM(a,b/2); if (b%2==0) return tmp*tmp%MOD; else return tmp*tmp%MOD*a%MOD; }
template<class T> inline T power(T a,T b,T m){ if (b==0) return 1;
  T tmp = power(a,b/2,m); if (b%2==0) return tmp*tmp%m; else return tmp*tmp%m*a%m; }
template<class T> inline T gcd(T a, T b){if (b==0) return a; return gcd(b, a%b);}
template<class T> inline T lcm(T a, T b){return a / gcd(a,b) * b;}
// ax+by=gcd(a,b)を解く
template<class T> inline T extgcd(T a,T b,T &x,T &y){if (b==0){x=1; y=0; return a;} T d=extgcd(b,a%b,y,x); y -= a/b*x; return d;}


int main() {
  int n; cin >>n;
  vector<int> a(n),b(n),c(n);
  rep(i, n) cin >>a.at(i); rep(i, n) cin >>b.at(i); rep(i, n) cin >>c.at(i);
  sort(all(a)); sort(all(b)); sort(all(c));
  vector<int> ba(n),cb(n);
  // ba[i]...a[j]<b[i]となるjの数。広義単調増加
  // cb[i]...b[j]<c[i]となるjの数。広義単調増加
  rep(i, n){
    int tmp = lower_bound(all(b), c[i]) - b.begin();
    cb[i] = tmp;
  }
  rep(i, n){
    int tmp = lower_bound(all(a), b[i]) - a.begin();
    ba[i] = tmp;
  }
  vector<int> basum(n+1); // ba[i]の累積和
  rep(i, n) basum[i+1] = basum[i] + ba[i];
  ll res = 0;
  rep(i, n){
    int x = cb[i];
    if (x < 1) continue;
    // このときc[i]より小さい値はb[0]～b[x]となる
    // つまりba[0]～ba[x]を全て足したい
    res += basum[x];
  }
  cout <<res <<endl;
}
