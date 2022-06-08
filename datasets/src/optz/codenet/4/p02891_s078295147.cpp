#include<bits/stdc++.h>
using namespace std;
string s,t;
long long ans,ls,ll,hh,p,h1,h2;
long long tt;
int main()
{
	cin>>s>>p;
	ls=s.size();
	if(ls==1)
	{
		cout<<p/2;
		return 0;
	}
	for(int i=1;i<ls;i++)
	if(s[i]!=s[i-1])
	{
		tt=i;
		break;
	}
	if(tt==ls-1)
	{
		cout<<ls*p/2;
		return 0;
	}
	t=s+s;
	hh=1;
	for(int i=tt+1;i<tt+ls;i++)
	{
		if(s[i]==s[i-1])
		hh++;
		else
		{
			ans+=hh/2;
			hh=1;
		}
	}
	ans+=hh/2;
	ans=ans*p;
	h1=1;
	for(int i=1;s[i]==s[i-1];i++)
	h1++;
	for(int i=ls-1;s[i]==s[i-1];i--)
	h2++;
	if((h1+h2)/2!=h1/2+h2/2)
	ans--;
	cout<<ans;
	return 0;
}