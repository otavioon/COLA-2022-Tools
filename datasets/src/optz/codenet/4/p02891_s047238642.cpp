#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<cmath>
#include<iostream>
#include<algorithm>
using namespace std;
char s[110];
long long k;
char tot='0';
unsigned long long ans=0;
int main()
{
	cin>>s;
	cin>>k;
	int len=strlen(s);
	if (len==1)
	{
		if (k==1)
		{
			cout<<0<<"\n";
			return 0;
		}
		if (k%2==0)
		{
			cout<<k/2<<"\n";
			return 0;
		}
		else
		{
			cout<<(k-1)/2<<"\n";
			return 0;
		}
	}
	if (len==2 && s[0]==s[1])
	{
		cout<<k<<"\n";
		return 0;
	}
	if (len==3 && s[0]==s[1] && s[0]==s[2])
	{
		if (k==1)
		{
			cout<<1<<"\n";
			return 0;
		}
		long long ks=k*3;
		if (ks%2==0)
		{
			cout<<ks/2<<"\n";
			return 0;
		}
		else
		{
			cout<<(ks-1)/2<<"\n";
			return 0;
		}
	}
	if (s[0]==s[len-1])
	{
		if ((s[0]==s[1] && s[0]==s[2]) && (!(s[len-1]==s[len-2] && s[len-1]==s[len-3])))
		{
			s[2]=tot;
			tot++;
			ans++;
			s[len-1]=tot;
			tot++;
			ans++;
			for (int i=0;i<len;++i)
			{
				if (s[i]==s[i+1])
				{
					s[i+1]=tot;
					tot++;
					ans++;
				}
			}
			ans*=k;
			ans--;
		}
		else
		{
			if ((!(s[0]==s[1] && s[0]==s[2])) && (s[len-1]==s[len-2] && s[len-1]==s[len-3]))
			{
				s[len-2]=tot;
				tot++;
				ans++;
				s[0]=tot;
				tot++;
				ans++;
				for (int i=0;i<len;++i)
				{
					if (s[i]==s[i+1])
					{
						s[i+1]=tot;
						tot++;
						ans++;
					}
				}
				ans*=k;
				ans--;
			}
			else
			{
				s[0]=tot;
				tot++;
				ans++;
				for (int i=0;i<len;++i)
				{
					if (s[i]==s[i+1])
					{
						s[i+1]=tot;
						tot++;
						ans++;
					}
				}
				ans*=k;
				ans--;
				if (s[len-1]>'z' || s[len-1]<'a')
				{
					ans--;
				}
			}
		}
	}
	else
	{
		for (int i=0;i<len;++i)
		{
			if (s[i]==s[i+1])
			{
				s[i+1]=tot;
				tot++;
				ans++;
			}
		}
		ans*=k;
	}
	cout<<ans<<"\n";
    return 0;
}