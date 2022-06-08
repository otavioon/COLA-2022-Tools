#include<bits/stdc++.h>

#define rep(i,n) for (int i = 0; i < (n); ++i)

using namespace std;
typedef pair<int, int> P;
typedef long long ll;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }

//最大公約数
ll gcd(ll x, ll y) {
    ll tmp = 0;
    if (x < y){
        tmp=x;
        x=y;
        y=tmp;
    }
    while (y > 0) {
        ll r = x % y;
        x = y;
        y = r;
        }
    return x;
}

//最大公倍数
ll lcm(ll x,ll y){
    return x/gcd(x,y)*y;
}

const int MAX = 1e6+1;
const ll MOD = 1e9+7;

long long fac[MAX], finv[MAX], inv[MAX];

// テーブルを作る前処理
void COMinit() {
    fac[0] = fac[1] = 1;
    finv[0] = finv[1] = 1;
    inv[1] = 1;
    for (int i = 2; i < MAX; i++){
        fac[i] = fac[i - 1] * i % MOD;
        inv[i] = MOD - inv[MOD%i] * (MOD / i) % MOD;
        finv[i] = finv[i - 1] * inv[i] % MOD;
    }
}

struct mint {
  ll x; // typedef long long ll;
    mint(ll x=0):x((x%MOD+MOD)%MOD){}
    mint operator-() const { return mint(-x);}
    mint& operator+=(const mint a) {
    if ((x += a.x) >= MOD) x -= MOD;
    return *this;
    }
    mint& operator-=(const mint a) {
    if ((x += MOD-a.x) >= MOD) x -= MOD;
    return *this;
    }
    mint& operator*=(const mint a) {
        (x *= a.x) %= MOD;
        return *this;
    }
    mint operator+(const mint a) const {
        mint res(*this);
        return res+=a;
    }
    mint operator-(const mint a) const {
        mint res(*this);
        return res-=a;
    }
    mint operator*(const mint a) const {
        mint res(*this);
        return res*=a;
    }
    mint pow(ll t) const {
        if (!t) return 1;
        mint a = pow(t>>1);
        a *= a;
        if (t&1) a *= *this;
        return a;
    }

    // for prime MOD
    mint inv() const {
        return pow(MOD-2);
    }
    mint& operator/=(const mint a) {
        return (*this) *= a.inv();
    }
    mint operator/(const mint a) const {
        mint res(*this);
        return res/=a;
    }
};

// 二項係数計算
long long COM(int n, int k){
    if (n < k) return 0;
    if (n < 0 || k < 0) return 0;
    return fac[n] * (finv[k] * finv[n - k] % MOD) % MOD;
}


//階乗
ll kaijo(ll k){
    ll sum = 1;
    for (ll i = 1; i <= k; ++i)
    {
        sum *= i;
        sum%=1000000000+7;
    }
    return sum;
}

long long modpow(long long a, long long n, long long MOD) {
    long long res = 1;
    while (n > 0) {
        if (n & 1) res = res * a % MOD;
        a = a * a % MOD;
        n >>= 1;
    }
    return res;
}

// //sieve(MAX);でベクトルIsPrimeに「MAXまでの数値の素数の真偽」を格納する。
// struct Sieve {
//     int n;
//     vector<int> f, primes;
//     Sieve(int n=1):n(n), f(n+1) {
//         f[0] = f[1] = -1;
//         for (ll i = 2; i <= n; ++i) {
//         if (f[i]) continue;
//         primes.push_back(i);
//         f[i] = i;
//         for (ll j = i*i; j <= n; j += i) {
//             if (!f[j]) f[j] = i;
//         }
//         }
//     }
//     bool isPrime(int x) { return f[x] == x;}
//     vector<int> factorList(int x) {
//         vector<int> res;
//         while (x != 1) {
//         res.push_back(f[x]);
//         x /= f[x];
//         }
//         return res;
//     }
//     vector<P> factor(int x) {
//         vector<int> fl = factorList(x);
//         if (fl.size() == 0) return {};
//         vector<P> res(1, P(fl[0], 0));
//         for (int p : fl) {
//         if (res.back().first == p) {
//             res.back().second++;
//         } else {
//             res.emplace_back(p, 1);
//         }
//         }
//         return res;
//     }
// };
struct UnionFind {
    vector<int> par;
    UnionFind(int n) : par(n, -1) { }
    int root(int x) {
        if (par[x] < 0) return x;
        else return par[x] = root(par[x]);
    }
    bool issame(int x, int y) {
        return root(x) == root(y);
    }
    bool merge(int x, int y) {
        x = root(x); y = root(y);
        if (x == y) return false;
        if (par[x] > par[y]) swap(x, y); // merge technique
        par[x] += par[y];
        par[y] = x;
        return true;
    }
    ll size(int x) {
        return -par[root(x)];
    }
};

ll count(int n, int a){
    ll bunshi = 1;
    for(int i = 0; i < a; i++){
        bunshi*=(n-i);
        bunshi%=MOD;
    }
    ll bunbo = 1;
    for(int i = 1; i < a+1; i++){
        bunbo*=i;
        bunbo%=MOD;
    }
    bunbo = modpow(bunbo,MOD-2,MOD);
    // cout<<(bunshi*bunbo)%MOD<<endl;
    return (bunshi*bunbo)%MOD;
}

// 約数列挙。約数をvector<ll>で返す。計算量はsqrt(n)。
vector<ll> divisor(ll n) {
    vector<ll> ret;
    for(ll i = 1; i * i <= n; i++) {
        if(n % i == 0) {
        ret.push_back(i);
        if(i * i != n) ret.push_back(n / i);
        }
    }
    sort(begin(ret), end(ret));
    return (ret);
}

// ここから開始
const ll INF = 1e18;
const double PI = 3.14159265358979323846264338327950;
int dx[] = {1,0,-1,0};
int dy[] = {0,1,0,-1};



int main(){
    int N;
    double K;
    cin>>N>>K;
    vector<double> a(N);
    rep(i,N){
        cin>>a[i];
    }
    int left = -1;
    int right = 1e9+1;
    // int right = ;
    // cout<<"OK"<<endl;
    while(right-left>1){
        int mid = left + (right - left)/2;
        ll sum = 0;
        rep(i,N){
            sum+=(a[i]-1)/mid+1-1;
        }
        // cout<<sum<<endl;
        if(sum<=K) right = mid;
        else left = mid;
        // cout<<left<<" "<<right<<endl;
    }
    cout<<right<<endl;
    return 0;
}
