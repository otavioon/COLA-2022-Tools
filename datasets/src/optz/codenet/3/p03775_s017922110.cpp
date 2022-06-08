#include<bits/stdc++.h>
#define lson (o<<1)
#define rson (o<<1|1)
#define fi first
#define sc second
#define dbg(x) cout<<#x<<" = "<<(x)<<endl;
typedef long long ll;
typedef unsigned int uint;
typedef unsigned long long ull;
using namespace std;
const double pi=acos(-1);
const double eps=1e-6;
inline int lowbit(int x)
{
	return x&(-x);
}
inline int read()
{
	int f=1,x=0;
	char ch;
	do
	{
		ch=getchar();
		if(ch=='-')f=-1;
	}
	while(ch<'0'||ch>'9');
	do
	{
		x=x*10+ch-'0';
		ch=getchar();
	}
	while(ch>='0'&&ch<='9');
	return f*x;
}
template<typename T> inline T max(T x,T y,T z)
{
	return max(max(x,y),z);
}
template<typename T> inline T min(T x,T y,T z)
{
	return min(min(x,y),z);
}
template<typename T> inline T sqr(T x)
{
	return x*x;
}
template<typename T> inline void checkmax(T &x,T y)
{
	x=max(x,y);
}
template<typename T> inline void checkmin(T &x,T y)
{
	x=min(x,y);
}
template<typename T> inline void read(T &x)
{
	x=0;
	T f=1;
	char ch;
	do
	{
		ch=getchar();
		if(ch=='-')f=-1;
	}
	while(ch<'0'||ch>'9');
	do x=x*10+ch-'0',ch=getchar();
	while(ch<='9'&&ch>='0');
	x*=f;
}
template<typename A,typename B,typename C> inline A fpow(A x,B p,C yql)
{
	A ans=1;
	for(; p; p>>=1,x=1LL*x*x%yql)if(p&1)ans=1LL*x*ans%yql;
	return ans;
}
struct FastIO
{
	static const int S=1310720;
	int wpos;
	char wbuf[S];
	FastIO():wpos(0) {}
	inline int xchar()
	{
		static char buf[S];
		static int len=0,pos=0;
		if(pos==len)pos=0,len=fread(buf,1,S,stdin);
		if(pos==len)return -1;
		return buf[pos++];
	}
	inline int read()
	{
		int c=xchar(),x=0;
		while(c<=32&&~c)c=xchar();
		if(c==-1)return -1;
		for(; '0'<=c&&c<='9'; c=xchar())x=x*10+c-'0';
		return x;
	}
} io;
ll n,s,cnt=0;
int main()
{
	n=read();
    for(int i=int(sqrt(n)) ;i>=1; i--)
    {
        if(n%i==0)
        {
            s=n/i;
            for(; s>0; s/=10)
            	cnt++;
            cout<<cnt<<endl;
            return 0;
        }
    }
    return 0;
}