#include<bits/stdc++.h>
using namespace std;
bool mincut(vector<int> &a,double x,int k)
{
	int k1;
  	for(auto y:a)
    {
      k1 = floor((y-1)/x);
      k-=k1;
    }
  return k>=0;
}
int main()
{
  long long int n,k;
  cin>>n>>k;
  vector<int> v(n);
  for(int i=0;i<n;i++)
    cin>>v[i];
  long long int l=0,r=1000000001,m;
  while(l<r-1)
  {
    m = (l+r-1)/2;
    if(mincut(v,m,k))
      r = m;
    else
    {
      l = m;
    }
  }
  cout<<r;
  return 0;
}