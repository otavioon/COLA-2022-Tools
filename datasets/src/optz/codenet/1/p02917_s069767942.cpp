// by adiforluls
#pragma GCC optimize ("-O2")
#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;
#define FAST         ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0)
#define ll           long long
#define ld           long double
#define pb           push_back
#define mp           make_pair
#define pii          pair<int,int>
#define mii          map<int,int>
#define vi           vector<int>
#define vll          vector<long long>
#define all(a)       (a).begin(),(a).end()
#define clz(a)       __builtin_clz(a) // count leading zeroes
#define ctz(a)       __builtin_ctz(a) // count trailing zeroes
#define popc(a)      __builtin_popcount(a) // count set bits (for ints only diff for ll)
#define lul          1000000007
#define rep(i,a,b)   for(int i=a;i<b;i++)
#define rfor(i,a,b)  for(int i=a; i>=b; i--)
#define SIZE         1000005
#define F            first
#define S            second
#define mod          998244353
 
#define TRACE
 
#ifdef TRACE
#define trace(...) __f(#__VA_ARGS__, __VA_ARGS__)
template <typename Arg1>
void __f(const char* name, Arg1&& arg1){
    std::cerr << name << " = " << arg1 << std::endl;
}
template <typename Arg1, typename... Args>
void __f(const char* names, Arg1&& arg1, Args&&... args){
    const char* comma = strchr(names + 1, ',');std::cerr.write(names, comma - names) << " = " << arg1<<" |";__f(comma+1, args...);
}
#else
#define trace(...)
#endif
 
#define endl         '\n'
#define ordered_set tree<ll, null_type,less<ll>, rb_tree_tag,tree_order_statistics_node_update>
// order_of_key(k)
// find_by_order(k)
const ld PI = acos(-1.0);
const int INF = 0x3f3f3f3f;

void solve()
{
    int n; cin>>n;
    vi a(n-1);
    rep(i,0,n-1) cin>>a[i];
    int ans = a[0]+a[n-1];
    if(n>2)
    {
        rep(i,0,n-2)
        {
            ans+=min(a[i],a[i+1]);
        }
    }
    cout<<ans;    
}
int main()
{   
    FAST;
   //  #ifndef ONLINE_JUDGE
     // freopen("input.txt", "r", stdin);
     // freopen("output.txt", "w", stdout);
   //  #endif
    int t; t=1; //cin>>t;
    while(t--){
       solve();
    }
    return 0;
}