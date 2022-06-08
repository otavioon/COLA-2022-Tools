#include<stdio.h>
#include<algorithm>
#define ll long long
using namespace std;

const int maxn = 1e6+20;
ll a[maxn],b[maxn],c[maxn];

int main()
{
    ll n;
    scanf("%lld",&n);
    for(int i = 1 ; i <= n ; i ++) scanf("%lld",&a[i]);
    for(int i = 1 ; i <= n ; i ++) scanf("%lld",&b[i]);
    for(int i = 1 ; i <= n ; i ++) scanf("%lld",&c[i]);
    sort(a+1,a+n+1);
    sort(b+1,b+n+1);
    sort(c+1,c+n+1);
    ll ans = 0;
    ll numa = 0,numc = 0;
    for(int i = 1 ; i <= n ; i ++)
    {
        while(a[numa+1] < b[i] && numa+1 <= n) numa ++;
        while(c[numc+1] <= b[i] && numc+1 <= n) numc ++;
        ans += numa*(n-numc);
    }
    printf("%lld\n",ans);
    return 0;
}
