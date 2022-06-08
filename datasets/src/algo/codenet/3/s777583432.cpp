#include<bits/stdc++.h>
#define ll long long
#define met(a) memset(a,0,sizeof(a))
#define inf 0x3f3f3f3f
using namespace std;
const int mod=1e9+7;
const int N=1e5+10;
ll a[N],b[N],c[N];
int main()
{
    ll i,j=0,k=0,m,n;
    ll ans=0;
    cin>>n;
    for(i=1; i<=n; i++)
        cin>>a[i];
    for(i=1; i<=n; i++)
        cin>>b[i];
    for(i=1; i<=n; i++)
        cin>>c[i];
    sort(a+1,a+1+n);
    sort(b+1,b+1+n);
    sort(c+1,c+1+n);
    for(i=1;i<=n;i++)
    {
        while(a[j+1]<b[i]&&j+1<=n)
            j++;
        while(c[k+1]<=b[i]&&k+1<=n)
            k++;
        ans+=j*(n-k);
    }
    cout<<ans<<endl;
    return 0;
}
