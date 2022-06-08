#pragma region Macros
#include <bits/stdc++.h>

#define FOR(i, a, b) for (int i = (a); i < (b); ++i)
#define REP(i, n) FOR(i, 0, n)
#define ALL(a) (a).begin(), (a).end()
#define SZ(x) ((int)(x).size())
#define IN(x, a, b) x >= a and x < b

using namespace std;
using ll = long long;

template <class T> bool chmax(T &a, const T &b) {
  if (a < b) {
    a = b;
    return 1;
  }
  return 0;
}
template <class T> bool chmin(T &a, const T &b) {
  if (b < a) {
    a = b;
    return 1;
  }
  return 0;
}
template <typename T> constexpr T INF = numeric_limits<T>::max() / 2;
#pragma endregion

int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);

  string s;
  cin >> s;
  ll k = 0;
  cin >> k;
  ll n = SZ(s);
  ll ans = 0;
  if (n == 1) {
    ans = k / 2;
  } else if (n == 2) {
    if (s[0] == s[1]) {
      ans = k;
    }
  } else {
    string s2;
    if (k == 1) {
      s2 = s;
    } else {
      s2 = s + s;
    }
    ll l = 0;
    ll r = 0;
    ll i = 0;
    while (i < SZ(s2) - 2) {
      if (s2[i] == s2[i + 1] and s2[i + 1] == s2[i + 2]) {
        s2[i + 1] = '0';
        if (i + 1 < n) {
          l++;
        } else {
          r++;
        }
        i++;
      } else if (s2[i + 1] == s2[i + 2] and i == SZ(s2) - 3) {
        r++;
        i++;
      } else if (s2[i] == s2[i + 1]) {
        s2[i] = '0';
        if (i < n) {
          l++;
        } else {
          r++;
        }
        i++;
      } else {
        i++;
      }
    }
    if (k == 1) {
      ans = l + r;
    } else {
      if (k % 2 == 0) {
        ans = (l + r) * (k / 2);
      } else {
        ans = l * ((k + 1) / 2) + r * (k / 2);
      }
    }
  }

  cout << ans << endl;

  return 0;
}