#include <bits/stdc++.h>
using namespace std;

long long n,a[100001],b[100001],c[100001];
int main(){
  cin >> n;
  for(int i=0;i<n;i++) cin >> a[i];
  for(int i=0;i<n;i++) cin >> b[i];
  for(int i=0;i<n;i++) cin >> c[i];
  sort(a,a+n);
  sort(b,b+n);
  sort(c,c+n);

  int ans = 0, b_pos = 0, c_pos = 0;
  for(int i=0;i<n;i++){
    while( a[i] >= b[b_pos] && b_pos < n ) b_pos++;
    if( b_pos == n ) break;
    c_pos = 0;
    for( int j=b_pos;j<n;j++){
      while( b[j] >= c[c_pos] ) c_pos++;
      if( c_pos == n ) break;
      ans += n-c_pos;
    }
    if( b_pos==n || c_pos==n ) break;
  }
  cout << ans << endl;
  return 0;
}
