#include<bits/stdc++.h>
using namespace std;
#define N 100005
#define INF 1<<30
#define LL long long

LL n,a,b;
LL h[N];

bool ok(LL x)
{
	LL sum=0;
	for(int i=0;i<n;i++)
		if(h[i]-x*b>0) sum+=(h[i]-x*b+a-b-1)/(a-b);
	if(sum>x) return 0;
	return 1;
}

int main()
{
	
	cin>>n>>a>>b;
	for(int i=0;i<n;i++)
		cin>>h[i];
	
	LL l=0,r=INF,mid;
	while(l<=r)
	{
		mid=(l+r)/2;
		if(ok(mid)) r=mid-1;
		       else l=mid+1;
	}
	if(ok(mid)) cout<<mid<<'\n';
	       else cout<<mid+1<<'\n';
	
	return 0;
}