#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int main()
{
    ll n;
    cin>>n;
    ll a[n];
    for(ll i=1;i<=n-1;i++)
        cin>>a[i];

        ll tmp=a[n-1];
        ll sum=a[n-1];
        ll aj=0;
    for(ll i=n-2;i>=1;i--)
    {
        if(a[i]<=tmp)
        {
            sum+=a[i];
        }
        else
        {
            aj=1;
            sum+=a[i+1];
        }
    }
    if(aj==1)
        cout<<sum<<endl;
    else
        cout<<sum+a[1]<<endl;
}
