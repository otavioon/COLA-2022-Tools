#include<bits/stdc++.h>

using namespace std;

int main(){
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n;
  cin >> n;
  int a[n], b[n], c[n];
  for(int i=0; i<3; i++){
    for(int j=0; j<n; j++){
      if(i==0){
        cin >> a[j];
      }else if(i == 1){
        cin >> b[j];
      }else
        cin >> c[j];
    }
  }
  sort(a, a+n);
  sort(b, b+n);
  sort(c, c+n);
  long long ans = 0;
  int j=0, k=0;
  for(int i=0; i<n; i++){
    while(a[j] < b[i] && j < n) j++;
    while(c[k] <= b[i] && k < n) k++;
    ans += 1ll * j * (n - k);
  }
  cout << ans << endl;
  return 0;
}
