#include <algorithm>
#include <iostream>
using namespace std;

int main ()
{
  ios::sync_with_stdio(false);
  int N;
  int i;
  int j;
  int k;
  int count = 0;

  cin >> N;
  int a[N];
  int b[N];
  int c[N];

  for (i = 0; i < N; i++) {
    cin >> a[i];
  }
  for (i = 0; i < N; i++) {
    cin >> b[i];
  }
  for (i = 0; i < N; i++) {
    cin >> c[i];
  }

  sort(a, a + N);
  sort(b, b + N);
  sort(c, c + N);

  for (i = 0; i < N; i++) {
    for (j = 0; j < N; j++) {
      if (a[i] >= b[j]) {
        continue;
      }
      for (k = 0; k < N; k++) {
        if (b[j] < c[k]) {
          count += N-k;
          break;
        }
      }
    }
  }
  cout << count << "\n";

  return 0;
}