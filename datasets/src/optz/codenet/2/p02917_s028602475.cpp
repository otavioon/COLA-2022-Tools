#include<bits/stdc++.h>
using namespace std;
#define ll long long int
int main()
{
    ll n,i,j,x,sum=0,sum2=0,mul=1,maxi = INT_MIN;
   vector<ll>vi,vt;
   cin>>n;
   for(i = 0 ;i<n-1 ;i++)
   {
       cin>>x;
       vi.push_back(x);
   }
   vt.push_back(vi[0]);
   for(i =  0 ;i<n-2 ;i++)
   {
       vt.push_back(min(vi[i],vi[i+1]));
   }
   vt.push_back(vi[n-2]);
   for(i = 0 ;i<n ;i++)
   {
       sum+=vt[i];
   }

   cout<<sum<<endl;
}
