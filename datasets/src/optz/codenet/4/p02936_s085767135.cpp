#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
typedef long double ld;
typedef vector<ll> vl;
typedef vector<string> vs;
typedef vector<char> vc;
typedef queue<ll> ql;
typedef deque<ll> dql;
typedef priority_queue<ll, vl/*, greater<ll>*/> pql; //降順(/*昇順*/)
typedef set<ll> sl;
#define rep(i, n) for(ll i = 0; i < ll(n); ++i)
#define rep2(i, n) for(ll i = 1; i <= ll(n); ++i)
//#define rep(i, k, n) for(ll i = k-1; i < ll(n); ++i)
//#define rep2(i, k, n) for(ll i = k; i <= ll(n); ++i)
#define all(v) (v).begin(), (v).end()
bool chmin(ll &a, ll &b) {if(b < a) {a = b; return 1;} return 0;}
bool chmax(ll &a, ll &b) {if(b > a) {a = b; return 1;} return 0;}
const ll INF = 1LL << 60;
const ll MOD = 1e9 + 7;
//const ll MOD = 998244353;
const ll MAX = 2e5;
ll num=1, ans=0, cnt=0, sum=0;

sl point[MAX+1], subtree[MAX+1];

void dfs(ll p) {
  subtree[p].insert(p);
  for(ll i: point[p]) {
    point[i].erase(p);
    dfs(i);
    for(ll j: subtree[i]) subtree[p].insert(j);
  }
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  
  ll N, Q;
  cin >> N >> Q;
  
  rep(i, N-1) {
    ll a, b;
    cin >> a >> b;
    point[a].insert(b);
    point[b].insert(a);
  }
  
  dfs(1);
  
  vl counter(N+1);
  rep(i, Q) {
    ll p, x;
    cin >> p >> x;
    for(ll j: subtree[p]) counter[j] += x;
  }
  
  rep2(i, N-1) cout << counter[i] << " ";
  cout << counter[N];
  return 0;
}