//----AUTHOR:kkdrummer----/
#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
//#include <boost/multiprecision/cpp_int.hpp> 
//using namespace boost::multiprecision; 
using namespace __gnu_pbds;
using namespace std;
typedef    long long   ll;
typedef    long double   ld;
//typedef    unordered_set<ll>   usll;
//typedef    unordered_multiset<ll>   umsll;
typedef    multiset<ll>   msll;
typedef    set<ll>   sll;
typedef    vector<ll>   vll;
typedef    pair<ll,ll>   pll;
typedef    vector<pll>   vpll;
typedef    priority_queue<ll>   pqll;
typedef    vector<int>   vi;
typedef    set<int>   si;
typedef    multiset<int>   msi;
//typedef    unordered_multiset<int>   umsi;
//typedef    unordered_set<int>   usi;
typedef     pair<int,int>   pi;
typedef    vector<pi>   vpi;
typedef    set<pi>   spi;
typedef    priority_queue<int>   pqi;
typedef    tree<int,null_type,less<int>,rb_tree_tag,tree_order_statistics_node_update>   ind_set;
typedef    tree<ll,null_type,less<ll>,rb_tree_tag,tree_order_statistics_node_update>   ind_setll;
#define    in   insert
#define    fi   first
#define    se   second
#define    pb   push_back
#define    mp   make_pair
#define    be   begin
#define    en   end
#define    itr   iterator
#define io ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define    mo   998244353
#define    inf  9223372026854775807
#define    ninf   -inf
#define    ima   2047483647
#define    imi   -ima
#define    oncnt    __builtin_popcount
#define    zerobegin   __builtin_clz
#define    zeroend   __builtin_ctz
#define    parity   __builtin_parity
#define    all(x)   x.be(),x.en()
#define    eps   1e-9
#define    coutd   cout<<setprecision(12)<<fixed
#define    mems(dp,x)   memset(dp,x,sizeof(dp))
#define    fbo    find_by_order
#define    ook    order_of_key
#define    upb    upper_bound
#define    lowb   lower_bound 
#define    lte(v,x)   upb(all(v),x)-v.be()
#define    gte(v,x)   v.end()-lowb(all(v),x)
const    ld   PI=3.1415926535897932384626433832792884197169399375105820974944;
inline ll modpow(ll x,ll n){if(x==0)return 0;if(n==0)return 1;if(n==1)return(x%mo);ll u=(modpow(x,n/2));u=(u*u)%mo;if(n%2!=0)u=(u*x%mo)%mo;return u;}
inline ll modinv(ll x){return modpow(x,mo-2);}
inline ll mmul(ll a,ll b){if(a>=mo)a=a%mo;if(b>=mo)b=b%mo;if(a*b>=mo)return(a*b)%mo;return(a*b);}
inline ll madd(ll a, ll b){if(a>=mo)a=a%mo;if(b>=mo)b=b%mo;if(a+b>=mo)return(a+b)%mo;return(a+b);}
inline ll msub(ll a, ll b){if(a>=mo)a=a%mo;if(b>=mo)b=b%mo;return(((a-b)%mo+mo)%mo);}
inline ll mdiv(ll a,ll bb){if(a>=mo)a=a%mo;ll b=modinv(bb);if(b>=mo)b=b%mo;if(a*b>=mo)return(a*b)%mo;return(a*b);}
inline ll gcd(ll a,ll b){return __gcd(a,b);}
inline ll lcm(ll a,ll b){return (a*b)/gcd(a,b);}





int main()
{       io 
int testcases=1;      //  cin>>testcases;
while(testcases--)
{


ll n,d;
cin>>n>>d;
d*=2ll;
d++;
ll k=n/d;
if(n%d!=0)
k++;

cout<<k;














}return 0;}