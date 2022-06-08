#include<bits/stdc++.h>
using namespace std;
#define ll long long
int main()
{

	ios_base::sync_with_stdio(0);
	cout.tie(0);
	cin.tie(0);

	#ifndef ONLINE_JUDGE
    freopen("input.txt" , "r" , stdin);
	freopen("output.txt" , "w" , stdout);
	#endif

	string s;
	cin>>s;
	ll k,ans=0,c=1,n,f=0;
	cin>>k;
	n=s.length();
	for(ll i=1;i<n;i++)
	{
		if(s[i]==s[i-1])
			c++;
		else
		{
			ans+=c/2;
				c=1;
		}
		if((i==n-1))
		{
			ans+=c/2;
			if((s[0]==s[n-1])&&(c%2))
			{
				ans+=1;
				f=1;
			}
		}
	}
	if(f)
	cout<<ans*k-1<<endl;
    else
	cout<<ans*k<<endl;

	
	
}
