/***********************
*  Author: xuziyuan    * 
***********************/

#include <bits/stdc++.h>

#define rt0 return 0
#define rep(i,n) for(int i=0;i<n;i++)
#define repn(i,n) for(int i=1;i<=n;i++)
#define replet(c) for(char c='a';c<='z';c++)
#define LL long long
#define pii pair <int,int>
#define pb push_back
#define fi first
#define se second
#define mpr make_pair
#define sqr(a) ((a)*(a))

using namespace std;

const LL MOD=1e9+7;

LL n,a[200010],ans;
bool vis[200010];
vector <LL> pw;

int FIND(int ubb,LL targ)
{
	int lb=0,ub=ubb;
	while(lb<=ub)
	{
		int mid=(lb+ub)/2;
		if(a[mid]==targ) return mid;
		if(a[mid]>targ) ub=mid-1;
		else lb=mid+1;
	}
	return -1;
}

int main()
{
	pw.pb(1);
	repn(i,40) pw.pb(pw[i-1]*2LL);
	cin>>n;
	rep(i,n) cin>>a[i];
	sort(a,a+n);
	for(int i=n-1;i>=0;i--)
	{
		if(vis[i]) continue;
		LL sum=pw[lower_bound(pw.begin(),pw.end(),a[i])-pw.begin()];
		LL targ=sum-a[i];
		int pos=FIND(i-1,targ);
		if(pos==-1) continue;
		bool ok=false;
		for(int j=pos;j>=0&&a[j]==targ;j--)
		{
			if(!vis[j])
			{
				vis[j]=true;
				vis[i]=true;
				ans++;
				ok=true;
				break;
			}
		}
		if(!ok)
		for(int j=pos;j<n&&a[j]==targ;j++)
		{
			if(!vis[j])
			{
				vis[j]=true;
				vis[i]=true;
				ans++;
				ok=true;
				break;
			}
		}
	}
	cout<<ans<<endl;
	rt0;
}