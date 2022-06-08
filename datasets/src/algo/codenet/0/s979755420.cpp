#include <bits/stdc++.h>
using namespace std;

int main() {
  string S;
  int K;
  cin >> S >> K;
  
  int64_t ans = 0;
  int n = S.size();
  
  //最初と最後が同じときその範囲を調べる
  int roop_s = n - 1, roop_e = 0;
  if (S.at(0) == S.at(n - 1)) {
    for (int i = 0; i < n; i++) {
      if (S.at(0) == S.at(i)) {
        roop_e = i;
      } else {
        break;
      }
    }
    for (int i = n - 1; i >= 0; i--) {
      if (S.at(n - 1) == S.at(i)) {
        roop_s = i;
      } else {
        break;
      }
    }
    //ansへの処理
    if (roop_e == n - 1) {
      ans = (int64_t)n * K / 2;
    } else {
      //初め、最後、それ以外を足す
      ans += (roop_e + 1) / 2;
      ans += (n-1 - roop_s + 1) / 2;
      ans += (((int64_t)n + roop_e + 1) - roop_s) / 2 * (K - 1);
    }
  } else {
    roop_s = n;
    roop_e = -1;
  }
  
  //roopの範囲外で調べる
  //roop_e == n - 1のとき調べない
  int64_t eqc_n = 1;
  
  if (roop_e == n - 1) {
  } else {
    char prev = S.at(roop_e + 1);
    for (int i = roop_e + 2; i < roop_s; i++) {
      char cuc = S.at(i);
      if (cuc == prev) {
        eqc_n++;
      } else {
        ans += eqc_n / 2 * K;
        eqc_n = 1;
      }
      if (i == roop_s - 1) {
        ans += eqc_n / 2 * K;
      }
      prev = cuc;
    }
  }
  
  cout << ans << endl;
}
