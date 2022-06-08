#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
typedef vector<ll> vl;
typedef set<ll> sl;
#define rep(i, n) for(ll i = 0; i < ll(n); ++i)
#define rep2(i, n) for(ll i = 1; i <= ll(n); ++i)
const ll MAX = 2e5;

sl point[MAX+1];
vl counter(MAX+1), root_of_cnt(MAX+1);

void dfs(ll p) {
  counter[p] += root_of_cnt[p];
  for (ll i: point[p]) {
    point[i].erase(p);
    counter[i] = counter[p];
    dfs(i);
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
  
  rep(i, Q) {
    ll p, x;
    cin >> p >> x;
    root_of_cnt[p] += x;
  }
  
  dfs(1);
  
  rep2(i, N) cout << counter[i] << " ";
  return 0;
}