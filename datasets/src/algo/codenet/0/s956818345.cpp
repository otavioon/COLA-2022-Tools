// Copyright 2019 yaito3014
#include "bits/stdc++.h"
using namespace std;
using namespace literals;

int main() {
  cin.tie(0); ios::sync_with_stdio(0);
  string S;
  cin >> S;
  int K;
  cin >> K;
  int N = S.length();
  int64_t ans = 0;
  for (int i = 0; i < N - 1; ++i) {
    if (S[i] != S[i + 1])continue;
    if (i == 0 && S.front() == S.back()) {
      S[i] = 1; ++ans;
    }
    else {
      S[i + 1] = 1;
      ++ans; ++i;
    }
  }
  ans *= K;
  if (S.front() == S.back())
    ans += K-1;
  cout << ans << endl;
}
