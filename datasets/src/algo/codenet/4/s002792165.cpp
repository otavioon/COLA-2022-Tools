#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
  int N, K;
  cin >> N >> K;
  set<int> dislike;
  for (int i = 0; i < K; i++) {
    int num;
    cin >> num;
    dislike.insert(num);
  }
  int ans;
  for (int i = N; i < 1000000; i++) {
    bool can = true;
    int tmp = i;
    if (dislike.count(tmp%10)) can = false;
    while (tmp > 9) {
      tmp /= 10;
      int tmp2 = tmp % 10;
      if (dislike.count(tmp2)) can = false;
    }
    if (can) {
      ans = i;
      break;
    }
  }
  cout << ans << endl;
}
