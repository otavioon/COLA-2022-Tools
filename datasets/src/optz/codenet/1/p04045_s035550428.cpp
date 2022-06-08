#include <iostream>
#include <bits/stdc++.h>
#pragma GCC Optimize("Ofast")
using namespace std;
#define ll long long
ll vis[100];

ll solve(ll d,ll val, ll n)
{
    // cout<<val<<" ";
    if(n<=val)
    {
        return val;
    }
    ll ans=INT_MAX;
    for(ll i=0;i<=9;i++){
        if(vis[i]==0)
        {
            ans = min(ans,solve(d,(val*10)+i,n));
        }
    }
    return ans;
}



int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    memset(vis,0,sizeof(vis));
    ll n,k;
    cin>>n>>k;
    ll a[k+1];
    for(ll i=0;i<k;i++)
    {
        cin>>a[i];
        vis[a[i]]=1;
    }
    ll start = 0;
    for(ll i=1;i<10;i++)
    {
        if(vis[i]==0)
        {
            start = i;
            break;
        }
    }
    
    
    cout<<solve(1,start,n)<<endl;
    
    
   return 0;
}