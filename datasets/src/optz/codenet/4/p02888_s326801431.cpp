#include <bits/stdc++.h>
#include <cstdlib> // abs(x-y)
#include <iomanip> // 出力の桁数指定
#define rep(i, s, n) for (int i = (s); i < (int)(n); i++) // repマクロ

using namespace std;

int main() {
  int n;
  cin >> n;
  vector<int> l(n);
  rep (i, 0, n)
    cin >> l.at(i);
  int ans = 0;
  
  rep (i, 0, n) {
    rep (j, i+1, n) {
      rep (k, j+1, n) {
        if ( (l.at(i) + l.at(j) - l.at(k) > 0) and (l.at(j) + l.at(k) - l.at(i) > 0) and (l.at(k) + l.at(i) - l.at(j) > 0) )
          ans++;
      }
    }
  }
  cout << ans << endl;
}