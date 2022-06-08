#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
#define ll long long
#define rg register
#define inf 0x3f3f3f3f
#define MX 100050
inline int read()
{
    int x=0,f=1;char c=getchar();
    while(c<'0'||c>'9'){if(c=='-')f=-1;c=getchar();}
    while(c>='0'&&c<='9')x=x*10+c-'0',c=getchar();
    return x*f;
}
int n,j,k;
int a[MX],b[MX],c[MX];
ll ans;
int main(){
    // freopen("a.in","r",stdin);
    n=read();
    for(int i=1;i<=n;i++) a[i]=read();
    for(int i=1;i<=n;i++) b[i]=read();
    for(int i=1;i<=n;i++) c[i]=read();

    sort(a+1,a+1+n);
    sort(b+1,b+1+n);
    sort(c+1,c+1+n);
    for(int i=1;i<=n;i++)
    {
        while(a[j+1]<b[i]&&j+1<=n) j++;
        while(c[k+1]<=b[i]&&k+1<=n) k++;
        ans+=1LL*j*(n-k);
    }
    printf("%lld\n",ans);
    return 0;
}