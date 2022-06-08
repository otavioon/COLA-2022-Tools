#include<cstdio>
#include<cmath>
#include<cstdlib>
#include<cstring>
#include<ctime>
#include<algorithm>
#include<queue>
#include<vector>
#include<map>
#include<set>
#define ll long long
#define ull unsigned long long
#define mod 1000000007
#define max(a,b) (a>b?a:b)
#define min(a,b) (a<b?a:b)
#define lowbit(x) (x& -x)
#define inf 0x3f3f3f3f
#define eps 1e-18
#define maxn 2000010
inline ll read(){ll tmp=0; char c=getchar(),f=1; for(;c<'0'||'9'<c;c=getchar())if(c=='-')f=-1; for(;'0'<=c&&c<='9';c=getchar())tmp=(tmp<<3)+(tmp<<1)+c-'0'; return tmp*f;}
inline ll power(ll a,ll b){ll ans=1; for(;b;b>>=1){if(b&1)ans=ans*a%mod; a=a*a%mod;} return ans;}
inline ll gcd(ll a,ll b){return b?gcd(b,a%b):a;}
inline void swap(int &a,int &b){int tmp=a; a=b; b=tmp;}
using namespace std;
int main()
{
	int n=read(),m=read();
	printf("%d\n",(n-1)*(m-1));
}