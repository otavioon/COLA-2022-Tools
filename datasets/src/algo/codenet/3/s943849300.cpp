#include <iostream>
#include <algorithm> 
using namespace std;

int main ()
{
  int n;
  cin >> n;
  int a[n], b[n], c[n];
  for (int i = 0; i != n; ++i) {
    cin >> a[i];
  }
  for (int i = 0; i != n; ++i) {
    cin >> b[i];
  }
  for (int i = 0; i != n; ++i) {
    cin >> c[i];
  }
  sort(a, a+n);
  sort(b, b+n);
  sort(c, c+n);
  int ans;
  for (int i = 0; i != n; ++i) {
    for (int j = 0; j != n; ++j) {
      if (a[i] < b[j]) {
	for (int k = 0; k != n; ++k){
	  if (b[j] < c[k]) {
	    ans += 1;
	  }
	}
      }
    }
  }
  cout << ans;
  return 0;
}
