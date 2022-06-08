#include <bits/stdc++.h>
using namespace std;

#define fast ios_base::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL)

#define ll long long
#define pb(a) push_back(a)
#define eb(a) emplace_back(a)

#define xx first
#define yy second
#define mp make_pair
//#define end "\n"
#define pll pair<ll,ll>
#define mll map<ll,ll>
#define vll vector<ll>
#define pdd pair<double,double>
#define ALL(v) (v).begin(), (v).end()

const ll MOD=998244353;
const ll inf=1e18;

#define MODSET(d) if ((d) >= MOD) d %= MOD;
#define MODNEGSET(d) if ((d) < 0) d = ((d % MOD) + MOD) % MOD;


ll power(ll a,ll n){
    ll ans=1;
    while(n){
        if(n&1)
            ans=(ans*a);
        n>>=1;
        a=(a*a);
    }
    return ans;
}

ll powerMod(ll a,ll n){
    ll ans=1;
    while(n){
        if(n&1)
            ans=(ans*a)%MOD;
        n>>=1;
        a=(a*a)%MOD;
    }
    return ans;
}

ll lcm(ll a,ll b){
    return a*(b/__gcd(a,b));
}

ll sumdigit(ll n){
    ll sum=0;
    while(n){
        sum+=n%10;
        n=n/10;
    }
    return sum;
}

ll countSetBit(ll a){
    return __builtin_popcount(a);
}

const long sz=1e5+10;

ll length(ll a){
    ll ans=0;
    while(a){
        ans++;
        a=a/10;
    }
    return ans;
}


int main()
{
    fast;
    ll t;
   // cin>>t;
    t=1;
    while(t--){
        ll n,d;
        cin>>n>>d;
        cout<<ceil(1.0*n/(2*d+1));
    }
    return 0;
}
