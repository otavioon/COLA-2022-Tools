#include <bits/stdc++.h>
using namespace std;
 
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define int long long

const int N=2e5+5;

int n, ans=0;
int a[N];
map<int, int> m;

int32_t main()
{
	IOS;
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		m[a[i]]++;
	}
	for(int i=32;i>=0;i--)
	{
		for(auto &it:m)
		{
			int other=(1LL<<i)-it.first;
			if(other==it.first)
			{
				int take=it.second/2;
				it.second%=2;
				ans+=take;
				continue;
			}
			if(m.find(other)!=m.end())
			{
				int take=min(it.second, m[other]);
				ans+=take;
				it.second-=take;
				m[other]-=take;
			}
		}
	}
	cout<<ans;
	return 0;
}