#pragma GCC optimize(2)
#include<bits/stdc++.h>
#define ll long long
#define maxn 1000005
#define inf 1e9
#define pb push_back
#define rep(i,a,b) for(int i=a;i<=b;i++)
#define per(i,a,b) for(int i=a;i>=b;i--)
using namespace std;

inline ll read()
{
	ll x=0,w=1; char c=getchar();
	while(c<'0'||c>'9') {if(c=='-') w=-1; c=getchar();}
	while(c<='9'&&c>='0') {x=(x<<1)+(x<<3)+c-'0'; c=getchar();}
	return w==1?x:-x;
}

char s[maxn],t[maxn];

int main()
{
	scanf("%s",s+1); ll k=read(),a1=0,a2=0,ans=0,n=strlen(s+1);
	rep(i,1,n) s[i+n]=s[i],t[i]=s[i];
	rep(i,2,n) if(s[i]==s[i-1]) s[i]='#',a1++;
	if(s[1]!=s[n]) return cout<<a1*k<<endl,0;
	per(i,n-1,1) if(t[i]==t[i+1]) t[i]='#',a2++;
	if(t[1]!=t[n]) return cout<<a2*k<<endl,0;
	rep(i,n+1,2*n) if(s[i]==s[i-1]) s[i]='#',a2++;
	ans=a1*k;
	if(s[2*n]=='#') ans+=k/2; else ans+=k-1;
	cout<<ans<<endl;
	return 0;
}