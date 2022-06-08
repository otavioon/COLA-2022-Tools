#include <bits/stdc++.h>
#define MAXN 1000000005
using namespace std;
typedef long long ll;


int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    long n,i,j;
    cin>>n;
    ll a[n+1];
    unordered_map<ll,ll> c;
    ll ans = 0;

    for(i=1;i<=n;i++)
    {
        cin>>a[i];
        c[a[i]]++;
    }
    vector<ll> po2,vec;
    for(i=1;i<MAXN;i<<=1)
    {
        po2.push_back(i);
        // cout<<i<<" ";
    }
    for(auto it: c)
    {
        vec.push_back(it.first);
    }
    sort(vec.begin(),vec.end());
    for(i=1;i<=vec.size();i++)
    {
        // cout<<c[vec[i]]<<": ";
        if(c[vec[i]]>0)
        {
            for(j=po2.size()-1;j>=0;j--)
            {
                if(c[po2[j]-vec[i]]>0)
                {
                    // cout<<po2[j]-vec[i]<<endl;
                    if(vec[i]!=po2[j]-vec[i])
                    {
                        ll z = min(c[vec[i]],c[po2[j]-vec[i]]);
                        ans += z;
                        c[vec[i]] -= z;
                        c[po2[j]-vec[i]] -= z;
                        if(c[vec[i]]<=0)
                        break;
                    }
                    else
                    {
                        if(c[vec[i]]>1)
                        {
                            ll z = c[vec[i]]/2;
                            ans += z;
                            c[vec[i]] -= z*2;
                            if(c[vec[i]]<=0)
                            break;
                        }
                    }
                }
            }
        }
        // cout<<endl;
    }
    cout<<ans;
    
    return 0;
}
