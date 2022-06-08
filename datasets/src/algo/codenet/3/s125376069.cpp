#include <vector>
#include <queue>
#include <algorithm>
#include <iostream>
#include <string>
#include <tuple>
#include <set>
#include <map>
#include <unordered_map>
#include <complex>
#include <iomanip>
#include <cmath>
using namespace std;
typedef long long ll;

int main()
{
  int n;
  cin >> n;
  ll a[n], b[n], c[n];
  for (int i = 0; i < n; i++) cin >> a[i];
  for (int i = 0; i < n; i++) cin >> b[i];
  for (int i = 0; i < n; i++) cin >> c[i];
  sort(a, a + n);
  sort(b, b + n);
  sort(c, c + n);
  ll ans = 0;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      if (b[j] >= c[i]) break;
      for (int k = 0; k < n; k++) {
        if (a[k] >= b[j]) break;
        ans++;
      }
    }
  }
  cout << ans << endl;
}
