#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define REP(i,m,n) for(int i=(int)(m); i<(int)(n); i++)
#define rep(i,n) REP(i,0,n)
#define RREP(i,m,n) for(int i=(int)(m); i>=(int)(n); i--)
#define rrep(i,n) RREP(i,n-1,0)
#define all(v) v.begin(), v.end()
const int inf = 1e9+7;
const ll longinf = 1LL<<60;
const ll mod = 1e9+7;

int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);
  int N, K;
  cin >> N >> K;
  set<int> se;
  rep(i, 10) se.insert(i);
  rep(i, K) {
    int d;
    cin >> d;
    se.erase(d);
  }
  auto check = [&](int n) {
    while(n > 0) {
      if(!se.count(n%10)) return false;
      n /= 10;
    }
    return true;
  };
  while(true) {
    if(check(N)) {
      cout << N << "\n";
      return 0;
    }
    N++;
  }
  return 0;
}
