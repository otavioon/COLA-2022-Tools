/////////////////////////////////////////////////////////
//
//  c/temp.cpp file
//  Last Updated: 2018-10-23 ...Maybe
//
//    I hope you adding this code to the setting file
//    alias g++='g++ -std=c++1y -DDEBUG_LOCAL'
//
/////////////////////////////////////////////////////////

#include <bits/stdc++.h>

using namespace std;

#define fi first
#define se second
#define mp make_pair
#define pb push_back

//#define int long long

#define _overload3(_1,_2,_3,name,...) name
#define _REP(i,n) REAP(i,0,n)
#define REAP(i,a,b) for(int i=int(a);i<int(b);++i)
#define REP(...) _overload3(__VA_ARGS__,REAP,_REP,)(__VA_ARGS__)

#define _REPR(i,n) REAPR(i,n,0)
#define REAPR(i,a,b) for(int i=int(a-1);i>=int(b);--i)
#define REPR(...) _overload3(__VA_ARGS__,REAPR,_REPR,)(__VA_ARGS__)

#define ALL(a) a.begin(),a.end()
#define rALL(a) a.rbegin(),a.rend()

#define coutALL(a) {int loop_coutALL=0;for(auto e:a) cout<<(loop_coutALL++?" ":"")<<e; cout<<endl;}

#define coutYN(a) cout<<((a)?"YES":"NO")<<endl;
#define coutYn(a) cout<<((a)?"Yes":"No")<<endl;
#define coutyn(a) cout<<((a)?"yes":"no")<<endl;

#define pcnt __builtin_popcount
#define buli(x) __builtin_popcountll(x)

const int INF=1145141919;
//const long long INF=114514191911451419;
const int MOD=(int)1e9+7;
const double EPS=1e-12;
const int dx[]={1,0,-1,0},dy[]={0,1,0,-1};
//const int dx[]={-1,-1,-1,0,1,1,1,0},dy[]={-1,0,1,1,1,0,-1,-1};

using vi=vector<int>;
using vvi=vector<vi>;
using vs=vector<string>;

typedef pair<int,int> pii;
typedef pair<int,string> pis;
typedef pair<string,int> psi;
typedef pair<string,string> pss;

typedef long long ll;

template<typename T> istream &operator >> (istream &is, vector<T> &v){for(T &x:v) is>>x;return is;}
template<typename T> ostream &operator << (ostream &os, vector<T> &v){int i=0;for(T &x:v) os<<(i++?" ":"")<<x;return os;}

ll rev(ll n){ll x=0;for(;n>0;){x=x*10+n%10;n/=10;}return x;}

ll upper(ll n,ll m){return (n+m-1)/m;};
ll rounding(ll n){return (long double)n+0.5;};

bool inG(ll x,ll n){return 0<=x && x<n;}
bool outG(ll x,ll n){return x<0 || n<=x;}

inline int qp(int a,ll b){if(!b)return 1;int ans=1;do{if(b&1)ans=1ll*ans*a;a=1ll*a*a;}while(b>>=1);return ans;}
inline int qp(int a,ll b,int mo){if(!b)return 1;int ans=1;do{if(b&1)ans=1ll*ans*a%mo;a=1ll*a*a%mo;}while(b>>=1);return ans;}

inline ll fac(ll k,ll n){ll a=1;for(int i=0;i<n;i++)a*=k--;return a;}
inline ll fac(ll k,ll n,int mo){ll a=1;for(int i=0;i<n;i++)a*=k--,a%=mo;return a;}

inline int dsum(ll n){int a=0;for(;n;n/=10)a+=n%10;return a;}

struct Arithmetic{Arithmetic(){cin.tie(0);ios::sync_with_stdio(0);cout<<fixed<<setprecision(20);}};

//#define DEBUG_LOCAL

#ifdef DEBUG_LOCAL
template<typename T> void deb(T a){cerr<<"deb: "<<a<<"です"<<endl;}
#define debl {cerr<<"debug: "<<__LINE__<<"行目だ"<<endl;}
void what_cr(){cout<<__GCC_ATOMIC_CHAR16_T_LOCK_FREE<<" ←？"<<endl;}
//ori_func S

//ori_func E
#else
template<typename T>void deb(T a){}
#define debl
void what_cr(){}void t_t(){}
#endif

signed main(){

  Arithmetic Exception;

  int n;
  cin>>n;

  multiset <int> a;

  REP(i,n){

    int x;
    cin>>x;
    a.insert(x);

  }

  int ans=0;

  for(;!a.empty();){

    auto it1=a.end(); it1--;
    a.erase(it1);

    int fi2=pow(2,(int)log2(*it1)+1)-*it1;

    set<int>::iterator it2;
    if((it2=a.find(fi2))!=a.end()){

      ans++;
      a.erase(it2);

    }

  }

  cout << ans << endl;

  return 0;

}
