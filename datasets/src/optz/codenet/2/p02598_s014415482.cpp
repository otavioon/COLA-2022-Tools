#include <bits/stdc++.h>
// #include <ext/pb_ds/assoc_container.hpp>
// #include <ext/pb_ds/tree_policy.hpp>
// using namespace __gnu_pbds;
using namespace std;
#define ll  long long
#define PI  acos(-1)
#define pb  push_back
#define ins insert
#define INF 5000000000000000007 //1e18+7
#define mk  make_pair
#define lb(v,x) lower_bound(all(v),x)
#define ub(v,x)  upper_bound(all(v),x)
#define ff  first
#define ss  second
#define rev reverse
#define endl "\n"
#define max3(x,y,z)  max(x,max(y,z))
#define min3(x,y,z)  min(x,min(y,z))
#define sz(a) (ll)a.size()
#define double long double
#define coud(a,b) cout<<fixed << setprecision((b)) << (a)
#define mset(x,y)  memset(x,y,sizeof(x))
#define all(x)   (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define bp(n)  __builtin_popcountll(n)
#define mxt(a)  *(max_element(a.begin(),a.end()))
#define mnt(a)  *(min_element(a.begin(),a.end()))
#define unique_sort(c) (sort(all(c)), c.resize(distance(c.begin(),unique(c.begin(),c.end()))))
#define rep(i,a,b) for(ll i=(a);i<=(b);++i)
#define trav(a, x)    for(auto &a : x)
#define re(i,n)       for(ll i=0;i<n;++i) 
#define int2Bin(x,y)  bitset <y> z=x; cout<<z.to_string()<<endl;
const double eps=1e-7;
const string alpha = "abcdefghijklmnopqrstuvwxyz";
// int dx[8]={+1, +1, +1, 0, 0, -1, -1, -1};
// int dy[8]={+1, 0, -1, +1, -1, +1, 0, -1};
int dx[4]={1, 0, 0, -1};
int dy[4]={0, -1, 1, 0};
ll power(ll x,ll y){ll ans=1;x=x;while(y>0){if(y&1)ans=(ans*x);y=y>>1;x=(x*x);}return ans;}
ll sqr(ll x) { return x * x;}
template <typename T> T gcd(T a,T b){ if(a==0) return b; return gcd(b%a,a); }
template <class T> inline void chmax(T &x,T y){ x = max((x), (y));}
template <class T> inline void chmin(T &x,T y){ x = min((x), (y));}
template <class T> T abs(T x) { return x>0 ? x : -x;}
template <typename T> T powm(T a,T b, ll m){T cnt=1; while(b>0){ if(b%2==1) cnt=(cnt*a)%m; b/=2; a=(a*a)%m; }return cnt%m;}
typedef pair<int,int>  pii;
typedef pair<ll,ll>  pll;
typedef vector<pll>  vpll;
typedef vector<pii>  vpii;
typedef vector<ll>   vll;
typedef vector<int>  vii;
#define minpq priority_queue<T,vector<T>,greater<T> >;
// #define T int
// #define ordered_set tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>
//*X.find_by_order(k) returns the kth largest element (0-based).
//X.order_of_key(val) returns the no. of values less than val.
ll ncr(ll n,ll r){ll ans=1;if(r>n)return 0;if(r>n-r)r=n-r;for(ll i=0;i<r;i++){ans*=(n-i);ans/=(i+1);}return ans;}
const int MOD=1000000007;   
const int N=200010;
struct compare{
    bool operator() (const int &a,const int &b) const{
        return a>b;
    }
};
void prec(){

}
ll n,k,ans;
ll a[N];
bool ok(ll x) {
    ll cnt=0;
    for(int i=1; i<=n; ++i) {
        cnt+=(a[i]+x-1)/x - 1;
    }
    return cnt<=k;
}
void run(){ 
   cin>>n>>k;
   rep(i,1,n) cin>>a[i];
   ll l=1,r=1e9;
   while(l<=r) {
      ll mid=(l+r)>>1;
      if(ok(mid)) ans=mid,r=mid-1;
      else l=mid+1;
   }
   cout<<ans;
}   
int32_t main(){
    cin.sync_with_stdio(0);cin.tie(0);
    cin.exceptions(cin.failbit);
    int tc=1;
    //cin>>tc;
    prec();
    re(i,tc)
        run();
    return 0; 
}
/* 
    stuff you should look for
    * int overflow,array bounds.
    * special cases (n=1?).
    * N,MOD value.
*/
