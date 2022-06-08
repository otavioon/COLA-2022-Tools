#include<bits/stdc++.h>
using namespace std;
#define il inline
#define gc getchar()
#define int long long
#define ri register int
#define rb register bool
#define rc register char
#define rp(i,x,y) for(ri i=x;i<=y;++i)
#define my(i,x,y) for(ri i=x;i>=y;--i)

const int N=1000+10;
int K,len,ret,as;
char str[N];

il int read()
{
	rc ch=gc;ri x=0;rb y=1;
	while(ch!='-' && (ch>'9' || ch<'0'))ch=gc;
	if(ch=='-')ch=gc,y=0;
	while(ch>='0' && ch<='9')x=(x<<1)+(x<<3)+(ch^'0'),ch=gc;
	return y?x:-x;
}

signed main()
{
	//freopen("A.in","r",stdin);freopen("A.out","w",stdout);
	scanf("%s",str+1);len=strlen(str+1);K=read();if(len==1)return printf("%lld\n",K/2),0;
	ri nw=1;while(nw<=len && str[nw]==str[nw+1])++nw;
	rp(i,2,len)if(str[i]==str[i-1])++ret,str[i]='z'+1;;if(K==1)printf("%lld\n",ret);
	if(nw&1 && str[len]==str[1])as=K-1;;printf("%lld\n",ret*K+as);
	return 0;
}

