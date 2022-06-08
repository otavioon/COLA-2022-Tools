#include <bits/stdc++.h>
using namespace std;

int main() {

  int N;
  cin >> N;

  vector<int> count(N);
  vector<int> a(N);
  for (int i = 0; i < N; i++) {
    cin >> a[i];
  }

  bool flg = true;
  int current = 0;
  int answer = 0;

  while (flg) {
    int v_ = a[current] - 1;
    if (count[v_] == 0) {
      answer++;
      count[current]++;
      current = v_;
      if (v_ == 1){
        flg = false;
      }
    } else {
      flg = false;
      answer = -1;
    }
  }

  cout << answer << endl;

}