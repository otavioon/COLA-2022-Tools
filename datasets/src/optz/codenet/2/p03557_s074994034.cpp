#define _GLIBCXX_DEBUG
#include"bits/stdc++.h"

using namespace std;

//loops
#define REP(i,n) for(int i=0;i<(ll)(n);i++)
#define REPD(i,n) for(int i=(ll)(n)-1;i>=0;i--)
#define OneToN(i,n) for(int i=1;i<(ll)(n+1);i++)
#define ZeroToN(i,n) for(int i=0;i<(ll)(n+1);i++)
#define AToB(i,a,b) for(int i=a;i<(ll)(b+1);i++)
#define FOR(i,a,b) for(int i=(a);i<=(b);i++)
#define FORD(i,a,b) for(int i=(a);i>=(b);i--)

//bitsearch
#define BITSEARCH(bit, n) for (int bit = 0; bit < (1<<n); ++bit)
#define isOne(bit, i) bit & (1<<i)


//arrays
#define ALL(x) (x).begin(),(x).end() //sortなどの引数を省略したい
#define SIZE(x) ((ll)(x).size()) //sizeをsize_tからllに直しておく
#define add push_back


#define remove_unique(v) v.erase(unique(ALL(v)), v.end())

//pair
#define fir first
#define sec second

//types
#define ll long long
#define vec vector
#define cord2d pair<int,int>
//UNCOMMENT WHEN NEEDED
#define int ll

//input
template <class T> T get(){ T s; cin >> s; return(s);}
#define gi get<int>()
#define gs get<string>()

template <class T> vector<T> getv(int n) { vec<T> v(n); REP(i, n) cin >> v[i]; return v; }
#define gim(n) getv<int>(n)
#define gsm(n) getv<string>(n)

//output
void print(int a){ cout << a << endl; }
void print(string a){ cout << a << endl; }
void print(char a){ cout << a << endl; }
void print(double a){ cout << a << endl; }
void print(double a, int dig){ cout << std::setprecision(dig) << a << endl; }

template <class T>ostream &operator<<(ostream &o,const vector<T>&v)
{o<<"{";for(int i=0;i<(int)v.size();i++)o<<(i>0?", ":"")<<v[i];o<<"}";return o;}

template <class T = int>
void print(vec<T> v){ cout << v << endl; }

template <class T = int>
void print2dVec(vec<vec<T>> v2d){for(vec<T> v: v2d) {print(v);}}

void YesNo1(bool i = true){ return print(i?"Yes":"No"); }
void YESNO2(bool i = true){ return print(i?"YES":"NO"); }

//debug output
#define var_name(var) #var
template <class T> void debug(T &var, int nest = 0, string before = "") { cout << string("          ", nest) << before; print(var); }

//name replacement
#define y0 y0__
#define y1 y1__
#define j0 j0__
#define j1 j1__

//bool lambdas
#define lamb(exp) [](auto i){return exp;}
#define isEven [](int i){return i % 2 == 0;}
#define isOdd [](int i){return i % 2 != 0;}

//constants
const ll INF = 1e18;
const int MOD = 10000007;

//maths
int factorial(int k){ int sum = 1; for (int i = 1; i <= k; ++i) { sum *= i; } return sum; }
int gcd(int a, int b) {
    if (b == 0)
        return a;
    return gcd(b, a % b);
}

void Main() {
    //code here
    int n = gi;
    vec<int> as = gim(n);
    vec<int> bs = gim(n);
    vec<int> cs = gim(n);
    sort(ALL(as));
    sort(ALL(bs));
    sort(ALL(cs));
    //print(as);print(bs);print(cs);
    int res = 0;
    vec<int> b_counts;
    for(int b: bs) {
        auto cPlace = upper_bound(ALL(cs), b);
        if (cPlace != cs.end()) {
            b_counts.add(n - (int)(cPlace - cs.begin()));
        } else {
            b_counts.add(0);
        }
    }
    //print(b_counts);
    vec<int> b_countsums = {0};
    REP(i, n) { //累積和
        b_countsums.add(b_counts[n-i-1] + *b_countsums.rbegin());
    }
    reverse(ALL(b_countsums));
    //print(b_countsums);
    for(int a: as) {
        auto bPlace = upper_bound(ALL(bs), a);
        if (bPlace != bs.end()) {
            res += b_countsums[bPlace - bs.begin()];
        }
    }
    print(res);
}

signed main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    Main();
}
