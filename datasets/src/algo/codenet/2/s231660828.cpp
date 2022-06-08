//#include <bits/stdc++.h>
#include <cstdio>
#include <algorithm>
#include <iostream>
#include <cstring>
#include <limits>
#include <map>
#include <vector>
#include <queue> 
#define P pair<int ,int >
#define pb push_back
#define LL long long
#define ft first
#define sd second
#define mp(x,y) make_pair(x,y)
#define db double
//#define int LL
using namespace std;
const int N   = 2e5+233;
//const int mod = ;
const int INF =numeric_limits<int >::max();

#define rep(i,x,y) for (int i=x;i<=y;++i)
void read(int &x)
{
	x=0;
	char ch=getchar();
	int f=1;
	while (!isdigit(ch)) (ch=='-'?f=-1:0),ch=getchar();
	while ( isdigit(ch)) x=x*10+ch-'0',ch=getchar();
	x*=f;
}
int n,a[N],ans;
int vis[N];
signed main()
{
	read(n);
	rep(i,1,n) read(a[i]);
	sort(a+1,a+1+n);
	for (LL k=1ll<<30;k>=1;k>>=1)
	  	  {
	  	  	if (k==16)
	  	  	{
	  	  		++k;--k;;
	  	  	}
	  	  	int r=n;
	  	  		rep(i,1,n) if (!vis[i])
	  			{	
	  				while (r>i&&(vis[r] ||a[i]+a[r]>k) ) --r;
	  				
	  				if (!vis[r]&&r>i&&a[i]+a[r]==k ) 
	  				{
	  					vis[r]=vis[i]=1;
	  					++ans;
	  				}
	  			}	
	  	  }
	printf("%d",ans);
	return 0;
}

    