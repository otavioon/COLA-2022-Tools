#include <bits/stdc++.h>
#define ll long long
using namespace std;
ll n,a[100010],b[100010],c[100010],bb[100010];
int main()
{
    scanf("%lld",&n);
    a[0]=b[0]=c[0]=0;
    for(ll i=1; i<=n; i++)
        scanf("%lld",&a[i]);
    for(ll i=1; i<=n; i++)
        scanf("%lld",&b[i]);
    for(ll i=1; i<=n; i++)
        scanf("%lld",&c[i]);
    sort(a+1,a+n+1);
    sort(b+1,b+n+1);
    sort(c+1,c+n+1);
    ll sum=0,book=n,i,j;
    for( i=1,j=1; i<=n; i++)
    {
        if(b[j]>a[i])
            bb[j]++;
        else
        {
            while(b[j]<=a[i])
            {
                j++;
                bb[j]+=bb[j-1];
            }
            if(b[j]>a[i])bb[j]++;
        }
    }
    if(j!=n)
        for(; j<=n; j++)
        {

            bb[j]+=bb[j-1];
        }
    ll ans=0;
    for(ll  i=n; i>=1; i--)
    {
        ll k=0;
        for(ll j=n; j>=1; j--)
        {
            if(b[i]<c[j])
                k++;
            else
                break;
        }
        ans+=k*bb[i];
    }

    printf("%lld\n",ans);

    return 0;
}