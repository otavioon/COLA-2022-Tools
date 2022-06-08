#include <bits/stdc++.h>

using namespace std;

// #define mod 1000000007
// #define mod1 9982
#define int  long long int
#define pii pair<int,int>
#define vpii vector<pii>
#define vi vector<int>
#define fi first
#define se second
#define psb push_back
#define ppb pop_back
#define fio ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL)
#define all(x) x.begin(),x.end()
#define endl "\n"

const int maxn=2e5+5;
int n,k;
int ar[maxn];

bool ok(int h)
{
    int cnt=0;
    for(int i=0;i<n;i++)
    {
        cnt+=((ar[i]+h-1)/h)-1;
    }
    return cnt <= k;
}

void solve()
{
    cin>>n>>k;
    for(int i=0;i<n;i++)
        cin>>ar[i];
    int l=1,h=(1e9),ans=-1;
    while(l<=h)
    {
        int mid=(l+h)/2;
        if(ok(mid))
        {
            ans=mid;
            h=mid-1;
        }
        else
            l=mid+1;
    }
    cout<<ans<<endl;
}

int32_t main()
{
    fio;
    int t;
    // cin>>t;
    t=1;
    while(t--)
        solve(); 
}

/*
./a.out <input.txt > output.txt
*/
