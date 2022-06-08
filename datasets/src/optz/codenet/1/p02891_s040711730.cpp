#include <iostream>
#include <cstring>
using namespace std;

long long n,k;
char s[105]; 
bool flag[105];
int main()
{
	cin>>s;
	cin>>k;
	n=strlen(s);
	long long ans=0;
	bool flg=true;
	for(int i=1;i<n;i++)
	{
		if(s[i]==s[i-1]&&flag[i-1]==false)
			ans+=k,flag[i]=true;
		if(s[i]!=s[i-1])
			flg=false;
	}
	if(flag[n-1]!=true&&s[n-1]==s[0])
	{
		ans+=k-1;
		flag[0]=true;
		for(int i=1;i<n;i++)
		{
			if(s[i]==s[i-1]&&flag[i-1]==true&&flag[i]==true)
				ans-=k/2,flag[i]=false;
			if(s[i]==s[i-1]&&flag[i-1]==false&&flag[i]==false)
				ans+=k/2,flag[i]=false;
		}
	}
	if(flg)
	{
		cout<<n*k/2<<endl;
		return 0;
	}
	cout<<ans<<endl;
	return 0;
}
