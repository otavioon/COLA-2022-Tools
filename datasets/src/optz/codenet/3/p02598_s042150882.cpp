#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<n;i++)
#define repn(i,n) for(int i=1;i<=n;i++)
#define LL long long
#define pii pair <int,int>
#define fi first
#define se second
#define pb push_back
#define mpr make_pair

using namespace std;

const LL MOD=1e9+7;

LL n,k;
double a[200010];

LL get(double x)
{
	double y=(LL)x;
	if(x-y>y+1-x) return (LL)y;
	return (LL)(y+1);
}

LL f(double x,LL y)
{
	if((double)y>=x) return 0;
	int r=(LL)x/y;
	for(LL i=max(0,r-3);i<=r+3;i++)
	{
		double res=(i==0 ? x:x/(i+1));
		//cout<<i<<' '<<res<<' '<<(LL)res<<endl;
		if((LL)(res+0.5)<=y) return i; 
	} 
}

bool check(LL mid)
{
	LL lft=k;
	rep(i,n) lft-=f(a[i],mid);//,cout<<a[i]<<' '<<mid<<' '<<f(a[i],mid)<<endl;
	return lft>=0;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>k;
	rep(i,n) cin>>a[i];
	LL lb=0,ub=1e9,mid;
	while(lb<ub)
	{
		mid=(lb+ub)/2;//cout<<lb<<' '<<ub<<' '<<mid<<endl;
		if(check(mid)) ub=mid;
		else lb=mid+1;
	}
	cout<<lb<<endl;
	//cout<<check(292638192);
	//f(9,4);
	return 0;
}