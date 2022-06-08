/**
 *  @author: pr4shan7 (प्रशांत)
 */
#include <bits/stdc++.h>
using namespace std;

// #define _DEBUG

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

#ifdef _DEBUG
  ifstream cin("input.txt");
  ofstream cout("output.txt");
#endif

  string s;
  cin >> s;
  long long k;
  cin >> k;

  int d1 = 1, d2 = 0, d3 = 1, d4 = 0;
  bool b = false;
  int i = 0;
  for (; i < s.length() - 1; i++) {
    if (s[i] == s[i + 1])
      d1++;
    else {
      i++;
      break;
    }
  }
  // i++;
  int j = s.length() - 1;
  for (; j > 0; j--) {
    if (s[j] == s[j - 1])
      d3++;
    else {
      j--;
      break;
    }
  }
  if (j == 0) b = true;

  long long res = 0;
  int temp = 0;
  for (; i < j; i++) {
    if (s[i] == s[i + 1])
      temp++;
    else if (temp) {
      d2 += (temp + 1) / 2;
      temp = 0;
    }
  }
  if (temp) {
    d2 += (temp + 1) / 2;
  }

  if (s[0] == s[s.length() - 1]) d4 = d1 + d3;

  if (!b and d4)
    res = k * d2 + (k - 1) * (d4 / 2) + d1 / 2 + d3 / 2;
  else if (d4 == 0) {
    res = k * d2 + k * (d1 / 2 + d3 / 2);
  }
  // cout << d1 << ' ' << d2 << ' ' << d3 << ' ' << d4 << ' ' << res << '\n';

  if (b and (s.length() & 1)) {
    if (k & 1)
      cout << (k / 2 + 1) * (s.length() / 2) + (k / 2) * (s.length() / 2 + 1) << '\n';
    else
      cout << (k / 2) * (s.length() / 2) + (k / 2) * (s.length() / 2 + 1) << '\n';
  } else if (b)
    cout << k * s.length() / 2 << '\n';
  else
    cout << res << '\n';
  return 0;
}
