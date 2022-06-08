#include <bits/stdc++.h>
#define ll long long
using namespace std;

ll n,a[100001],b[100001],c[100001];

int main(){
  cin >> n;
  for(int i=0;i<n;i++) cin >> a[i];
  for(int i=0;i<n;i++) cin >> b[i];
  for(int i=0;i<n;i++) cin >> c[i];

  sort(a,a+n);
  sort(b,b+n);
  sort(c,c+n);

  ll ans = 0;
  for(int i=0;i<n;i++){
    int b_pos = 0;
    while(a[i]>=b[b_pos]){
      b_pos++;
      if(b_pos == n){
        cout << ans << endl;
        return 0;
      }
    }
    int c_pos = 0;
    for(int j=b_pos;j<n;j++){
        while(b[j]>=c[c_pos]){
          c_pos++;
          if(c_pos == n){
            cout << ans << endl;
            return 0;
          }
        }
        ans += n-c_pos;
    }
  }
  cout << ans << endl;
  return 0;
}
