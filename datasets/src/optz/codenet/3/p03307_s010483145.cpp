#include <iostream>
#include <cstdlib>
#include <algorithm>
using namespace std;

int main()
{
  int n=0,ans=0;
  cin >> n;
  long long int a[n], temp=0, b;
  for(int i=0;i<n;++i){
    cin >> a[i];
    a[i] = a[i] - (i+1);
    temp += a[n];
  }
  sort(a, a+n);
  if(n%2==0){
    b = (a[(n/2)-1]+a[(n/2)])/2;
    int tmpans=0;
    for(int i=0;i<n;i++){
      tmpans+=abs(a[i]-b);
    }
    if(b<0) b--;
    else b++;
    for(int i=0;i<n;i++){
      ans+=abs(a[i]-b);
    }
    if(ans>tmpans) ans=tmpans;
  }else{
    b = a[int(n/2)];
    for(int i=0;i<n;++i){
      ans += abs(a[i]-b);
    }
  }
  cout << ans << endl;
  return 0;
}