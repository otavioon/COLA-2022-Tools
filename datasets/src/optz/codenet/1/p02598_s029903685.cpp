// Sakhiya07 - Yagnik Sakhiya
 
#include <bits/stdc++.h>
using namespace std;
 
#define ll long long int
#define ld long double
#define ff first
#define ss second
#define pb push_back
#define all(x) x.begin(),x.end()
#define pll pair<ll,ll>
#define mp make_pair
#define bp __builtin_popcountll
#define MOD  1000000007
const int N = 10000005; 
#define FAST ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);srand(time(NULL));

void solve()
{
    ll n,k;
    cin >> n >> k;
    ll a[n];
    for(ll i=0;i<n;i++)    cin >> a[i];
    ll low = 1,high = 1e9,ans;
    while(low<=high)
    {
        ll mid = (low + high)/2;
        ll sum = 0;
        for(ll i=0;i<n;i++)
        {
            sum += ceil(a[i]/(ld)mid);
            sum--;
        }
        if(sum<=k)    
        {
            ans = mid;
            high = mid - 1;
        }
        else   low = mid + 1;
    }
    cout<<ans;
}

int main()
{
    ll t = 1;
 //   cin >> t;
    while(t--)
    {
        solve();
    }
}