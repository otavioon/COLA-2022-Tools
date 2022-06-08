#include <iostream>
using namespace std;
int main() {
  int n, b0, b = 0;
  long long ans = 0;
  cin >> n;
  cin >> b0;
  b = b0;
  ans += b0;
  for (int i = 1; i < n - 1; ++i) {
    cin >> b;
    ans += min(b0, b);
    b0 = b;
  }
  ans += b;
  cout << ans << endl;
  return 0;
}
