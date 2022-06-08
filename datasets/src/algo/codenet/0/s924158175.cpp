#include <iostream>
#include <string>
using namespace std;
typedef long long ll;
int main() {
  ll k, l, cnt, a[100], ans = 0LL;
  string s;
  cin >> s >> k;
  l = s.length();
  cnt = 0LL;
  for (int i = 0; i < l; i++) {
    if (s[i] == s[0]) {
      cnt++;
    }
  }
  if (cnt == l) {
    cout << l * k / 2LL << endl;
    return 0;
  }
  for (ll i = 0LL; i < l; i++) {
    if (i == 0) {
      a[i] = 0;
    } else if (s[i] == s[i - 1]) {
      a[i] = a[i - 1];
    } else {
      a[i] = i;
      if (a[i - 1] != 0 || s[0] != s[l - 1]) {
        ans += (i - a[i - 1]) / 2LL * k;
      } else {
        ans += i / 2LL;
      }
    }
  }
  if (s[l - 1] == s[0]) {
    ans += (l - a[l - 1]) / 2LL;
    cnt = 0LL;
    for (int i = 0; i < l; i++) {
      if (a[i] == 0 || a[i] == a[l - 1]) {
        cnt++;
      }
    }
    ans += cnt / 2LL * (k - 1LL);
  } else {
    ans += (l - a[l - 1]) / 2LL * k;
  }
  cout << ans << endl;
}