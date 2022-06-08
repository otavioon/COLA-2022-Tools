#include <iostream>
using namespace std;

const int NMAX = 100000;
long sx[NMAX];


int main() {
  long n, a, b;
  cin >> n >> a >> b;
  long diff = a-b;
  long sum = 0;
  long s;
  for (int i = 0; i < n; i++) {
    cin >> s;
    sum += s;
    sx[i] = s;
  }
  // cout << sum << endl;
  long l = 1;
  long r = sum+1;
  long mid;
  while (r-l > 1) {
    mid = (l+r)/2;
    // cout << l << ' ' << r << endl;
    int cnt = 0;
    for (int i = 0; i < n; i++) {
      int res = sx[i] - b*mid;
      if (res > 0) {
	cnt += res / diff + 1;
	// cout << res << ' ';
      }
    }
    // cout << endl;
    // cout << cnt << endl;
    if (cnt <= mid) {
      r = mid;
    }
    else {
      l = mid;
    }
  }
  cout << mid << endl;
}