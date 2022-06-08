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

int n,ans=0;
multiset <int> s;

int main()
{
	cin>>n;
	rep(i,n)
	{
		int x;
		scanf("%d",&x);
		s.insert(x);
	}
	while(!s.empty())
	{
		multiset <int>::iterator it=s.end();
		it--;
		s.erase(it);
		int pw=1;
		for(;pw<=*it;pw*=2);
		if(s.find(pw-*it)!=s.end())
		{
			s.erase(s.find(pw-*it));
			ans++;
		}
	}
	cout<<ans<<endl;
	rt0;
}