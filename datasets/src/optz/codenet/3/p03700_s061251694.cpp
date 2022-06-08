#include<iostream>
#include<algorithm>
using namespace std;
int N_MAX=100000;
int main()
{
  int n,a,b,l,r,c,t,i;
  int h[N_MAX];
  cin >> n >> a >> b;
  for(i=0;i<n;i++)
    cin >> h[i];
  sort(h,h+n,greater<int>());
  l=(h[0]+a-1)/a;
  r=(h[0]+b-1)/b;
  while(l<r){
    c=(l+r)/2;
    t=0;
    for(i=0;i<n;i++){
      t+=max(0,(h[i]-b*c+a-b-1)/(a-b));
      if(t>c)
        break;
    }
    if(t<=c)
      r=c;
    else
      l=c+1;
  }
  cout << l << endl;
  return 0;
}