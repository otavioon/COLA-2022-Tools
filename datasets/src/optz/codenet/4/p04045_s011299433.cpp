#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>
using namespace std;

int main() {
  int N, K, i, n, count, Ntmp;
  bool flag = false;
  cin >> N >> K;
  vector<int> D(K);
  vector<int> num(10 - K);
  for (i = 0; i < K; i++) cin >> D[i];
  Ntmp = n = N;
  count = 0;
  i = 2;
  while (1) {
    while (n >= 0) {
      // 入力されたDの中に、n%10がなかった場合count++する
      if (find(D.begin(), D.end(), n % 10) == D.end()) {
        // countがDと同じ大きさになった時点で発見
        if (++count == D.size()) {
          flag = true;
          break;
        }
      }
      if (n == 0) break;
      n /= 10;
    }
    // flagが立っていたらbreak
    if (flag) break;
    Ntmp = n = N * i++;
  }
  cout << Ntmp << endl;
}