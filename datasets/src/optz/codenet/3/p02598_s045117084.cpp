#include <bits/stdc++.h>
#define ll long long
#define ld long double
#define int long long
#define MOD 1000000007
#define mod 998244353
#define ff first
#define ss second
#define pb push_back
#define vi vector<int>
#define pii pair<int,int>
#define vii vector<pii>
#define vvi vector<vi>
#define endl "\n"
using namespace std;
void solve1();
void solve()
{
    int T;cin>>T;
    for(int z=1;z<=T;z++)
    {
        solve1();
    }
}
signed main()
{
    std::ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    solve1();
    return 0;
}
void solve1()
{
    int n,k;cin>>n>>k;
    ld arr[n];
    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
    }
    sort(arr,arr+n);
    int lo=1,hi=arr[n-1];
    int ans=((lo + hi)/2);
    while(lo!=hi)
    {
        if(lo==hi-1)
        {
            break;
        }
        ans=((lo + hi)/2);
        int f=0;
        for(int i=0;i<n;i++)
        {
            if(arr[i]>ans)
            {
                f+=((arr[i]-1)/ans);
            }
        }
        if(f>k)
        {
            lo = ans;

        }
        else
        {
            hi =ans;
        }

    }
    if(k==0)
    {
        cout<<arr[n-1]<<endl;
    }
    else
    {
    cout<<ans<<endl;}
}
