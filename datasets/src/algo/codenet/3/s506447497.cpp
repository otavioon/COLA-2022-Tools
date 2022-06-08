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
  int tmpj = 0, tmpk = 0;
  int flag1 = 0, flag2 = 0;
  for (int i = 0; i != n; ++i) {
    tmpk = 0;
    flag1 = 0;
    for (int j = tmpj; j != n; ++j) {
      flag2 = 0;
      if (a[i] < b[j]) {
	if (flag1 == 0) {
	  tmpj = j;
	  flag1 = 1;
	}
	for (int k = tmpk; k != n; ++k){
	  if (b[j] < c[k]) {
	    if (flag2 == 0) {
	      tmpk = k;
	      flag2 = 1;
	    }
	    ans += n - k;
	    break;
	  }
	}
      }
    }
  }
  cout << ans;
  return 0;
}
