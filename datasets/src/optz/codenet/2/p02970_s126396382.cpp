//#pragma comment(linker, "/stack:200000000") //  (UNCOMMENT WHEN HAVING LOTS OF RECURSIONS)
#pragma GCC optimize("O3")
#pragma GCC optimize("Ofast")
//#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
//#pragma GCC optimize("unroll-loops")  // $ (UNCOMMENT WHEN TRYING TO BRUTEFORCE WITH A LOT OF LOOPS)\

#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/rope>

using namespace std;
using namespace __gnu_pbds;
using namespace __gnu_cxx;

#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define int long long
#define ll long long
#define rep(i,a,b) for(int i=a;i<b;++i)
#define fre(i,a,b) for(int i=a;i<=b;i++)
#define rpe(i,a,b) for(i=a-1;i>=b;i--)
#define rp(i,n) rep(i,0,n)
#define fr(i,n) fre(i,1,n)
#define trav(a, x) for (auto& a : x)
#define pb push_back
#define eb emblace_back
#define mp make_pair
#define endl "\n"
#define F first
#define S second
#define vi vector<int>
#define vii vector< vector<int> >
#define vpi vector< pair<int,int> >
#define viii vector< vector<vector<int> > >
#define cd complex<double>
#define PI acos(-1)
#define pie 3.14159265358979323846
#define all(c) (c).begin(),(c).end()
#define prec(n) fixed << setprecision(n)
#define print_time {cout << flush; cerr << endl << "Time taken: " << fixed << setprecision(3) << 1.0 * clock() / CLOCKS_PER_SEC << " secs\n";}
#define gcd(a,b) __gcd((a),(b))
#define lcm(a,b) ((a)*(b)) / gcd((a),(b))
#define bc(n) __builtin_popcountll(n)
#define leadzero(a) __builtin_clz(a)        // count leading zeroes
#define trailzero(a) __builtin_ctz(a)       // count trailing zeroes
#define bitcount(a) __builtin_popcount(a)   // count set bits
#define lps(v,x) (lower_bound(all(v),x)-v.begin())
#define ups(v,x) (upper_bound(all(v),x)-v.begin())

typedef long double ld;
typedef long double LD;

typedef tree< int, null_type, less<int>, rb_tree_tag,tree_order_statistics_node_update>
    ordered_set;
// order_of_key (val): returns the no. of values less than val
// find_by_order (k): returns the iterator to kth largest element.(0-based)

// -------------------------<RNG>-------------------------
mt19937 RNG(chrono::steady_clock::now().time_since_epoch().count());
#define SHUF(v) shuffle(all(v), RNG);
// Use mt19937_64 for 64 bit random numbers.

// ------------------------</RNG>-------------------------

#define TRACE
#ifndef ONLINE_JUDGE
#define trace(...) __f(#__VA_ARGS__, __VA_ARGS__)
template <typename Arg1>
void __f(const char* name, Arg1&& arg1){
    cerr << name << " : " << arg1 << endl;}
template <typename Arg1, typename... Args>
void __f(const char* names, Arg1&& arg1, Args&&... args){
    const char* comma = strchr(names + 1, ',');cerr.write(names, comma - names) << " : " << arg1<<"  ";__f(comma+1, args...);}
#else
#define trace(...)
#endif

auto clk=clock();
const int inft = (1LL<<61) ;
const int inf = 5e18;
const int mod = 1e9+7;
const int mod1 = 998244353;
const int N = 1e6+1e4+1e2+1 ;
const int M = 3*(1e5+1e3+1e1) ;

int modpow(int x,int n,int mod){x %= mod ; int res = 1; while(n>0){ if(n & 1) res = res * x % mod; x = x * x % mod; n >>= 1; } return res;}

// -----------------<Modular Arithmetic>------------------

//template<typename T> T gcd(T a, T b){return(b?__gcd(a,b):a);}
//template<typename T> T lcm(T a, T b){return(a*(b/gcd(a,b)));}
int add(int a, int b, int c){int res=a+b;return(res>=c?res-c:res);}
int mod_neg(int a, int b, int c){int res;if(abs(a-b)<c)res=a-b;else res=(a-b)%c;return(res<0?res+c:res);}
int mul(int a, int b, int c){ll res=(ll)a*b;return(res>=c?res%c:res);}
ll mulmod(ll a,ll b, ll m){ll q = (ll)(((LD)a*(LD)b)/(LD)m);ll r=a*b-q*m;if(r>m)r%=m;if(r<0)r+=m;return r;}
template<typename T>T expo(T e, T n){T x=1,p=e;while(n){if(n&1)x=x*p;p=p*p;n>>=1;}return x;}
template<typename T>T power(T e, T n, T m){T x=1,p=e;while(n){if(n&1)x=mul(x,p,m);p=mul(p,p,m);n>>=1;}return x;}
template<typename T>T extended_euclid(T a, T b, T &x, T &y){T xx=0,yy=1;y=0;x=1;while(b){T q=a/b,t=b;b=a%b;a=t;\
t=xx;xx=x-q*xx;x=t;t=yy;yy=y-q*yy;y=t;}return a;}
template<typename T>T mod_inverse(T a, T n){T x,y,z=0;T d=extended_euclid(a,n,x,y);return(d>1?-1:mod_neg(x,z,n));}

// -----------------</Modular Arithmetic>-----------------

signed main()
{
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0); cin.exceptions(cin.failbit);
    srand(chrono::high_resolution_clock::now().time_since_epoch().count());
    cout<<fixed<<setprecision(10);
    #ifndef ONLINE_JUDGE
//        freopen("input.txt", "r", stdin);
//        freopen("output.txt", "w", stdout) ;
    #endif // ONLINE_JUDGE

    int n, d ;
    cin >> n >> d;

    cout << (int)ceil(1.0*n/(2*d+1)) << endl ;

    cerr<<endl<<endl<<"Time elapsed: "<<(double)(clock()-clk)/CLOCKS_PER_SEC<<endl;
return 0 ;
}


