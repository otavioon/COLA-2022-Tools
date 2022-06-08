#pragma region template
#ifdef ONLINE_JUDGE
  #pragma GCC target("avx2")
  #pragma GCC optimize("O3")
  #pragma GCC diagnostic ignored "-Wunused-result"
  #include <bits/stdc++.h>
  #define here
  #define cprint(vec)
  #define com(msg)
  #define obs(...)
  #define local(x)
  #define alter(x,y) y
#else
  #include <bits/stdc++.h>
  #define here cerr<<__func__<<'/'<<__LINE__<<": reached\n"
  #define cprint(vec) dmp(vec)
  #define com(msg) cerr<<"{ "<<msg<< " }\n"
  #define obs(...) observe(#__VA_ARGS__, __VA_ARGS__)
  #define local(x) x
  #define alter(x,y) x
#endif

#define all(a) (a).begin(),(a).end()
#define rep(i,n) for(int i=0,i##_len=(n);i<i##_len;i++)
#define brep(i,a,b) for(int i=(a),i##_len=(b);i<=i##_len;i++)
#define rrep(i,n) for(int i=(n)-1,now=0;i>=0;i--,now++)
#define xrep(i,n) for(int i=1,i##_len=(n);i<=i##_len;i++)
#define yes(n) cout<<((n)?YES:NO)<<'\n'
#define co(n) cout<<n<<'\n'
#define cco(...) prints(__VA_ARGS__)
#define fout cout<<fixed<<setprecision(15)
#define Sort(v) sort(all(v))
#define rSort(v) sort(all(v),greater<typeof(v[0])>())
#define Rev(v) reverse(all(v))
#define Unique(v) (v).erase(unique(all(v)),(v).end())
#define in_range(x,a,b) ((a)<=(x)&&(x)<(b))
#define in_area(x,y,a,b) (0<=(x)&&0<=(y)&&(x)<(a)&&(y)<(b))
#define br puts("")
#define eb emplace_back

using namespace std;
using ll    = long long;
using ld    = long double;
using pt    = pair<int,int>;
using ull   = unsigned long long;
using str   = string;
using vbl   = vector<bool>;
using dqbl  = deque<bool>;
using vint  = vector<int>;
using vll   = vector<long long>;
using vld   = vector<long double>;
using vpt   = vector<pair<int,int>>;
using vstr  = vector<string>;
using vvbl  = vector<vector<bool>>;
using vdqbl = vector<deque<bool>>;
using vvint = vector<vector<int>>;
using vvll  = vector<vector<long long>>;

constexpr int         INF   = 1e9;
constexpr long long   LINF  = 1e18;
constexpr double      EPS   = 1e-9;
constexpr long double LEPS  = 1e-18;
constexpr int         dy4[] = {1,0,-1,0};
constexpr int         dx4[] = {0,1,0,-1};
constexpr int         dy8[] = {1,1,1,0,-1,-1,-1,0};
constexpr int         dx8[] = {-1,0,1,1,1,0,-1,-1};

// --- functions which take 1 argument --- //
template<class T> int sgn(const T &x){return (x>0)-(x<0);}
template<class S,class T> int digit(S x,const T &b=10){int r=1;while((x/=b)>=1)r++;return r;}
template<class T> double degToRad(const T &a){return a/180.0*M_PI;}
template<class T> double radToDeg(const T &a){return a/M_PI*180.0;}
template<class T> long long factorial(const T &n) {if(n==0)return 1;long long r=1;brep(i,2,n)r*=i;return r;}
template<class T> bool isPrime(const T &n){T i=2;while(i*i<=n){if(n%i==0&&n!=i)return 0;i++;}return 1;}
template<class T> map<T,T> factorize(T n){map<T,T>r;for(T i=2;i*i<=n;i++){while(n%i==0){r[i]++;n/=i;}}if(n!=1)r[n]=1;return r;}
template<class T> vector<T> divisor(const T &n){vector<T>r;for(T i=1;i*i<=n;i++){if(!(n%i)){r.eb(i);if(i*i!=n)r.eb(n/i);}}return r;}

// --- functions which take more than 1 argument --- //
template<class S,class T> bool chmax(S &a,const T &b){if(a<b){a=b;return true;}return false;}
template<class S,class T> bool chmin(S &a,const T &b){if(a>b){a=b;return true;}return false;}
template<class S,class T> bool near(const S &a, const T &b){return abs(a-b)<EPS;}
template<class S,class T> long long bpow(S m,T n){long long r=1;while(n>0){if(n&1)r*=m;m*=m;n/=2;}return r;}
template<class S,class T> typename common_type<S,T>::type min(const S &m,const T &n){return min((typename common_type<S,T>::type)m,(typename common_type<S,T>::type)n);}
template<class S,class T> typename common_type<S,T>::type max(const S &m,const T &n){return max((typename common_type<S,T>::type)m,(typename common_type<S,T>::type)n);}
template<class S,class T> typename common_type<S,T>::type nPr(const S &n,const T &k){if(n<k||n<0||k<0)return 0;T r=1;brep(i,n-k+1,n)r*=i;return r;}
template<class S,class T> typename common_type<S,T>::type nCr(const S &n,T k){if(n<k||n<0||k<0)return 0;T r=1;k=min(k,n-k);brep(i,n-k+1,n)r*=i;return r/factorial(k);}
template<class T>            void prints(const T &v){cout<<v<<'\n';}
template<class S,class... T> void prints(const S &v,const T&... w){cout<<v<<' ';prints(w...);}

// --- functions which take vector/deque as argument --- //
template<class T> void printD(const vector<T> &v,string d){rep(i,sz(v)-1)cout<<v[i]<<d;cout<<*v.rbegin()<<'\n';}
template<class T> void printD(const vector<vector<T>> &v,string d){for(const auto &x:v)printD(x,d);}
template<class T> bool in(const T &k,const vector<T> &v)          {return find(all(v),k)!=v.end();}
                  bool in(const int &k,const vector<long long> &v){return find(all(v),k)!=v.end();}
                  bool in(const long long &k,const vector<int> &v){return find(all(v),k)!=v.end();}
                  bool in(const char &k,const string &v)          {return find(all(v),k)!=v.end();}
                  bool in(const char* k,const vector<string> &v)  {return find(all(v),k)!=v.end();}
template<class T> double veclen(const vector<T> &v){return sqrt(reduce(all(v),0.0,[](T s,T v){return s+=v*v;}));}
template<class T> T min(const vector<T> &v){return *min_element(all(v));}
template<class T> T max(const vector<T> &v){return *max_element(all(v));}
template<class T> T sum(const vector<T> &v){return reduce(all(v),(T)0);}
template<class T> T gcd(const vector<T> &v){T r=v[0];brep(i,1,(int)v.size()-1)r=gcd(r,v[i]);return r;}
template<class T> T lcm(const vector<T> &v){T r=v[0];brep(i,1,(int)v.size()-1)r=lcm(r,v[i]);return r;}
template<class T> T vectorAdd(const T &u,const T &v)     {T r(u.size());rep(i,u.size())r[i]=u[i]+v[i];return r;}
template<class T> T vectorSubtract(const T &u,const T &v){T r(u.size());rep(i,u.size())r[i]=u[i]-v[i];return r;}
template<class T> T vectorMultiply(const T &u,const T &v){T r(u.size());rep(i,u.size())r[i]=u[i]*v[i];return r;}
template<class T> T vectorDivide(const T &u,const T &v)  {T r(u.size());rep(i,u.size())r[i]=u[i]/v[i];return r;}
template<class T> T dotProduct(const deque<bool> &u,const vector<T> &v){T r=0;rep(i,u.size())if(u[i])r+=v[i];return r;}
template<class S,class T> typename common_type<S,T>::type dotProduct(const vector<S> &u,const vector<T> &v){T r=0;rep(i,u.size())r+=u[i]*v[i];return r;}
template<class S,class T> void sortBySecond(vector<pair<S,T>> &v){sort(all(v),[](auto L,auto R){return L.second<R.second;});}

// --- functions which take set/map as argument --- //
template<class T> T min(const set<T> &v){return *min_element(all(v));}
template<class T> T max(const set<T> &v){return *max_element(all(v));}
template<class T> T sum(const set<T> &v){return reduce(all(v),(T)0);}
template<class T> T gcd(const set<T> &v){T r=0;for(const T &x:v)r=(r==0)?x:gcd(r,x);return r;}
template<class T> T lcm(const set<T> &v){T r=0;for(const T &x:v)r=(r==0)?x:lcm(r,x);return r;}
template<class T> bool in(const T &k,const set<T> &v){return find(all(v),k)!=v.end();}
template<class S,class T> pair<S,T> min(const map<S,T> &m){pair<S,T> r=*m.begin();for(const auto& p:m)if(chmin(r.second,p.second))r=p;return r;}
template<class S,class T> pair<S,T> max(const map<S,T> &m){pair<S,T> r=*m.begin();for(const auto& p:m)if(chmax(r.second,p.second))r=p;return r;}

// --- functions for debugging --- //
template<class T>            void observe(const char* n,T &&v)         {cerr<<n<<": "<<v<<'\n';}
template<class S,class... T> void observe(const char* n,S &&v,T&&... w){const char* c=strchr(n+1,',');cerr.write(n,c-n)<<": "<<v<<" |";observe(c+1,w...);}
template<class T> void dmp(const vector<T> &v)        {cerr<<"[ ";for(const T &x:v)cerr<<x<<' ';cerr<<"]\n";}
template<class T> void dmp(const deque<T> &v)         {cerr<<"[ ";for(const T &x:v)cerr<<x<<' ';cerr<<"]\n";}
template<class T> void dmp(const set<T> &v)           {cerr<<"[ ";for(const T &x:v)cerr<<x<<' ';cerr<<"]\n";}
template<class P> void dmp(const P &p)                {cerr<<"{ "<<p.first<<' '<<p.second<<" } ";}
template<class T> void dmp(const vector<vector<T>> &v){for(const auto &x:v)dmp<T>(x);}
template<class T> void dmp(const vector<deque<T>> &v) {for(const auto &x:v)dmp<T>(x);}
template<class S,class T> void dmp(const map<S,T> &m) {cerr<<"[ ";for(const auto &p:m)cerr<<"{ "<<p.first<<", "<<p.second<<" } ";cerr<<"]\n";}
template<class S,class T> void dmp(const vector<pair<S,T>> &v){cerr<<"[ ";for(const auto &x:v)dmp<pair<S,T>>(x);cerr<<"]\n";}
#pragma endregion template

ll N, K;
vector<ll> A;

bool possible(ll len) {
  ll cnt = 0;
  for (auto &&x : A) {
    cnt += x / len;
  }

  return cnt <= K;
}

void solve() {
  ll low = 0, high = max(A), mid;

  while (high - low > 1) {
    mid = low + ((high - low) >> 1);
    obs(low, mid, high);
    (possible(mid) ? high : low) = mid;
  }

  cout << high << '\n';
}

int main() {
  scanf("%lld",&N);
  scanf("%lld",&K);
  A.resize(N);
  for(int i = 0 ; i < N ; i++){
    scanf("%lld",&A[i]);
  }
  solve();
  return 0;
}
