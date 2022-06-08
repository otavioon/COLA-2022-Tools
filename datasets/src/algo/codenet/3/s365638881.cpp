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
    for(int i = 0 ; i < n ; i ++) scanf("%lld",&a[i]);
    for(int i = 0 ; i < n ; i ++) scanf("%lld",&b[i]);
    for(int i = 0 ; i < n ; i ++) scanf("%lld",&c[i]);
    sort(a,a+n);
    sort(b,b+n);
    sort(c,c+n);
    ll ans = 0;
    ll numa = 0,numc = 0;
    for(int i = 0 ; i < n ; i ++)
    {
        for(int j = 0 ; a[numa] < b[i] && numa < n ; j ++) numa ++;
        for(int j = 0 ; c[numc] <= b[i] && numc < n ; j ++) numc ++;
        ans += numa*(n-numc);
    }
    printf("%lld\n",ans);
    return 0;
}
