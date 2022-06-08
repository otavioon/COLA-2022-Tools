#include<bits/stdc++.h>
using namespace std;
int main()
{
	string s;cin>>s;int len=s.length();int ans=0;long long k;cin>>k;
	if(s[0]!=s[len-1])
	{
		int id=0;int tmp=0;
		while(id<len)
		{
			tmp=1;
			while(id<len-1&&s[id]==s[id+1]) id++,tmp++;
			ans+=(tmp/2);
			id++;
		}
		cout<<1ll*ans*k<<endl;
	}
	else
	{
		int id=0;int tmp=1;int a=1,b=1;
		while(id<len-1&&s[id]==s[id+1]) id++,a++;
		id++;//cout<<id<<" "<<a<<endl;
		if(id==len)
		{
			cout<<(1ll*len*k)/2<<endl;
			return 0;
		}
		while(id<len)
		{
			tmp=1;
			while(id<len-1&&s[id]==s[id+1]) id++,tmp++;
			if(id==len-1)
			{
				b=tmp;
			}
			else ans+=(tmp/2);
			id++;
		}
		cout<<1ll*ans*k+1ll*(a+b)/2*(k-1)<<endl;
	}
 } 