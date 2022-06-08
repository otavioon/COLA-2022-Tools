// C++ 14
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define loop(__x, __start, __end) for(ll __x = __start; __x < __end; __x++)


int main() {
  set<char> S;
  int n, k;
  cin >> n >> k;
  loop(i,0,k) {
    int a; cin >> a;
    S.insert((char)(a+'0'));
  }
  
  loop(x,n,100 * n) {
    string s = to_string(x);
    bool ok = true;
    for (auto &&c: s) ok &= S.count(c) == 0;
    if (ok) {
      cout << x << endl;
      return 0;
    }
  }
  cout << -1 << endl;
  return 0;
}
