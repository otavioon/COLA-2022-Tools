#include<cstdlib>
#include<vector>
#include<string>
#include<algorithm>
#include<cstring>
#include<queue>
#include<map>
#include<stack>
#include<cstdio>
#include<cmath>
#include<iostream>
#include<vector>
#define MAXN 1000
using namespace std;
typedef long long ll;
char str[200];
int main()
{
	ios::sync_with_stdio(false);
//	freopen("../in", "r", stdin);
//	freopen("../out", "w", stdout);
	ll cnt;
	cin>>str>>cnt;
	ll sum=0;
	ll len=strlen(str);

	ll sum1=0,sum2=0;
	ll index=0;
	while(str[index]==str[index+1])
		sum1++,index++;
	sum1++;
	char z=str[0];
	ll flag=1;
	for(ll i=1;i<len;i++)
	{
		if(str[i]!=z)
			flag=0;
		if(str[i]==str[i-1])
		{
			str[i]=1;
			sum++;
		}
	}
	if(flag)
		cout<<(cnt*len)/2<<endl;
	else if(cnt==1||str[0]!=str[len-1])
	{
		cout<<cnt*sum<<endl;
	}
	else
	{
		if(sum1%2==0)
		{
			cout<<cnt*sum<<endl;
		}
		else
		{
			cout<<cnt*sum+cnt-1<<endl;
		}
	}
	return 0;
}