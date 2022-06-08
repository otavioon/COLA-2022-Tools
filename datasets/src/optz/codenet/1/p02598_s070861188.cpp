#include <iostream>
#include <algorithm>
#include <cmath>
#include <climits>
#include <vector>
#include <cstring>
#include <set>
#include <map>
#include <stack>
#include <queue>
#include <unordered_map>
#include <unordered_set>
#include <string.h>
#include <iomanip>
using namespace std;
#define int long long
#define ull unsigned long long
#define F first
#define S second
#define nl "\n"
#define ld long double
#define div 1000000007
#define pi 3.14159265358979323846
#define pb push_back

bool chk(int l,int a[],int n,int k)
{
    int sum=0;
    for(int i=0;i<n;i++)
    {
        sum+=(a[i]/l);
    }
    if(sum<=k)
        return true;
    else
        return false;
}

void solve()
{
    int n,k;cin>>n>>k;
    int a[n];
    for(int i=0;i<n;i++)
        cin>>a[i];
    int l=1,u=*max_element(a,a+n);
    int ans=u;
    while(l<=u)
    {
        int mid=(l+u)/2;
        if(chk(mid,a,n,k))
        {
            ans=mid;
            u=mid-1;
        }
        else
            l=mid+1;
    }
    cout<<ans<<nl;
}

signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL);

    int t=1;
    //cin>>t;
    while(t--)
    {
        solve();
    }
    return 0;
}
