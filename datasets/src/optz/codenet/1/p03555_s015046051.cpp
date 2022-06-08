#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;


int main() {
  vector<char> a(3);
  vector<char> b(3);
  rep(i,3) cin >> a[i];
  rep(i,3) cin >> b[i];
  bool ans = false;
  if(a[0] == b[2] && a[1] == b[1] && a[2] == b[0]) ans = true;
  if(ans) cout << "YES" << endl;
  else cout << "NO" << endl;
  return 0;
}