#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;

int main() {
  string S;
  cin >> S;
  ll K;
  cin >> K;
  if (K <= 2) {
    if (K == 2) S = S + S;
    int ans = 0;
    for (int i = 1; i < S.size(); i++) {
      if (S[i] == S[i - 1]) {
        ans++, i++;
      }
    }
    cout << ans << endl;
    return 0;
  }

  int N = S.size();
  S = S + S + S;
  ll ans = 0, ans1 = 0, ans2 = 0;
  for (int i = 1; i < S.size(); i++) {
    if (S[i] == S[i - 1]) {
      ans++;
      if (N <= i && i <= 2 * N - 1) {
        ans1++;
      } else if (2 * N <= i) {
        ans2++;
      }
      i++;
    }
  }
  // cout << ans << ans1 << ans2 << K / 2 << (K - 1) / 2 << endl;
  cout << (ans - ans1 - ans2) + ans1 * (K / 2) + ans2 * ((K - 1) / 2) << endl;
}