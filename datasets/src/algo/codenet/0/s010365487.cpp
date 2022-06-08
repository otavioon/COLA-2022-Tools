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
int n,F,flag=1;
char s[MAXN+5];
LL cnt,k;
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
	for(int i=2;i<=n;i++)
	if(s[i]!=s[i-1])flag=0;
	if(flag){
		if(n%2){
			printf("%lld",((n+1)/2)*(k/2)+(n/2)*(k+1)/2);
		}else{
			printf("%lld",(n/2)*k);
		}
		return 0;
	}
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
		if(i==n||i==n-1)F=1;
		else cnt++;
	}
	printf("%lld\n",cnt*k+F*(k-1));
}