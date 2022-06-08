#include<algorithm>
#include<iostream>
#include<cstring>
#include<string>
#include<vector>
#include<cstdio>
#include<cmath>
#include<set>
#include<map>
using namespace std;
typedef long long ll;
const int MAXN=1e5+5;
int read()
{
    int s=0,f=1;
    char ch=getchar();
    while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
    while(ch>='0'&&ch<='9'){s=s*10+ch-'0';ch=getchar();}
    return s*f;
}
ll arr[MAXN];
ll gcd(ll a,ll b)
{
    return (b==0?a:gcd(b,a%b));
}
ll lcm(ll a,ll b)
{
    return (a*b)/(gcd(a,b));
}
int main()
{
    ll n,m;
    while(cin>>n>>m)
    {
        for(int i=1;i<=n;i++)cin>>arr[i];
        ll lc=1ll;
        for(int i=1;i<=n;i++)
        {
            lc=lcm(lc,arr[i]);
        }
        ll ans=ll(1.0*m/lc+0.519);
        cout<<ans<<endl;
    }
    return 0;
}
