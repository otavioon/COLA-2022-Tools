#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
typedef vector<ll> vl;
typedef set<ll> sl;
#define rep(i, n) for(ll i = 0; i < ll(n); ++i)
#define rep2(i, n) for(ll i = 1; i <= ll(n); ++i)
const ll MAX = 2e5;

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
  
  vl counter(N+1), root_of_cnt(N+1);
  rep(i, Q) {
    ll p, x;
    cin >> p >> x;
    root_of_cnt[p] += x;
  }
  rep2(i, N) for(ll j: subtree[i]) counter[j] += root_of_cnt[i];
  
  rep2(i, N) cout << counter[i] << " ";
  return 0;
}