//* Wild4Stone - IIT Roorkee *

#include<bits/stdc++.h>
using namespace std;
   #ifndef WildStone
      #pragma GCC optimize("Ofast")
      #pragma GCC optimize("unroll-loops")
   #endif
#define rep(i,a,b) for(i=a;i<=b;++i)
#define rev(i,a,b) for(i=a;i>=b;--i)
#define max2(a,b)  ((a)>(b)?(a):(b))
#define min2(a,b)  ((a)<(b)?(a):(b))
#define all(x)  x.begin(),x.end()
#define sz(x)  (int)x.size()
#define ins insert
#define fi first
#define se second
#define pb emplace_back  //push_back
#define mp make_pair
#define endl '\n'

#ifdef WildStone       
  template <typename T>
       void __p(T a) { cout << a << " "; }
  template <typename T, typename F>
       void __p(pair<T,F> a) { cout<<"{ "; __p(a.fi); __p(a.se); cout<<"}"; }
  template <typename T>
       void __p(vector<T> a) { cout<<"{ "; for(auto __it: a) { __p(__it); cout<<", "; } cout<<"}"; }
  template <typename T>
       void __p(set<T> a) {cout<<"{ "; for(auto __it: a) { __p(__it); cout<<", "; } cout<<"}"; }
  template <typename T,typename F>
       void __p(map<T,F> a) { cout<<"{ "; for(auto __it: a) { __p(__it.fi); cout<<"-> "; __p(__it.se); cout<<", "; } cout<<"}"; }

  template <typename Arg1>
       void __f(const char* name, Arg1&& arg1)             // for single trace argument
          { cout<<name<<" : "; __p(arg1); cout<<endl; }
  template <typename Arg1, typename ...Args>
       void __f(const char* names, Arg1&& arg1, Args&& ...args)  // for multiple trace arguments
          {
             int __bracket=0,__i=0; string __s;
             for(;;__i++)
                 if(names[__i]==',' && __bracket==0)  break;
                 else
                 {  __s += names[__i];
                        if(names[__i]=='(') __bracket++;
                   else if(names[__i]==')') __bracket--;
                 }
             cout<<__s<<" : ";   __p(arg1); cout<<" | ";
             __f(names+(__i)+1,args...);
          }
   template <typename Arg1, typename Arg2>                          // for traversing array
        void __f(const char* name , Arg1 arg1[], Arg2&& arg2)
          {
             int __i=0;  string __s;
             for(;;__i++) if(name[__i]==',') break; else __s += name[__i];
             cout<<__s<<" : ";
             for(__i=0;__i<arg2;__i++) __p(arg1[__i]); cout<<endl;
          }
  #define trace(...) cout<<"LINE: "<<__LINE__<<" || "; __f( #__VA_ARGS__, __VA_ARGS__)
  clock_t clk=clock();
  #define checktime() cout<<"\nTime Elapsed : "<<float(clock()-clk)/CLOCKS_PER_SEC<<endl
#else
  #define trace(...);
  #define checktime();
#endif

typedef long long int ll;
typedef long double   ld;
typedef pair<int,int> pii;
typedef pair<ll,ll>   pll;
typedef vector<int>   vi;
typedef vector<ll>    vll;
typedef vector<pii>   vpii;
typedef vector<pll>   vpll;

// #include <ext/pb_ds/assoc_container.hpp>
// #include <ext/pb_ds/tree_policy.hpp>
// using namespace __gnu_pbds;
// template <typename T>
// using ordered_set =  tree<T,null_type,less<T>,rb_tree_tag,tree_order_statistics_node_update>;
// #define fbo find_by_order //--> *p.fbo(0), *p.fbo(1).... iterating like vector/array
// #define ook order_of_key  //--> p.ook(element) : lowerbound binary search
//  // (int)p.size();    // p.erase(value) --> erases element with that value

const ll mod = 1000000007;  //998244353;
const ll inf = 0x3f3f3f3f3f3f3f3fLL;
const double eps = 1e-9;
const double PI  = acos(-1);

ll i,j,k;
void solve(void);
inline bool equal(double a, double b) { return fabs(a-b)<eps; }
// inline ll gcd(ll a, ll b) { a=abs(a); b=abs(b); while(a>0 && b>0) (a>b?a%=b:b%=a); return (a==0?b:a); }
// inline ll power(ll x, ll n, ll m = LLONG_MAX)    
//        {  ll res=1; 
//             while(n) { if(n&1) res=(res*x)%m;  x=(x*x)%m;  n >>= 1; }  return res; 
//        }

int main()
{
  ios_base::sync_with_stdio(false); cin.tie(0);
  cout<<fixed<<setprecision(10);
  int t = 1; 
  // cin>>t;
      while(t--)  solve();
  checktime();
  return 0;
}

void solve()
{
   ll k,x; cin>>k>>x;
   if(k*500 >=  x) cout<<"Yes\n";
   else cout<<"No\n"; 
}