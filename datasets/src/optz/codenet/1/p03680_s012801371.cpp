#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
typedef long long ll;
const int INF = 1 << 30;
const ll INFll = 1ll << 60;

int main() {
  int n;
  cin >> n;
  vector<int> A(n);
  for (int i; i < n; i++) cin >> A[i];
  int ans = -1;
  for (int curr = 1 - 1, cnt = 1, i = 0; i < n; i++, cnt++) {
    if (A[curr] - 1 == 2 - 1) {
      ans = cnt;
      break;
    }
    curr = A[curr] - 1;
  }
  cout << ans << endl;
  return 0;
}
