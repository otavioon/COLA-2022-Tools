#include "bits/stdc++.h"
#define _USE_MATH_DEFINES
#include <math.h>
 
using namespace std;
 
using LL = long long;
using VLL = std::vector<LL>;
using VVLL = std::vector<VLL>;
using VVVLL = std::vector<VVLL>;
using LD = long double;
using VLD = std::vector<LD>;
using VVLD = std::vector<VLD>;
using VVVLD = std::vector<VVLD>;
using BL = bool;
using VBL = std::vector<BL>;
using VVBL = std::vector<VBL>;
using VVVBL = std::vector<VVBL>;
 
template<class T> inline bool chmax(T &a, T b) { if (a < b) { a = b; return true; }return false; }
template<class T> inline bool chmin(T &a, T b) { if (a > b) { a = b; return true; }return false; }
 
//template<class T=LL> inline vector<T> cinv(LL N){ vector<T> v(N); REP(i, N)cin>>v[i]; return move(v);}
//template<class T=LL> inline vector<T> cinv(LL N){ vector<T> v(N); REP(i, N)cin>>v[i]; return move(v);}
#define REP(i,n) for(LL (i)=0;(i)<(n);(i)++)
#define REPM(i,n,m) for(LL (i)=m;(i)<(n);(i)++)
#define ALL(v) v.begin(), v.end()
#define PRINTLN(v) {LL i=0; for(auto (a): v ){   cerr <<i << " : "<<  a << endl; i++;}}
//#define PRLLSP(v) for(auto (a): v ) {cerr << a << " ";} cerr << endl
 
 
template<class T> 
void PRINTSP(vector<T> v, size_t w=3){
  for(auto (a): v ) {cerr <<setw(w)<< a << " ";} cerr << endl;
} 
 
 
struct mll{
	static LL MOD;
	LL val;
	mll(LL v = 0): val(v % MOD){ if (val < 0) val += MOD; }
	mll operator - () const { return -val; }
	mll operator + (const mll &b) const { return val + b.val; }
	mll operator - (const mll &b) const { return val - b.val; }
	mll operator * (const mll &b) const { return val * b.val; }
	mll operator / (const mll &b) const { return mll(*this) /= b; }
	mll operator + (LL b) const { return *this + mll(b); }
	mll operator - (LL b) const { return *this - mll(b); }
	mll operator * (LL b) const { return *this * mll(b); }
	friend mll operator + (LL a, const mll &b) { return b + a; }
	friend mll operator - (LL a, const mll &b) { return -b + a; }
	friend mll operator * (LL a, const mll &b) { return b * a; }
	mll &operator += (const mll &b) { val=(val+b.val)%MOD; return *this; }
	mll &operator -= (const mll &b) { val=(val+MOD-b.val)%MOD; return *this; }
	mll &operator *= (const mll &b) { val=(val*b.val)%MOD; return *this; }
	mll &operator /= (const mll &b) {
		LL c=b.val, d=MOD, u=1, v=0;
		while (d){
			LL t = c / d;
			c -= t * d; swap(c, d);
			u -= t * v; swap(u, v);
		}
		val = val * u % MOD;
		if (val < 0) val += MOD;
		return *this;
	}
	mll &operator += (LL b) { return *this += mll(b); }
	mll &operator -= (LL b) { return *this -= mll(b); }
	mll &operator *= (LL b) { return *this *= mll(b); }
	mll &operator /= (LL b) { return *this /= mll(b); }
	bool operator == (const mll &b) { return val == b.val; }
	bool operator != (const mll &b) { return val != b.val; }
	bool operator == (LL b) { return *this == mll(b); }
	bool operator != (LL b) { return *this != mll(b); }
	friend bool operator == (LL a, const mll &b) { return mll(a) == b.val; }
	friend bool operator != (LL a, const mll &b) { return mll(a) != b.val; }
	friend ostream &operator << (ostream &os, const mll &a) { return os << a.val; }
	friend istream &operator >> (istream &is, mll &a) { return is >> a.val; }
	static mll Combination(LL a, LL b){
		chmin(b, a-b);
		if (b<0) return mll(0);
		mll c = 1;
		REP(i, b) c *= a-i;
		REP(i, b) c /= i+1;
		return c;
	}
	static mll Kumiawase(LL a, LL b){
		chmin(b, a-b);
		if (b<0) return mll(0);
		return Junretu(a,b)/Kaijou(b);
	}
  static mll Kaijou(LL a){
		if (a<0)  return mll(0);
		mll c = 1;
    for(LL i=1;i<=a;i++){
      c *= i;
    }
    return c;
	}
	static mll Junretu(LL a, LL b){
    if(a<b){
      return mll(0);
    }
		mll c = 1;
    for(LL i=a;i>a-b;i--){
      c *= i;
    }
 
    return c;
	}
  static mll _Junretu(LL a, LL b){
    if(a<b){
      return mll(0);
    }
		return Kaijou(a)/(Kaijou(a-b));
	}
};
LL mll::MOD = (LL)(1e9 + 7);// 998244353LL;//(LL)(1e9 + 7);
using vmll = std::vector<mll>;
using vvmll = std::vector<vmll>;
using vvvmll = std::vector<vvmll>;
using vvvvmll = std::vector<vvvmll>;
 
 
template<typename TTT>
vector<LL> arg_sort(vector<TTT> A, bool ascend = true) {
  vector<LL> index(A.size());
  iota(index.begin(), index.end(), 0);
  if (ascend) {
    std::sort(index.begin(), index.end(), [&A](TTT i1, TTT i2) {
      return A[i1] < A[i2];
      });
  }
  else {
    std::sort(index.begin(), index.end(), [&A](TTT i1, TTT i2) {
      return A[i1] > A[i2];
      });
  }
 
  return index;
}

template<typename _Iterator, typename _Compare>
LL num_of_ika(_Iterator _first, _Iterator _last, _Compare key){
  return (LL)(upper_bound(_first,_last,key)-_first);
}
template<typename _Iterator, typename _Compare>
LL num_of_ookii(_Iterator _first, _Iterator _last, _Compare key){
  return (LL)(_last-upper_bound(_first,_last,key));
}
template<typename _Iterator, typename _Compare>
LL num_of_chisai(_Iterator _first, _Iterator _last, _Compare key){
  return (LL)(lower_bound(_first,_last,key) - _first);
}
template<typename _Iterator, typename _Compare>
LL num_of_ijou(_Iterator _first, _Iterator _last, _Compare key){
  return (LL)(_last-lower_bound(_first,_last,key));
}
template<typename _Iterator, typename _Compare>
LL num_of_onaji(_Iterator _first, _Iterator _last, _Compare key){
  return (LL)(upper_bound(_first,_last,key)-lower_bound(_first,_last,key));
}

struct UinonFindTree {
private:
  vector<LL> UFT;
public:
  UinonFindTree(LL N) {
    UFT.resize(N);
    for (LL i = 0; i < N; i++) {
      UFT[i] = -1; 
    }
  }
 
  LL root(LL i) { 
    if (UFT[i] < 0) {
      return i;
    }
    else {
      LL j = root(UFT[i]);
      UFT[i] = j;
      return j;
    }
  }
 
  bool same(LL i, LL j) {
    return (root(i) == root(j));
  }
 
  void unite(LL i, LL j)
  {
    LL root_i = root(i);
    LL root_j = root(j);
    if (root_i != root_j) {
      if (size(root_i) < size(root_j)) {
        swap(root_i, root_j);
      }
      UFT[root_i] += UFT[root_j];
      UFT[root_j] = root_i;
    }
  }
 
  LL size(LL i) {
    return -UFT[root(i)];
  }
 
  LL get_root_num() {
    set<LL> roots;
    for (LL i = 0; i < (LL)UFT.size(); ++i) {
      roots.insert(root(i));
    }
    return (LL)roots.size();
  }
 
  map<LL, vector<LL>> get_root_child() {
    map<LL, vector<LL>> a;
    for (LL i = 0; i < (LL)UFT.size(); ++i) {
      LL j = root(i);
      a[j].push_back(i);
    }
    return a;
  }
 
  void print() { 
    for (LL i = 0; i < (LL)UFT.size(); ++i) {
      cerr << root(i) << " ";
    }
    cerr << endl;
  }
};
 
 
 
#define cmax(a,b) {if(a<b){a=b;}}
#define cmin(a,b) {if(a>b){a=b;}}
#define EACH(a,A) for(auto a: A)
//#define cmax(a,b) a = (a>b ? a:b)
//#define cmin(a,b) a = (a<b ? a:b) 
//cin,cout高速化のおまじない＋桁数指定
inline VLL cinvll(LL N, LL minus = 0){
  VLL A(N);
  REP(i,N){
    cin >> A[i];
    A[i] -= minus;
  }
  return move(A);
}
inline VVLL zerosll(LL H, LL W, LL val=0){
  VVLL A(H,VLL(W,val));
  return move(A);
}
 
#define repi(itr, ds) for (auto itr = ds.begin(); itr != ds.end(); itr++)
 
// vector
template <typename T>
istream &operator>>(istream &is, vector<T> &vec) {
    for (T &x : vec) is >> x;
    return is;
}
// pair
template <typename T, typename U>
ostream &operator<<(ostream &os, pair<T, U> &pair_var) {
    os << "(" << pair_var.first << ", " << pair_var.second << ")";
    return os;
}
// vector
template <typename T>
ostream &operator<<(ostream &os, const vector<T> &vec) {
 
  for (LL i = 0; i < (LL)vec.size(); i++) {
    os << setw(5) << vec[i];
  } 
  os << endl;
  return os;
    
#if 0    
    os << "{";
    for (LL i = 0; i < (LL)vec.size(); i++) {
        os << vec[i] << (i + 1 == (LL)vec.size() ? "" : ", ");
    }
    os << "}";
    return os;
#endif
}
// map
template <typename T, typename U>
ostream &operator<<(ostream &os, map<T, U> &map_var) {
    os << "{";
    repi(itr, map_var) {
        os << *itr;
        itr++;
        if (itr != map_var.end()) os << ", ";
        itr--;
    }
    os << "}";
    return os;
}
// set
template <typename T>
ostream &operator<<(ostream &os, set<T> &set_var) {
    os << "{";
    repi(itr, set_var) {
        os << *itr;
        itr++;
        if (itr != set_var.end()) os << ", ";
        itr--;
    }
    os << "}";
    
    return os;
}
 
#define DUMPOUT cerr
#define DUMPCOLOR ("\033[36m")
 
void dump_func() {
    DUMPOUT << endl;
}
template <class Head, class... Tail>
void dump_func(Head &&head, Tail &&... tail) {
    DUMPOUT << DUMPCOLOR;
    DUMPOUT << head;
    if (sizeof...(Tail) > 0) {
        DUMPOUT << ", ";
    }
    dump_func(std::move(tail)...);
    DUMPOUT << "\033[m";
}
#ifdef DEBUG_
#define DEB
#define dump(...)                                                              \
    DUMPOUT << DUMPCOLOR                                                      \
            << "" << string(#__VA_ARGS__) << ": "                            \
            << "[" << to_string(__LINE__) << ":" << __FUNCTION__ << "]"        \
            << endl                                                            \
            << "\033[m"                                                        \
            << "",                                                         \
        dump_func(__VA_ARGS__)
#else
#define DEB if (false)
#define dump(...)
#endif
 
struct Fast{
	Fast(){
		cin.tie(0);
		ios::sync_with_stdio(false);
		cout << fixed << setprecision(std::numeric_limits<double>::max_digits10);
	}
} fast;
 
#if 0 
LL GCD(LL m, LL n) {
 
  if (m < n) {
    swap(m, n);
  }
 
  while (n != 0) {
    LL n_new = m % n;
    m = n;
    n = n_new;
  }
 
  return m;
 
}
 
VLL B;
VVLL T;
LL cnt=0;
void dfs(LL me,LL oya){
 
  for(LL i=0;i<T[me].size();i++){
    LL ko = T[me][i];
    if(ko==oya){
      continue;
    }
    cnt += min(B[me],B[ko]);
    dfs(ko,me);
  }
 
}
#endif
 

bool isPrime(LL N)
{
  if (N < 2) {
    return false;
  }
  else if (N == 2) {
    return true;
  }
  else if (N % 2 == 0) {
    return false;
  }

  LD sqrtNum = sqrt(N);
  for (LL i = 3; i <= sqrtNum; i += 2)
  {
    if (N % i == 0)
    {
      return false;
    }
  }
  return true;
}



VLL A;
LL N,M;
// index が条件を満たすかどうか
bool isOK(LL X) {

  LL cnt=0;
  REP(i,N){
    LL hidari=A[i];
    auto it = lower_bound(ALL(A),X-hidari);
    cnt += A.end()-it;
  }
  dump(cnt);
  if(cnt>=M){
    return true;
  }
  else{
    return false;
  }
}
// 汎用的な二分探索のテンプレ
LL binary_search() {
  LL ng = 1e10+1 ;
  LL ok = 0;

  /* ok と ng のどちらが大きいかわからないことを考慮 */
  while (abs(ok - ng) > 1) {
      LL mid = (ok + ng) / 2;

      if (isOK(mid)) ok = mid;
      else ng = mid;
  }
  return ok;
}

map< LL, LL > prime_factor(LL n) {
  map< LL,LL > ret;
  for(LL i = 2; i * i <= n; i++) {
    while(n % i == 0) {
      ret[i]++;
      n /= i;
    }
  }
  if(n != 1) ret[n] = 1;
  return ret;
}

void func()
{
  LL N,K;
  cin >>K>>N;
  if(500*K>=N){
    cout << "Yes";
  }
  else{
    cout << "No";
  }

  return;
}

int main()
{
  func();
  return 0;
}
 