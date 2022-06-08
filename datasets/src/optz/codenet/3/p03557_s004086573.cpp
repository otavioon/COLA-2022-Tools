#include<bits/stdc++.h>
using namespace std;
#define int long long int 
int32_t main()
{
  int n;
  cin>>n;
  int a[n],b[n],c[n];
  for(int i=0;i<n;i++)
  cin>>a[i];
  for(int i=0;i<n;i++)
  cin>>b[i];
  for(int i=0;i<n;i++)
  cin>>c[i];
  sort(a,a+n);
  sort(b,b+n);
  sort(c,c+n);
  // for(auto i:a)
  // cout<<i<<" ";
  // cout<<endl;
  // for(auto i:b)
  // cout<<i<<" ";
  // cout<<endl;
  // for(auto i:c)
  // cout<<i<<" ";
  // cout<<endl;
  int ans=0;
  for(int i=0;i<n;i++)
  {
    int p=(upper_bound(b,b+n,a[i])-b);
    
    for(int j=p;j<n;j++)
    {
     int y=n-(upper_bound(c,c+n,b[j])-c);
     ans+=y;
     
    }
  
  }
  cout<<ans<<endl;
}