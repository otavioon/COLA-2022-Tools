#include<iostream>
#include<cstdio>
#include<algorithm>
#include<set>
#include<queue>
#include<cstring>
using namespace std;
#define MAXN 500000
#define LL long long
#define Pr pair<int,int>
#define X first
#define Y second
int n,k,F;
char s[MAXN+5];
LL cnt;
LL read(){
	LL x=0,F=1;char c=getchar();
	while(c<'0'||c>'9'){if(c=='-')F=-1;c=getchar();}
	while(c>='0'&&c<='9'){x=x*10+c-'0';c=getchar();}
	return x*F;
}
int main()
{
	scanf("%s",s+1);
	k=read();
	n=strlen(s+1);
	if(k==1){
		int ans=0;
		for(int i=1;i<n;i++)
		if(s[i]==s[i+1]){
			s[i+1]='Z'+1;
			ans++;
		}
		printf("%d",ans);
		return 0;
	}
	s[n+1]=s[1];
	for(int i=1;i<=n;i++)
	if(s[i]==s[i+1]){
		s[i+1]='Z'+1;
		if(i==n)F=1;
		else cnt++;
	}
	printf("%lld\n",cnt*k+F*(k-1));
}