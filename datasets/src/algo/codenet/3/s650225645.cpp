#include<stdio.h>
#include<algorithm>
#define ll long long
using namespace std;

const int maxn = 1e6+10;
ll a[maxn],b[maxn],c[maxn];

int main()
{
    int n;
    scanf("%d",&n);
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
        while(a[numa] < b[i] && numa <= n) numa ++;
        while(c[numc] <= b[i] && numc <= n) numc ++;
        ans += numa*(n-numc);
    }
    printf("%lld\n",ans);
    return 0;
}
