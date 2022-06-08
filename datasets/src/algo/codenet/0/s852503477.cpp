#include<bits/stdc++.h>
using namespace std;
char t[1000];
int main()
{
	string s; long long i,x,ans;
	ans=0;
	long long k;
	cin>>s;
	for (i=0;i<s.length();i++)
	{
		t[i]=s[i];
	}
	cin>>k;
	x=s.length();
	for(i=0;i<s.length()-2;i++)
	{
		if(t[i]==t[i+1] && t[i+2]!='z' && t[i]!='z')
		{
			t[i+1]='z';
		}
		else if (t[i]==t[i+1] && t[i+2]!='y' && t[i]!='y')
		{
			t[i+1]='y';
		}
		else if(t[i]==t[i+1] && t[i+2]!='x' && t[i]!='x')
		{
			t[i+1]='x';
		}
	}
	//cout<<i<<endl;
		if(t[i]==t[i+1] && t[0]!='z' && t[i]!='z')
		{
			t[i+1]='z';
		}
		else if (t[i]==t[i+1] && t[0]!='y' && t[i]!='y')
		{
			t[i+1]='y';
		}
		else if(t[i]==t[i+1] && t[0]!='x' && t[i]!='x')
		{
			t[i+1]='x';
		}
	for (i=0;i<x;i++)
	{
		if(s[i]!=t[i])
		{
			ans++;
		}
	}
	ans=ans*k;
	if (t[x-1]==t[0])
	{
		ans+=(k-1);
	}
	cout<<ans<<endl;
}