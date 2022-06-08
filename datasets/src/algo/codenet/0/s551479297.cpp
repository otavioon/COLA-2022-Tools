#include<iostream>
#include<cstdio>
#include<algorithm>
#include<set>
#include<queue>
#include<cstring>
using namespace std;
#define MAXN 100000
#define LL long long
#define Pr pair<int,int>
#define X first
#define Y second
int n,k,F;
char s[MAXN+5];
LL cnt[3];
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
		for(int i=1;i<3*n;i++)
		if(s[i]==s[i+1]){
			s[i+1]='Z'+1;
			ans++;
		}
		printf("%d",ans);
		return 0;
	}
	for(int i=1;i<=n;i++)
	s[i+n]=s[i+n*2]=s[i+n*3]=s[i+n*4]=s[i];
	for(int i=1;i<5*n;i++)
	if(s[i]==s[i+1]){
		if(i!=4*n)s[i+1]='Z'+1;
		cnt[i/n]++;
	}
	//printf("%d %d %d %d\n",cnt[0],cnt[1],cnt[2],cnt[3]);
	printf("%lld\n",cnt[0]+cnt[1]*((k-1)/2)+cnt[2]*((k-2)/2)+((k%2)?cnt[4]:cnt[3]));
}