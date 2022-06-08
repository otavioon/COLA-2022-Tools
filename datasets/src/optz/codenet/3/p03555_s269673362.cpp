#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main(){
  int n;cin>>n;
  vector<int> a(n),b(n),c(n);
  for(int i = 0; n > i; i++)cin>>a[i];
  for(int i = 0; n > i; i++)cin>>b[i];
  for(int i = 0; n > i; i++)cin>>c[i];
  sort(a.begin(),a.end());
  sort(b.begin(),b.end());
  sort(c.begin(),c.end());
  long long ans = 0;
  for(int i = 0; n > i; i++){
    
    auto y = upper_bound(a.begin(),a.end(),b[i]-1);
    auto z = lower_bound(c.begin(),c.end(),b[i]+1);
    ans += (y-a.begin()) * (c.end()-z);
  }
  cout << ans << endl;
}
    