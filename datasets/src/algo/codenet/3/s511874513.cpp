#include <bits/stdc++.h>
using namespace std;

int main() {
  int n, tim = 1, cou = 1, sum = 0;
  cin >> n;
  int a[n], b[n], c[n];
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }
  sort(a, a + n);
  for (int i = 0; i < n; i++) {
    cin >> b[i];
  }
  sort(b, b + n);
  for (int i = 0; i < n; i++) {
    cin >> c[i];
  }
  sort(c, c + n);

  int u = 0;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      if (a[i] < b[j]) {
        for (int k = 0; k < n; k++) {
          if (b[j] < c[k]) {
            sum += n - k;

            break;
          }
        }
      }
    }
  }
  cout << sum << endl;
  return 0;
}
