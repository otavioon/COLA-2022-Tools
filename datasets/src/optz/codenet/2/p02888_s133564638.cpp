///PROBLEM CODE - SEGDIR (CodeChef)
///SOLUTION FOR 3rd problem of ICPC Online round 2k19!!

#include<bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define ld long double
#define rep(i,a,n) for (ll i=a;i<n;i++)
#define per(i,a,n) for (ll i=n-1;i>=a;i--)
#define all(x) (x).begin(),(x).end()
#define sz(x) (ll)x.size()
#define pb push_back


///Input/Output macros!
#define gi(x) scanf("%d", &x)
#define gi2(x, y) scanf("%d%d", &x, &y)
#define gi3(x, y, z) scanf("%d%d%d", &x, &y, &z)
#define gill(x) scanf("%lld", &x)
#define gill2(x, y) scanf("%lld%lld", &x, &y)
#define gill3(x, y, z) scanf("%lld%lld%lld", &x, &y, &z)
#define pi(x) printf("%d\n", x)
#define pill(x) printf("%lld\n", x)


///Basic Debugging macros!
#define printVar(n) cout<<#n<<": "<<n<<endl
#define printArr(a,l) cout<<#a<<": ";for(ll __i__=0;__i__<l;__i__++){cout<<a[__i__]<<" ";}cout<<endl
#define print2dArr(a,r,c) cout<<#a<<":\n";for(ll __i__=0;__i__<r;__i__++){for(ll __j__=0;__j__<c;__j__++){cout<<a[__i__][__j__]<<" ";}cout<<endl;}

using namespace std;

///Power of 2 till 2^31!
ll pow2[32] = {1,2,4,8,16,32,64,128,256,512,1024,2048,4096,8192,16384,32768,65536,131072,262144,524288,1048576,2097152,4194304,8388608,16777216,33554432,67108864,134217728,268435456,536870912,1073741824,2147483648};

///Power function!
ll power(ll x,ll y)
{
        ll res = 1;
        while(y>0){
            if(y&1)
                res *= x;
            y>>=1;
            x*=x;
        }
        return res;
}

///Basic Sieve of Eratosthenes!
void Sieve(ll n)
{
    bool prime[n+1];
    memset(prime, true, sizeof(prime));
    for (ll p=2; p*p<=n; p++)
    {
        if (prime[p] == true)
        {
            for (ll i=p*p; i<=n; i += p)
                prime[i] = false;
        }
    }
    for (ll p=2; p<=n; p++)
       if (prime[p])
          cout << p << " ";
}

ll gcd(ll a,ll b) { return b?gcd(b,a%b):a;}

bool isPerfectSquare(ll x){ ll s = sqrt(x); return (s*s == x);}

bool isFibonacci(int n){return isPerfectSquare(5*n*n + 4) || isPerfectSquare(5*n*n - 4);}

bool isPrime(int n){if (n <= 1)return false;if (n <= 3)  return true;
    if (n%2 == 0 || n%3 == 0) return false;
    for (int i=5; i*i<=n; i=i+6) if (n%i == 0 || n%(i+2) == 0)return false;
    return true;
}

typedef vector<int> vi;
typedef vector<ld> vd;
typedef vector<ll> vl;


const int MOD = 1000000007;
const long double PI = 4*atan((long double)1);
const ll INF = 1e18;


bool vis[10000];

int main()
{
    int n;
    scanf("%d",&n);//cin>>n;
    vector<int> a;
    for(int i=0;i<n;i++){
        int val;scanf("%d",&val);
        a.push_back(val);
    }
    sort(a.begin(),a.end());
    ll ans=0;
    for(int i=0;i<n && i+2<n;i++){
        if(!vis[i] && !vis[i+1] && !vis[i+2])
        if(a[i]+a[i+1]>a[i+2] && a[i]+a[i+2]>a[i+1] && a[i+2]+a[i+1]>a[i]){
            ans++;
            vis[i]=true;
            vis[i+1]=true;
            vis[i+2]=true;
        }
    }
    cout<<ans<<'\n';
}
