#include <bits/stdc++.h>
using namespace std;

#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define int long long

#define N 2e5+5;

int32_t main()
{
    IOS;
    int t=1;
    // cin>>t;
    while(t--)
    {
        int n,k;
        cin>>n>>k;
        int a[n];
        int l=1,r=0;
        for (int i = 0; i < n; ++i)
        {
            cin>>a[i];
            r=max(r,a[i]);
        }
        int ans=0;
        while(l<=r){
            int mid=(l+r)/2;
            int s=0;
            for(int i=0; i<n; i++){
                s+=(a[i]+mid-1)/mid;
                s-=1;
            }
            if(s<=k){
                ans=mid;
                r=mid-1;
            }
            else{
                l=mid+1;
            }
        }
        cout<<ans;
    }
    return 0;
}