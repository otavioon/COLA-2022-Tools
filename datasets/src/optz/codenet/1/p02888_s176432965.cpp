#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int mod=1e9+7;
int m,n,vis[2005],yy[2005],hh[2005]; 

int main()
{
    std::ios::sync_with_stdio(0); std::cin.tie(0);
    cin>>m;
    for(int i=0;i<m;++i)
    {
    	cin>>n;
    	vis[n]++;
	}
	for(int i=1;i<=2000;++i)
	{
		yy[i]=yy[i-1]+min(vis[i],1);
		hh[i]=hh[i-1]+vis[i];
	}
	ll sum=0;
	for(int i=1;i<=999;++i)
	 {if(!vis[i]) continue;
	 for(int j=i+1;j<=1000;++j)
	 {
	 	if(!vis[j]) continue; 
		sum+=yy[i+j-1]-yy[j];
	 }} 
	 for(int i=1;i<=1000;++i)
	 {
	 	if(vis[i]==2) sum+=hh[2*i-1]-2;
	 	if(vis[i]>=3) sum+=vis[i]*(vis[i]-1)*(vis[i]-2)/6+(vis[i]*(vis[i]-1)/2)*(hh[2*i-1]-vis[i]);
	 }
	 cout<<sum;
	return 0;
}