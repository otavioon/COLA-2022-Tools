#include<iostream>
#include<fstream>
#include<sstream>
#include<algorithm>
#include<cstdio>
#include<cassert>
#include<cmath>
#include<cstdlib>
#include<cstring>
#include<string>
#include<deque>
#include<queue>
#include<vector>
#include<list>
#include<map>
#include<set>
#include<bitset>
#include<stack>
#include<iomanip>
#include<utility>
#include<functional>
using namespace std;
const long long INF=10000000009;
int n;
long long a,b;
long long h[100005];
long long h1[100005];
bool check(long long x)
{
	long long tot=0;
	for(long long i=0;i<n;i++)
		h1[i]=h[i]-x*b;
	long long a1=a-b;
	for(long long i=0;i<n;i++)
	{
		if(h1[i]<=0)
			continue;
		long long now=h1[i]/a1;
		if(h1[i]%a1!=0)
			now++;
		tot+=now;
		if(tot>x)
			return false;
	}
	if(tot>x)
		return false;
	return true;
}
int main()
{
	cin>>n>>a>>b;
	for(int i=0;i<n;i++)
		cin>>h[i];
	long long l=1,r=INF,mid;
	while(l<=r)
	{
		mid=(l+r)/2;
		if(check(mid))
			r=mid-1;
		else
			l=mid+1;
	}
	cout<<r+1;
	return 0;
}
