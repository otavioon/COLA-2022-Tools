#include<iostream>
#include<algorithm>
using namespace std;

int main() {
  int n;
  cin >> n;
  int a[n],b[n],c[n];
  for(int i = 0; i < n; i++) {
    cin >> a[i];
  }
  for(int i = 0; i < n; i++) {
    cin >> b[i];
  }
  for(int i = 0; i < n; i++) {
    cin >> c[i];
  }
  sort(a,a+n);
  sort(b,b+n);
  sort(c,c+n);
  long long int J = 0;
  long long int K = 0;
  long long int ans = 0;
  long long int tmp = 0;
  for(int i = 0; i < n; i++) {
    bool pre = true;
    ans += tmp;
    for(int j = J; j < n; j++) {
      if(b[j] >= c[i]) {
        break;
      }
      pre = false;
      J = j + 1;
      for(int k = K; k < n; k++) {
        if(a[k] >= b[j]) break;
        K = k+1;
      }
      tmp += K;
      ans += K;
    }
  }
  cout << ans << endl;

}
