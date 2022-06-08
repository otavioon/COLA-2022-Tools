#include <algorithm>
#include <array>
#include <bitset>
#include <cmath>
#include <functional>
#include <iostream>
#include <limits>
#include <list>
#include <map>
#include <numeric>
#include <set>
#include <string>
#include <vector>
#include <queue>
#include <unordered_map>
#include <unordered_set>
#include <iomanip>
#include <chrono>
#include <random>

#include <cstring>

using namespace std;

using ll = long long;
ll const MM = 1000000007;

#define pv(val) cerr << #val << '=' << (val) << endl
#define pl cerr << '@' << __LINE__ << endl

#define rep(i, n) for (ll i = 0; i < (n); i++)
#define rep2(i, b, e) for (ll i = (b); i < (e); i++)
#define all(a) a.begin(), a.end()
#define rall(a) a.rbegin(), a.rend()

template <class T>
ostream& operator<<(ostream& os, vector<T> const& vec);
template <class T, size_t S>
ostream& operator<<(ostream& os, array<T, S> const& arr);
template<class T, class U>
ostream& operator<<(ostream& os, pair<T, U> const& p);
template<class... Args>
ostream& operator<<(ostream& os, tuple<Args...> const& t);

template <class T>
ostream& operator<<(ostream& os, vector<T> const& vec) {
    if (vec.empty()) {
        os << "{}";
    } else {
        os << '{';
        for (size_t i = 0; i < vec.size() - 1; i++) os << vec[i] << ", ";
        os << vec.back() << '}';
    }
    return os;
}

template <class T, size_t S>
ostream& operator<<(ostream& os, array<T, S> const& arr) {
    if (arr.empty()) {
        os << "{}";
    } else {
        os << '{';
        for (size_t i = 0; i < arr.size() - 1; i++) os << arr[i] << ", ";
        os << arr.back() << '}';
    }
    return os;
}

template<class T, class U>
ostream& operator<<(ostream& os, pair<T, U> const& p) {
    os << '(' << p.first << ", " << p.second << ')';
    return os;
}

template<size_t I, class... Args>
typename enable_if<sizeof...(Args) == (I + 1)>::type print_tuple(ostream& os, tuple<Args...> const& t) {
    os << get<I>(t);
}
template<size_t I, class... Args>
typename enable_if<sizeof...(Args) != (I + 1)>::type print_tuple(ostream& os, tuple<Args...> const& t) {
    os << get<I>(t) << ", ";
    print_tuple<I + 1, Args...>(os, t);
}

template<class... Args>
ostream& operator<<(ostream& os, tuple<Args...> const& t) {
    os << '(';
    print_tuple<0, Args...>(os, t);
    os << ')';

    return os;
}

struct Timer {
    using Clock = std::chrono::system_clock;
    Clock::time_point startTime;
 
    Timer()
    {
        start();
    }
    void start()
    {
        startTime = Clock::now();
    }
 
    long long milli() const
    {
        return std::chrono::duration_cast<std::chrono::milliseconds>(Clock::now() - startTime).count();
    }
    long long micro() const
    {
        return std::chrono::duration_cast<std::chrono::microseconds>(Clock::now() - startTime).count();
    }
};

namespace math {
    ll gcd(ll u, ll v) {
        while (v != 0) {
            ll r = u % v;
            u = v;
            v = r;
        }
        return u;
    }
    ll lcm(ll m, ll n) {
        if ((0 == m) || (0 == n)) return 0;

        return ((m / math::gcd(m, n)) * n);
    }

    vector<ll> divisors(ll n) {
        vector<ll> ret;
        for (ll i = 1; i * i <= n; i++) {
            if (n % i == 0) {
                ret.push_back(i);
                if (i * i != n) ret.push_back(n / i);
            }
        }
        sort(begin(ret), end(ret));
        return ret;
    }
    set<ll> divisors_set(ll n) {
        set<ll> ret;
        for (ll i = 1; i * i <= n; i++) {
            if (n % i == 0) {
                ret.insert(i);
                if (i * i != n) ret.insert(n / i);
            }
        }
        return ret;
    }

    // https://qiita.com/ofutonfuton/items/92b1a6f4a7775f00b6ae
    struct Combination {
        vector<ll> fac;
        vector<ll> ifac;

        Combination() :
            fac(1000000 + 100),
            ifac(1000000 + 100)
        {
            fac[0] = 1;
            ifac[0] = 1;
            for (ll i = 0; i < 1000000 + 100; i++) {
                fac[i + 1] = fac[i] * (i + 1) % MM;
                ifac[i + 1] = ifac[i] * this->mpow(i + 1, MM - 2) % MM;
            }
        }

        static ll mpow(ll x, ll n) {
            ll ans = 1;
            while (n != 0) {
                if (n & 1) ans = ans * x % MM;
                x = x * x % MM;
                n = n >> 1;
            }
            return ans;
        }

        ll operator()(ll a, ll b) const {
            return this->comb(a, b);
        }

        ll comb(ll a, ll b) const {
            if (a == 0 && b == 0)return 1;
            if (a < b || a < 0 || b < 0)return 0;
            ll const tmp = ifac[a - b] * ifac[b] % MM;
            return tmp * fac[a] % MM;
        }

    };// comb;

    ll digit(ll n, ll b = 10) {
        if (n == 0)
            return 1;

        ll d = 0;
        while (n > 0) {
            d++;
            n /= b;
        }

        return d;
    }
}  // namespace math

struct UnionFind {
    vector<ll> data;
    UnionFind(ll size) : data(size, -1) {}
    bool unionSet(ll x, ll y) {
        x = root(x);
        y = root(y);
        if (x != y) {
            if (data[y] < data[x]) swap(x, y);
            data[x] += data[y];
            data[y] = x;
        }
        return x != y;
    }
    bool findSet(ll x, ll y) { return root(x) == root(y); }
    ll root(ll x) { return data[x] < 0 ? x : data[x] = root(data[x]); }
    ll size(ll x) { return -data[root(x)]; }
};

ll bound(function<bool(ll)> f, ll ng, ll ok) {
    while (abs(ng - ok) > 1) {
        ll mid = (ng + ok) / 2;
        if (f(mid))
            ok = mid;
        else
            ng = mid;
    }

    return ok;
}

ll order(vector<ll> const& r) {
    vector<ll> a(r.size());
    iota(all(a), 1);

    ll ord = 0;
    while (a != r) {
        next_permutation(all(a));
        ord++;
    }

    return ord;
}

ll ab(ll a, ll b) {
    ll const c = math::gcd(a, b);

    ll const a0 = a / c;
    ll const b0 = b / c;
    if (a0 % 2 == 0 || b0 % 2 == 0)
        return 10000000000;


    return a * b0;
}

int main(void) {
    ll n, m;
    cin >> n >> m;
    vector<ll> a(n);
    rep(i, n) cin >> a[i];

    ll acc = a[0];
    rep2(i, 1, a.size()){
        acc = ab(acc, a[i]);
        acc = min(acc, 10000000000ll);
    }
    acc /= 2;
    pv(acc);

    ll ans = m / acc;
    if (ans % 2 == 1)
        ans++;
    ans /= 2;

    cout << ans << endl;

    return 0;
}

























