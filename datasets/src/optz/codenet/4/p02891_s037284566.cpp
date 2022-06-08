#include<bits/stdc++.h>
using namespace std;
#define PI 3.1415926535897932384626
#define ll long long int
ll h[1001];

ll fun(string s, ll n)
{
    ll i,ans=0,t;
    memset(h,0,sizeof(h));
    for(i=0;i<n;i++) {
        (i==0)?t=n-1:t=i-1;
        if(s[i]==s[(i+1)%n] && h[(i+1)%n]==0 && h[t]!=1)
            h[i]=1;
    }
    for(i=0;i<n;i++)  {
    //    cout<<h[i]<<" ";
        ans+=h[i]; 
    }  
    //cout<<"\n";
    ans = min(ans,n-ans);
    return ans;
}

int main()
{
    ios_base::sync_with_stdio(false);
    ll n,ans1,ans2,ans,k,i,f;
    string s,t;
    cin>>t>>k;
    n = t.size();
    ans1 = fun(t,n);
    f = h[n-1]; //first and last char considered cyclic there and counted.
    
    s = t+t; n += n;
    ans2 = fun(s,n);
    ans = ( ((ans2)*(k/2)) + ((ans1)*(k%2)) );
    ans -= f;
    cout<<ans<<"\n";
    return 0;
}
