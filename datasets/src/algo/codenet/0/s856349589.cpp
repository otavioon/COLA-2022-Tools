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
		else if(t[i]==t[i+1] && t[i+2]!='w' && t[i]!='w')
		{
			t[i+1]='w';
		}
	}
	//cout<<i<<endl;
		if(t[x-2]==t[x-1] && t[0]!='z' && t[x-1]!='z')
		{
			t[x-1]='z';
		}
		else if(t[x-2]==t[x-1] && t[0]!='y' && t[x-1]!='y')
		{
			t[x-1]='y';
		}
		else if(t[x-2]==t[x-1] && t[0]!='x' && t[x-1]!='x')
		{
			t[x-1]='x';
		}
		else if(t[x-2]==t[x-1] && t[0]!='w' && t[x-1]!='w')
		{
			t[x-1]='w';
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