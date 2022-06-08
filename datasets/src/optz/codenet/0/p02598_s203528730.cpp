#include<bits/stdc++.h>
#include <map>
#include <set>
#include <cmath>
#include <queue>
#include <cstdio>
#include <vector>
#include <climits>
#include <cstring>
#include <cstdlib>
#include <iostream>
#include <algorithm>
using namespace std;
const int N=1e5+10;
#define ll long long
#define inf 0x3f3f3f3f
#define mem(x) memset(x,0,sizeof(x))
#define sca(x) scanf("%d",&x)
#define scall(x) scanf("%lld",&x)
#define eps 1e-6
int a[200005];
int n,k;
bool check(int x)
{
	int sum=0;
	for(int i=1;i<=n;i++)
	{
		if(a[i]>x)
		{
			sum+=(a[i]/x);
			if(a[i]%x)
			sum++;
			sum--;
			if(sum>k)
			return false;
		}
	}
	if(sum>k)
	return false;
	return true;
}
int main()
{
	sca(n);sca(k);
	for(int i=1;i<=n;i++)
	sca(a[i]);
	int minn=inf,maxn=0;
	for(int i=1;i<=n;i++)
	{
		minn=min(minn,a[i]);
		maxn=max(maxn,a[i]);
	}
	int l=1,r=maxn;
	while(l<r)
	{
		int mid=(l+r)/2;
		//cout<<mid<<"判断结果"<<check(mid)<<endl;
		if(check(mid))
		r=mid;
		else
		l=mid+1;
	}
	cout<<l<<endl;
}