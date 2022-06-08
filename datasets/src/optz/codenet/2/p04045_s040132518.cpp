#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll INF = 1e11;

int N, K;
vector<int> D;

bool check(int m) {
  string s = to_string(m);
  for (int s_num = 0; s_num < s.size(); s_num++) {
    for (int d_num = 0; d_num < D.size(); d_num++) {
      if (s[s_num] - '0' == D[d_num]) {
        return false;
      }
    }
  }
  return true;
}

void abc042c() {
  for (int i = N; i <= 999999; i++) {
    if (check(i)) {
      cout << i << "\n";
      return;
    }
  }
}

int main() {
  cin >> N >> K;
  D.resize(K);
  for (int i = 0; i < K; i++) {
    cin >> D[i];
  }
  abc042c();
  return 0;
}