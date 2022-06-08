#include <bits/stdc++.h>
  
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/detail/standard_policies.hpp>
using namespace __gnu_pbds;
 
using namespace std;
 
#if !ONLINE_JUDGE
#define debug
#endif
 
typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> ii;
typedef vector<pair<int,int> > vii;
typedef pair<ll,ll> pll;
typedef vector<vector<int> > vvi;
typedef vector<vector<ii> > vvii;
 
#define pb push_back
#define mp make_pair
#define all(x) x.begin(),x.end()
#define sz(x) (int)x.size()
#define fill(a,x) memset(a,x,sizeof(a))
#define ff first
#define ss second
#define trav(a, x) for(auto& a : x) 
#define FOR(i,a,b) for(int i = a; i<=b; ++i)
#define NFOR(i,a,b) for(int i = a; i>=b; --i)

#ifdef debug
#define dbg(...) { cerr<<"[ "; dump(#__VA_ARGS__, __VA_ARGS__);}
#undef endl
template <typename Arg1,typename Arg2>
ostream& operator << (ostream& out, const pair<Arg1,Arg2> &x) {
    return out<<"("<<x.ff<<","<<x.ss<<")";
}
 
template <typename Arg1>
ostream& operator << (ostream& out, const vector<Arg1> &a) {
    out<<"[";for(const auto &x:a)out<<x<<",";return out<<"]";
}
 
template <typename Arg1>
ostream& operator << (ostream& out, const set<Arg1> &a) {
    out<<"[";for(const auto &x:a)out<<x<<",";return out<<"]";
}
 
template <typename Arg1,typename Arg2>
ostream& operator << (ostream& out, const map<Arg1,Arg2> &a) {
    out<<"[";for(const auto &x:a)out<<x<<",";return out<<"]";
}
 
template <typename Arg1,typename Arg2>
ostream& operator << (ostream& out, const unordered_map<Arg1,Arg2> &a) {
    out<<"[";for(const auto &x:a)out<<x<<",";return out<<"]";
} 
 
template <typename Arg1>
void dump(const string name, Arg1&& arg1){
    cerr << name << " : " << arg1 << " ] " << endl;
}
 
template <typename Arg1, typename... Args>
void dump(const string names, Arg1&& arg1, Args&&... args){
    const string name = names.substr(0,names.find(','));
    cerr<<name<<" : "<<arg1<<" | ";
    dump(names.substr(1+(int)name.size()), args...);
}
#else
    #define dbg(args...)
#endif
 
ll gcd(ll a,ll b){if (a==0) return b;return gcd(b%a,a);}
ll lcm(ll a,ll b){return a*(b/gcd(a,b));}
ll Abs(ll a){if(a>0)return a;return -a;}
ll Ceil(ll a,ll b){if(a%b==0)return a/b;else return a/b+1;}
double Abs(double a){if(a>0)return a;return -a;}
 
//*X.find_by_order(2) element at index=2
//X.order_of_key(1) how many elements strictly less than 1
 
#define ordered_set tree<int, null_type,less_equal<int>, rb_tree_tag,tree_order_statistics_node_update> 

const ll INF = 1e18;
const int mod = 1e9 + 7;
 
inline int pow_(ll x, ll y,ll p){
  int r = 1; while(y){if(y & 1) r = r * x % p; y >>= 1; x = x * x % p;} return r;
}
inline int inv_(int x){return pow_(x, mod - 2, mod);}
inline int add(ll a,ll b){a += b; if(a >= mod) a -= mod; return a;}
inline int mul(int a, int b){return a * 1LL * b % mod;}
inline int sub(int a, int b){a -= b; if(a < 0) a += mod; return a;}
  
mt19937_64 mrand(chrono::steady_clock::now().time_since_epoch().count());
 
const int N = 1e5 + 5;

int a[N];
int sum[N] = {0};

int main(int argc, char const *argv[])
{
    #ifdef LOCAL_TEST
    freopen("in.txt","r",stdin);
    //freopen("out.txt", "w", stdout);
    #else
    ios_base::sync_with_stdio(false);cin.tie(NULL);
    #endif

    auto start = std::chrono::high_resolution_clock::now();

    ll k,n;
    cin>>k>>n;

    if(k*500 >= n){
        cout << "Yes\n";
    } else {
        cout << "No\n";
    }

    auto finish = std::chrono::high_resolution_clock::now();  
    std::chrono::duration<double> elapsed = finish - start;
    cerr << "Elapsed time: " << elapsed.count() << " s\n";
    
    return 0;    
}