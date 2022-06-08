#include "bits/stdc++.h"
using namespace std;

// GNU C Compiler
//template<class T> inline string toString(T x) { ostringstream sout; sout << x; return sout.str(); }

// type
using ll = int_fast64_t;
using ull = uint_fast64_t;
using LL = long long;
using ULL = unsigned long long;
using PII = pair<int, int>;
//using pair<T1, T2> = p12;

//container
#define PB emplace_back
#define MP make_pair 
#define SZ(a) int((a).size())
#define ALL(v) v.begin(),v.end()

//repetition
#define REP(n) for(ll i=0; i<(n); i++)
#define REPj(n) for(ll j=0; j<(n); j++)
#define REPinit(i,a,n) for(ll i=(a); i<(n); i++)
#define REPinitj(j,a,n) for(ll j=(a); j<(n); j++)

//algorithm
#define SORT(c) sort((c).begin(),(c).end())
#define CONTAINER_ALL(a) a.begin(),a.end()

//constant

//clear memory
#define CLR(a) memset((a), 0 ,sizeof(a))

//Optimizer
// #pragma GCC optimize("Ofast")
// #pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")

namespace modular {
    constexpr ll MOD = 1000000007;
    const int MAXN = 1100000;
    template <ll Modulus> class modint {
        using u64 = ll;

    public:
        u64 a;

        constexpr modint(const u64 x = 0) noexcept : a(((x% Modulus) + Modulus) % Modulus) {}
        constexpr u64& value() noexcept { return a; }
        constexpr const u64& value() const noexcept { return a; }
        constexpr modint operator+(const modint rhs) const noexcept { return modint(*this) += rhs; }
        constexpr modint operator-(const modint rhs) const noexcept { return modint(*this) -= rhs; }
        constexpr modint operator*(const modint rhs) const noexcept { return modint(*this) *= rhs; }
        template <typename T> constexpr modint operator^(T rhs) const noexcept { return modint(*this) ^= rhs; }
        constexpr modint& operator+=(const modint rhs) noexcept {
            a += rhs.a;
            if (a >= Modulus) { a -= Modulus; }
            return *this;
        }
        constexpr modint& operator-=(const modint rhs) noexcept {
            if (a < rhs.a) { a += Modulus; }
            a -= rhs.a;
            return *this;
        }
        constexpr modint& operator*=(const modint rhs) noexcept {
            a = a * rhs.a % Modulus;
            return *this;
        }
        constexpr bool operator==(const modint rhs) const noexcept { return a == rhs.a; }
        template <typename T> constexpr modint& operator^=(T n) noexcept {
            modint<Modulus> res = 1;
            modint<Modulus> x = a;
            while (n) {
                if (n & 1) res *= x;
                x *= x;
                n >>= 1;
            }
            a = res.a;
            return *this;
        }
    };
#define mint modint<MOD>
#define vmint vector<mint>

    vmint Inv{ 0, 1 }, Prd{ 1, 1 }, Invprd{ 1, 1 };
    mint inv(int n) {
        if (Inv.size() > n)
            return Inv[n];
        else {
            for (int i = Inv.size(); i <= n; ++i) Inv.emplace_back(Inv[MOD % i] * (-MOD / i));
            return Inv[n];
        }
    }
    mint prd(int n) {
        if (Prd.size() > n)
            return Prd[n];
        else
            for (int i = Prd.size(); i <= n; ++i) Prd.emplace_back(Prd[i - 1] * i);
        return Prd[n];
    }
    mint invprd(int n) {
        if (Invprd.size() > n)
            return Invprd[n];
        else
            for (int i = Invprd.size(); i <= n; ++i) Invprd.emplace_back(Invprd[i - 1] * inv(i));
        return Invprd[n];
    }
    mint modpow(ll a, ll n) {
        mint x = a;
        return x ^= n;
    }
    template <ll T> modint<T> operator/(modint<T> l, modint<T> r) {
        if (r.a < MAXN) return l * inv(r.a);
        return l * (r ^ (MOD - 2));
    }
    template <typename T, ll S> modint<S> operator/(T l, modint<S> r) { return modint<S>(l) / r; }
    template <ll T> modint<T> operator/=(modint<T>& l, modint<T> r) { return l = l / r; }
    mint C(int a, int b) {
        if (a < 0 || b < 0) return 0;
        if (a < b) return 0;
        return prd(a) * invprd(b) * invprd(a - b);
    }
    mint P(int a, int b) {
        if (a < 0 || b < 0) return 0;
        if (a < b) return 0;
        return prd(a) * invprd(a - b);
    }
    ostream& operator<<(ostream& os, mint a) {
        os << a.a;
        return os;
    }
    template <typename T> ostream& operator<<(ostream& os, vector<T>& a) {
        for (auto& e : a) os << e << " ";
        os << endl;
        return os;
    }
    istream& operator>>(istream& is, mint& a) {
        ll x;
        is >> x;
        a = x;
        return is;
    }
} // namespace modular


int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    using namespace modular;

    ll N;
    cin >> N;

    if (N % 2 == 0) cout << N << endl;
    else cout << (N * 2) << endl;
    


    return 0;
}
