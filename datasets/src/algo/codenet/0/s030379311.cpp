#include<bits/stdc++.h>
#define LL long long
using namespace std;
char c[210];
LL n,ans;
bool book[210],flag;
LL read(){LL sss=0,fff=1;char ccc;ccc=getchar();while(ccc<'0'||ccc>'9'){if(ccc=='-')fff=-1;ccc=getchar();}while(ccc>='0'&&ccc<='9'){sss=sss*10+ccc-'0';ccc=getchar();}return sss*fff;}
int main()
{
//	freopen("123.in","r",stdin);
//	freopen("123.out","w",stdout);
	scanf("%s",c);
	n=read();
	int len=strlen(c);
	int i=1;
	while(i<len)
	{
		if(c[i]==c[i-1])
		{
			book[i]=true;ans++;i+=2;
			if(i==len&&c[0]==c[len-1])
				flag=true,book[len-1]=true,ans++;
		}
		else
		{
			i++;
			if(i==len&&c[0]==c[len-1])
				book[len-1]=true,ans++;
		}
	}
	ans*=n;
	if(flag)
		printf("%lld\n",ans-1);
	else
		printf("%lld\n",ans);
	return 0;
}