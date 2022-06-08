#include <bits/stdc++.h>
using namespace std;

template <class T> using V = vector<T>;
template <class S, class T> using P = pair<S, T>;

using ll = long long;
using ull = unsigned long long;
using vll = V<ll>;
using vvll = V<vll>;
using vvvll = V<vvll>;
using pl = P<ll, ll>;
using vpl = V<pl>;
using vvpl = V<vpl>;
using vs = V<string>;
using qll = queue<ll>;
using qpl = queue<pl>;
using mapll = map<ll, ll>;
using setll = set<ll>;
using pqll = priority_queue<ll>;

#define int ll
#define fi first
#define se second
#define mp make_pair
#define pb push_back
#define pob pop_back()
#define pf push_front
#define pof pop_front()
#define sz size()
#define bgn begin()
#define en end()
#define emp empty()
#define fr front()
#define bk back()
#define res resize
#define tp top()
#define p_q priority_queue
#define inv inverse()

#define FOR(i,a,b) for(ll i=(a);i<=(ll)(b);i++)
#define rFOR(i,a,b) for(ll i=(b);i>=(ll)(a);i--)
#define REP(i,a) FOR((i),0,(ll)(a)-1)
#define REP0(i,a) FOR((i),0,(ll)(a))
#define REP1(i,a) FOR((i),1,(ll)(a))
#define rREP(i,a) rFOR((i),0,(ll)(a)-1)
#define rREP0(i,a) rFOR((i),0,(ll)(a))
#define rREP1(i,a) rFOR((i),1,(ll)(a))
#define IOTA(a,n) iota((a).bgn,(a).en,(n))
#define SORT(a) sort((a).bgn,(a).en)
#define rSORT(a) sort((a).rbegin(),(a).rend())
#define UNIQUE(a) (a).erase(unique((a).bgn,(a).en),(a).en)
#define BINS(a,b) binary_search((a).bgn,(a).en,(b))
#define LOWB(a,b) (lower_bound((a).bgn,(a).en,(b))-(a).bgn)
#define UPB(a,b) (upper_bound((a).bgn,(a).en,(b))-(a).bgn)
#define CNT(a,b) count((a).bgn,(a).en,b)
#define SUM(a) accumulate((a).bgn,(a).en,0)
#define REV(a) reverse((a).bgn,(a).en)
#define yn(a) cout <<((a)?"yes":"no")<<"\n";
#define Yn(a) cout <<((a)?"Yes":"No")<<"\n";
#define YN(a) cout <<((a)?"YES":"NO")<<"\n";
#define imp(a) cout <<((a)?"possible":"impossible")<<"\n";
#define Imp(a) cout <<((a)?"Possible":"Impossible")<<"\n";
#define IMP(a) cout <<((a)?"POSSIBLE":"IMPOSSIBLE")<<"\n";
#define dbg(a) cerr <<(#a)<<": "<<(a)<<"\n";
#define DigN2(a) ((llabs(a)==0)?(1):((ll)(log2(double(llabs(a))))+1))
#define DigN10(a) ((llabs(a)==0)?(1):((ll)(log10(double(llabs(a))))+1))
#define Dig2(a,b) (((a)>>(b))&1)
#define Dig10(a,b) (ll)(((a)/((ll)(pow(10.0,(double)(b)))))%10)
#define Pow2(a) ((ll)(1)<<(a))
#define Pow10(a) ((ll)(pow(10.0,double(a))))
#define powll(a,b) (ll)(pow((double)(a),(double)(b)))

#define li(...) ll __VA_ARGS__;Input(__VA_ARGS__);
#define si(...) string __VA_ARGS__;Input(__VA_ARGS__);
#define vli(size, ...) vll __VA_ARGS__;vInput(size,__VA_ARGS__);
#define vsi(size, ...) vs __VA_ARGS__;vInput(size,__VA_ARGS__);

const ll MOD = 1e9 + 7;
//const ll MOD = 998244353;
//const ll MOD = 924844033;
//const ll MOD = 9007199254740881;
const ll INF = 1LL << 60;//1.15e18
const double PI = acos(-1.0);
const string alp = "abcdefghijklmnopqrstuvwxyz";
const string ALP = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";

void Input() {}
template <class Var, class... Args> void Input(Var& var, Args&... args) {
    cin >> var;
    Input(args...);
}

void vInit(ll size) {}
template <class T, class... Args> void vInit(ll size, V<T>& v, Args&... args) {
    v.res(size);
    vInit(size, args...);
}
void vInputNum(ll num) {}
template <class T, class... Args> void vInputNum(ll num, V<T>& v, Args&... args) {
    cin >> v[num];
    vInputNum(num, args...);
}
void vInput(ll size) {}
template <class... Args> void vInput(ll size, Args&... args) {
    vInit(size, args...);
    REP(i, size) vInputNum(i, args...);
}

template <class S, class T> ostream &operator<<(ostream &out, const P<S, T> &p) {
    return out << "[" << p.fi << ", " << p.se << "]";
}
 
template <class T> ostream &operator<<(ostream &out, V<T> &v) {
    if (v.emp) return out << "{}";
    else {
        auto itr = v.bgn;
        out << "{" << *itr;
        itr++;
        while (itr != v.en) {
            out << ", " << *itr;
            itr++;
        }
        out << "}";
        return out;
    }
}
 
template <class S, class T> ostream &operator<<(ostream &out, const map<S, T> &m) {
    if (m.emp) return out << "<[]>";
    else {
        auto itr = m.bgn;
        out << "< [" << (itr->fi) << ": " << (itr->se);
        itr++;
        while (itr != m.en) {
            out << "], [" << (itr->fi) << ": " << (itr->se);
            itr++;
        }
        out << "] >";
        return out;
    }
}
 
template <class T> ostream &operator<<(ostream &out, const set<T> &s) {
    if (s.emp) return out << "<>";
    else {
        auto itr = s.bgn;
        out << "<" << *itr;
        itr++;
        while (itr != s.en) {
            out << ", " << *itr;
            itr++;
        }
        out << ">";
        return out;
    }
}

ll gcd(ll a, ll b) { if (a < b) { a ^= b; b ^= a; a ^= b; } return b ? gcd(b, a%b) : a; }
ll lcm(ll a, ll b) { return a / gcd(a, b)*b; }

struct UFT {

public:
    ll tsize;
    ll mode;
    vll par;
    vll rank;
    UFT() {}
    UFT(const UFT &uft) {}
    UFT(ll tsizeget, ll modeget = 0){
        tsize = tsizeget;
        mode = modeget;
        par.assign(tsize, -1);
        if (!mode) rank.res(tsize, 0);
    }
    ll root(ll x) {
        return par[x] < 0 ? x : par[x] = root(par[x]);
    }
    bool isRoot(ll x) {
        return x == root(x);
    }
    bool same(ll x, ll y) {
        return root(x) == root(y);
    }
    void merge(ll x, ll y) {
        x = root(x);
        y = root(y);
        if (x == y) return;
        if (mode) {
            par[x] += par[y];
            par[y] = x;
        }
        else {
            if (rank[x] < rank[y]) {
                par[y] += par[x];
                par[x] = y;
            }
            else {
                par[x] += par[y];
                par[y] = x;
                if (rank[x] == rank[y]) rank[x]++;
            }
        }
    }
    ll size(ll x) {
        return -par[root(x)];
    }
};

ll isP(ll n) {
    if (n <= 1) return 0;
    FOR(i, 2, (ll)sqrt(n) + 1) {
        if (n%i == 0) return 0;
    }
    return 1;
}

vvll CombMemo(1000, vll(1000, -1));

ll Comb(ll n, ll k) {
    if ((n < 0) || (k < 0)) return 0;
    if (CombMemo[n][k] == -1) {
        if (n < k) CombMemo[n][k] = 0;
        else {
            if (n == 0) CombMemo[n][k] = 1;
            else if (k == 0) CombMemo[n][k] = 1;
            else if (n == k) CombMemo[n][k] = 1;
            else CombMemo[n][k] = Comb(n - 1, k - 1) + Comb(n - 1, k);
        }
    }
    return CombMemo[n][k];
}

void Solve();

signed main() { 
    cin.tie(0);
    ios::sync_with_stdio(false);
    cout << setprecision(20) << fixed;
    Solve();
}

void Solve() {
  li(n,d);
  ll a=d*2+1;
  cout << ((n%a)?(n/a+1):n/a);
}











