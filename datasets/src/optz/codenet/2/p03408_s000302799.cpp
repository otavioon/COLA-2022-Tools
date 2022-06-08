/*
#include <boost/multiprecision/cpp_dec_float.hpp>
#include <boost/multiprecision/cpp_int.hpp>

#include <boost/rational.hpp>
*/
#include <bits/stdc++.h>
using namespace std;
#define _GLIBCXX_DEBUG
#define rep(i,t) for (ll i = (ll)(0); i < (ll)(t); i++)
#define rep2(i,s,t) for (ll i = (ll)(s); i < (ll)(t); i++)
#define rep3(i,t) for (ll i = (ll)(1); i <= (ll)(t); i++)
#define rep4(i,s,t) for (ll i = (ll)(s); i <= (ll)(t); i++)
#define repr(i,t) for (ll i = (t-1); i>=(0);i--)
#define repr2(i,s,t) for (ll i = (t-1); i>=(s);i--)
#define repr3(i,t) for (ll i = (t); i>=(1);i--)
#define repr4(i,s,t) for (ll i = (t); i>=(s);i--)
using ll = long long;
using ld = long double;
using ull = unsigned long long;
using uint = unsigned;
using pcc =pair<char,char>;
using pll = pair<ll,ll>;
using pii = pair<int,int>;
using pdd = pair<double,double>;
using tuplis = array<ll,3>;
template<class T> using pq = priority_queue<T,vector<T>,greater<T>>;
inline const ll LINF = 0x1fffffffffffffff;
inline const ll MINF = 0x7fffffffffff;
inline const int INF = 0x3fffffff;
inline const int mod=1000000007;
//inline const int mod=998244353;



inline const ld DINF = numeric_limits<ld>::infinity();
inline const ld EPS=1e-9;
inline const ld PI=acos(-1);
//const ll dx[] ={0,1,0,-1,1,-1,1,-1};
//const ll dy[] ={1,0,-1,0,1,1,-1,-1};
inline const bool grindin(const int i,const int j,const int H,const int W){return i>=0&&i<H&&j>=0&&j<W;}
inline const ll dx[] ={0,1,0,-1};
inline const ll dy[] ={1,0,-1,0};
#define is_low(c) ('a'<=c)&&(c<='z')
#define is_upp(c) ('A'<=c)&&(c<='Z')
#define each1(i,a) for(auto&& i:a)
#define each2(x,y,a) for(auto&& [x,y]:a)
#define each3(x,y,z,a) for(auto&& [x,y,z]:a)
#define rrep(n) for(ll i=(n);i--;)
#define stlen(s) ll s.size()-1
#define all(v) begin(v), end(v)
#define range(v,a) begin(v),begin(v)+a
#define range2(v,a,b) begin(v)+a,begin(v)+b
#define range3(v,a) begin(v)+1,begin(v)+a+1
#define range4(v,a,b) begin(v)+a+1,begin(v)+b+1
#define allr(v) rbegin(v), v.rend(v)
#define ranger(v,a) rbegin(v),rbegin(v)+a
#define ranger2(v,a,b) rbegin(v)+a,rbegin(v)+b
#define ranger3(v,a) rbegin(v)+1,rbegin(v)+a+1
#define ranger4(v,a,b) rbegin(v)+a+1,rbegin(v)+b+1
#define cout(n) cout<<std::fixed<<std::setprecision(n)
//#define sum(...) accumulate(all(__VA_ARGS__),0LL)
#define dsum(...) accumulate(all(__VA_ARGS__),0.0L)
#define elif else if
#define unless(a) if(!(a))
#define mp make_pair
#define mt make_tuple
#define INT(...) int __VA_ARGS__; in(__VA_ARGS__)
#define LL(...) ll __VA_ARGS__; in(__VA_ARGS__)
#define ULL(...) ull __VA_ARGS__; in(__VA_ARGS__)
#define STR(...) string __VA_ARGS__; in(__VA_ARGS__)
#define CHR(...) char __VA_ARGS__; in(__VA_ARGS__)
#define DBL(...) double __VA_ARGS__; in(__VA_ARGS__)
#define LD(...) ld __VA_ARGS__; in(__VA_ARGS__)
#define Sort(a) sort(all(a))
#define Rev(a) reverse(all(a))
#define Uniq(a) sort(all(a)); a.erase(unique(all(a))),end(a))
#define vec(type,name,...) vector<type> name(__VA_ARGS__)
#define VEC(type,name,size) vector<type> name(size); in(name)
#define vv(type,name,h,...) vector<vector<type>> name(h,vector<type>(__VA_ARGS__))
#define VV(type,name,h,w) vector<vector<type>> name(h,vector<type>(w)); in(name)
template<class T> inline const auto min(const T& a){ return *min_element(all(a));}
template<class T> inline const auto max(const T& a){ return *max_element(all(a));}
inline const ll popcnt(const ull a){return __builtin_popcountll(a);}
inline const ll gcd(ll a,ll b){while(b){ll c=b; b=a%b;a=c;}return a;}
inline const ll lcm(ll a,ll b){unless(a&&b) return 0;return a*b/gcd(a,b);}
inline const ll intpow(ll a,ll b){ll ans=1; while(b){if(b&1)ans*=a;a *=a; b/=2;}return ans;}
inline const ll modpow(ll a,ll b, ll p=mod){ll ans=1; while(b){if(b&1)(ans*=a)%=p;(a*=a)%=p;b/=2;}return ans;}
template<class T,class U>inline const bool chmin(T& a,const U& b){if(a>b){a=b;return 1;}return 0;}
template<class T,class U>inline const bool chmax( T& a,const U& b){if(a<b){a=b;return 1;}return 0;}
inline const vector<ll> iota(const ll n){vector<ll> a(n); iota(all(a),0);return a;}
inline const vector<pll> factor(ull x){vector<pll> ans; for(ull i=2;i*i<=x;i++)if(x%i==0){ans.push_back({i,1});while((x/=i)%i==0)ans.back().second++;}if(x!=1)ans.push_back({x,1});return ans;}
inline const map<ll,ll> factor_map(ull x){map<ll,ll> ans; for(ull i=2; i*i<=x;i++)if(x%i==0){ans[i]=1;while((x/=i)%i==0)ans[i]++;}if(x!=1)ans[x]=1;return ans;}
inline const vector<ll> divisor(ull x){vector<ll> ans; for(ull i=2;i*i<=x;i++)if(x%i==0)ans.push_back(i);rrep(ans.size()-(ans.back()*ans.back()==x))ans.push_back(x/ans[i]);return ans;}
inline const int scan() {return getchar();}
inline const void scan(int &a){scanf("%d", &a);}
inline const void scan(unsigned& a){scanf("%u",&a);}
inline const void scan(long& a){scanf("%ld",&a);}
inline const void scan(long long& a){scanf("%lld", &a);}
inline const void scan(char& a){ do{a=getchar();}while(a==' '||a=='\n');}
inline const void scan(float& a){ scanf("%f",&a);}
inline const void scan(double& a){ scanf("%lf",&a);}
inline const void scan(long double& a){ scanf("%Lf",&a);}
inline const void scan( string& a){cin>> a;}
template<class T>inline const void scan( vector<T>& a){for(auto&& i:a)scan(i);}
template<class T,size_t size>inline const void scan(array<T, size>& a){for(auto&& i:a)scan(i);}
template<class T,class L>inline const void scan( pair<T,L>&p){scan(p.first);scan(p.second);}
template<class T,size_t size>inline const void scan( T (&a)[size]){ for(auto&& i:a)scan(i);}
inline const void in(){}
template <class Head,class... Tail>inline const void in( Head& head, Tail&... tail){scan(head);in(tail...);}
inline const int ctoi(const char c){if(c>='a'&&c<='z'){return c-'a';} if(c>='A'&&c<='Z'){return c-'A';}return -1;}
inline const void print(){putchar(' ');}
inline const void print(const bool a){printf("%d", a);}
inline const void print(const int a){printf("%d",a);}
inline const void print(const unsigned a){ printf("%u",a);}
inline const void print(const long a){printf("%ld",a);}
inline const void print(const unsigned long long a){printf("%llu",a);}
inline const void print(const char a){ printf("%c",a);}
inline const void print(const double a){printf("%.15f",a);}
inline const void print(const long double a){printf("%.15Lf",a);}
inline const void print(const string&a){for(auto&&i :a)print(i);}
template<class T> inline const void print(const vector<T> &a){if(a.empty())return ;print(a[0]);for(auto i=a.begin();++i!=a.end();){putchar(' ');print(*i);}}
template<class T> inline const void print(const deque<T>&a ){if(a.empty())return;print(a[0]);for(auto i=a.begin(); ++i!=a.end();){putchar(' ');print(*i);}}
template<class T, size_t size>inline const void print(const T (&a)[size]){print(a[0]);for(auto i=a;++i!=end(a);){putchar(' ');print(*i);}}
template<class T>inline const void print(const T& a){cout<<a;}
inline const int out(){putchar('\n');return 0;}
template<class T> inline const int out(const T& t){print(t);putchar('\n');return 0;}
template<class Head,class... Tail>inline const int out(const Head& head,const Tail&... tail){print(head);putchar(' ');out(tail...);return 0;}
inline const int first(const bool i){return out(i?"first":"second");}
inline const int yes(const bool i){return out(i?"yes":"no");}
inline const int Yes(const bool i){return out(i?"Yes":"No");}
inline const int YES(const bool i){return out(i?"YES":"NO");}
inline const int possible(const bool i){return out(i?"possible":"impossible");}
inline const int Possible(const bool i){return out(i?"Possible":"Impossible");}
inline const int POSSIBLE(const bool i){return out(i?"POSSIBLE":"IMPOSSIBLE");}

 
using Graph = vector<vector<int>>;
using Graphw = vector<vector<pair<ll,ll>>>;
using mat = vector<vector<ll>>;
using vec = vector<ll>;

/*
namespace mp = boost::multiprecision;
// 任意長整数型
using Bint = mp::cpp_int;
// 仮数部長が32の浮動小数点数型
using Real32 = mp::number<mp::cpp_dec_float<32>>;
// 仮数部長が1024の浮動小数点数型
using Real1024 = mp::number<mp::cpp_dec_float<1024>>;
// 有理数型
using Rat = boost::rational<Bint>;
*/



signed main(){

INT(N);
map<string,int> score;
map<string,bool>seen;
vector<string> list;
rep(i,N){
    STR(s);
    if(!seen[s]){
        seen[s]=true;
        list.push_back(s);
    }
    score[s]++;
}
INT(M);
rep(i,M){
    STR(t);
    if(!seen[t]){
        seen[t]=true;
        list.push_back(t);
    }
    score[t]--;
}
int max_=0;
rep(i,list.size()){
    chmax(max_,score[list[i]]);
}
out(max_);
}