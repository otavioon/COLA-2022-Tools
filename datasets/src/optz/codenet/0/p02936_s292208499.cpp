#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define REP(i,m,n) for(int i=(int)(m); i<(int)(n); i++)
#define rep(i,n) REP(i,0,n)
const int inf = 1e9+7;
const ll longinf = 1LL<<60;
const ll mod = 1e9+7;

ll find_next(vector<int>& v, ll tmp, int n) {
  vector<int>::iterator itr = lower_bound(v.begin(), v.end(), tmp%n+1);
  return tmp + (*itr - tmp % n);
}

int main() {
  string s, t;
  cin >> s >> t;
  string s2 = s + s;
  int n = s.size();
  vector<vector<int> > A(26);
  rep(i, s2.size()) {
    A[int(s2[i] - 'a')].push_back(i);
  }
  ll tmp = -1;
  rep(i, t.size()) {
    if(A[int(t[i] - 'a')].size() == 0) {
      cout << -1 << endl;
      return 0;
    }
    tmp = find_next(A[int(t[i] - 'a')], tmp, n);
  }
  if(tmp < 1e+100 * n)
    cout << tmp + 1 << endl;
  else
    cout << -1 << endl;
  return 0;
}

