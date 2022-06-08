#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll, ll> P;
#define DUMP(x)  cout << #x << " = " << (x) << endl;
#define FOR(i, m, n) for(ll i = m; i < n; i++)
#define IFOR(i, m, n) for(ll i = n - 1; i >= m; i-- )
#define REP(i, n) FOR(i,0,n)
#define IREP(i, n) IFOR(i,0,n)
#define FOREACH(x,a) for(auto& (x) : (a) )
#define ALL(v) (v).begin(), (v).end()
#define SZ(x) ll(x.size())

int main(){
  ll n; cin >> n;
  multiset<ll> st, power;
  REP(i,n){
    ll a; cin >> a;
    st.insert(a);
  }
  ll cur = 2;
  const ll MAX = 2e9;
  while(cur<MAX){
    power.insert(cur);
    cur *= 2;
  }

  ll ans = 0;
  while(!st.empty()){
    auto it = prev(st.end());
    ll now = *it;
    st.erase(it);
    ll target = *power.upper_bound(now) - now;
    it = st.find(target);
    if(it==st.end()) continue;
    ans++;
    st.erase(it);
  }
  cout << ans << endl;
}