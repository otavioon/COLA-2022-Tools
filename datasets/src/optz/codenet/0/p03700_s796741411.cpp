#include <bits/stdc++.h>
#define rep(i, n) for (int i=0; i<(int)(n); i++)
#define all(v) v.begin(), v.end()
#define allR(v) v.rbegin(), v.rend()
#define PRINT(v) for (auto x : (v)) cout <<x <<" " ; cout <<endl;
using namespace std;
using ll = long long;
using Graph = vector<vector<int>>;
typedef pair<int,int> Pi;
const ll MOD = 1000000007;
const ll INF = 10000000000000000;
const int inf = 1001001001;
vector<int> x4 = {0, 1, 0, -1}, x8 = {0, 1, 1, 1, 0, -1, -1, -1};
vector<int> y4 = {1, 0, -1, 0}, y8 = {1, 1, 0, -1, -1, -1, 0, 1};
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
void hey(){ cout <<"hey" <<endl; }

template<class T> struct edge { int to; T cost;};


bool check(ll x, int N, vector<ll> &h, ll A, ll B){
  // 爆発をx回で全員殺せるか
  ll times = 0;
  ll C = A-B;
  rep(i, N){
    if (h[i] <= x * B) continue; // こいつを中心に爆発させる必要はない
    ll sub = h[i] - x*B; // こいつを中心に爆撃
    times += (sub + C - 1) / C;
  }
  return times <= x;
}

int main() {
  int N; ll A,B; cin >>N >>A >>B;
  vector<ll> h(N); rep(i, N) cin >>h[i];
  int ok = 1000000000, ng = 0;
  while (abs(ok-ng) > 1){
    int mid = (ok + ng) / 2;
    if (check(mid, N, h, A, B)) ok = mid;
    else ng = mid;
  }
  int res = ok;
  cout <<res <<endl;
}
