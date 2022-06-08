#include <iostream>
#include <string>
#include <cmath>
#include <vector>
#include <algorithm>
using namespace std;
#define rep(i, n) for(int i = 0; i < n; ++i)
typedef long long ll;

int main()
{
	ll N;cin>>N;
	ll b=N;
	vector<ll> pf;
	
	for(ll i=2;i*i<=N;++i)
	{
		while(b%i==0)
		{
			b=b/i;
			pf.push_back(i);
		}
	}
	
	if(b!=0)pf.push_back(b);
	
	ll a=1;
	b=1;
	sort(pf.begin(),pf.end());
	for(int i=pf.size()-1;0<=i;--i)
	{
		if(a<b)a=a*pf[i];
		else b=b*pf[i]; 
	}
	
	//cout<<a<<":"<<b<<endl;

	int ans1=0;
	while(a!=0)
	{
		a=a/10;
		ans1++;
	}
	int ans2=0;
	while(b!=0)
	{
		b=b/10;
		ans2++;
	}
	int ans=(ans1>ans2)?ans1:ans2;
	cout<<ans<<endl;
	return 0;
}