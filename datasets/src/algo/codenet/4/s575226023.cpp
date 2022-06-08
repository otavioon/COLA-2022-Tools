#include <bits/stdc++.h>
using ll = long long;
#define FOR(i, k, n) for(ll i = (k); i < (n); i++)
#define FORe(i, k, n) for(ll i = (k); i <= (n); i++)
#define FORr(i, k, n) for(ll i = (k)-1; i > (n); i--)
#define FORre(i, k, n) for(ll i = (k)-1; i >= (n); i--)
#define REP(i, n) FOR(i, 0, n)
#define REPr(i, n) FORre(i, n, 0)
#define ALL(x) (x).begin(), (x).end()
#define ALLr(x) (x).rbegin(), (x).rend()
#define chmin(x, y) x = min(x, y)
#define chmax(x, y) x = max(x, y)
using namespace std;

const int INF = 1001001001;

int main(void){
  ll n, k;
  cin >> n >> k;
  set<int> st;
  REP(i, k){
    int d;
    cin >> d;
    st.insert(d);
  };
  FORe(i, n, 100000){
    string s = to_string(i);
    int m = s.size();
    bool ok = true;
    REP(i, m) if(st.count(s[i]-'0')) ok = false;
    if(ok){
      cout << i << endl;
      return 0;
    }
  }
  
  return 0;
}