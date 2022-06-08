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
  int64_t s = 0;
  for (int i = 0; i < N - 1; ++i) {
    if (S[i] != S[i + 1])continue;
    ++s; ++i;
  }
  S += S;
  int64_t d = 0;
  for (int i = 0; i < 2 * N - 1; ++i) {
    if (S[i] != S[i + 1])continue;
    ++d; ++i;
  }
  S += S;
  int64_t t = 0;
  for (int i = 0; i < 3 * N - 1; ++i) {
    if (S[i] != S[i + 1])continue;
    ++t; ++i;
  }
  int64_t ans = s + (t - s) * ((K - 1) / 2) + ((K - 1) % 2 ? d - s : 0);
  cout << ans << endl;
}
