#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
typedef pair<int,long> P;
int main(void){
  int n,i,j,a[100010],b[100010],c[100010],t,bs[100010],bn[100010],bg[100010];
  long ans=0;
  cin >> n;
  for (i=0;i<n;i++) cin >> a[i];
  for (i=0;i<n;i++) cin >> b[i];
  for (i=0;i<n;i++) cin >> c[i];
  sort(a,a+n,greater<int>());
  sort(b,b+n,greater<int>());
  sort(c,c+n,greater<int>());
  i=t=0;
  while (i<n){
    bn[t]=1;
    bs[t]=b[i];
    while (i<n && b[i]==b[i+1]){
      i++;
      bn[t]++;
    }
    t++;
    i++;
  }
  j=0;
  for (i=0;i<t;i++){
    while (bs[i]<=a[j]) j++;
    bg[i]=(n-j)*bn[i];
  }
  for (i=t-2;i>=0;i--) bg[i]+=bg[i+1];
  j=0;
  for (i=0;i<n;i++){
    while (c[i]<=bs[j]) j++;
    ans+=bg[j];
  }
  cout << ans << endl;
  return 0;
}