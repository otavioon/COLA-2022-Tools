#include <iostream>
#include <string>
#include <vector>
#include <list>
#include <set>
#include <algorithm>
#include <unordered_map>

#define rep(i, a, b) for (ll i = a; i < b; i++)

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef pair<ll, ll> pll;
typedef unordered_map<string, ll> u_map;

// input
void input() {}
template <class Head, class... Tail>
void input(Head &&a, Tail &&... b)
{
    cin >> a;
    input(forward<Tail>(b)...);
}

template <class V>
void input(vector<V> &v)
{
    for_each(v.begin(), v.end(), [](auto &i) { input(i); });
}

// output
template <class V>
void output(vector<V> &v)
{
    for_each(v.begin(), v.end(), [](auto &x) { cout << x << " "; });
    cout << endl;
}

// math functions
ll mpow(ll a, ll n, ll p)
{
    ll x = 1;
    while (n > 0)
    {
        if (n & 1)
        {
            x = a * x % p;
        }
        a = a * a % p;
        n >>= 1;
    }

    return x;
}

ll mfact(ll n, ll p)
{
    ll res = 1;
    for (ll i = 2; i <= n; i++)
    {
        res = res * i % p;
    }
    return res;
}

ll mcomb(ll n, ll r, ll p)
{
    if (n == 0 && r == 0)
    {
        return 1;
    }
    if (n < r || n < 0 || r < 0)
    {
        return 0;
    }

    ll a = mfact(n, p);
    ll b = mfact(n - r, p);
    ll c = mfact(r, p);
    return (((a * mpow(b, p - 2, p)) % p) * mpow(c, p - 2, p)) % p;
}

ll gcd(ll a, ll b)
{
    if (a < b)
    {
        a ^= b;
        b ^= a;
        a ^= b;
    }
    return b ? gcd(b, a % b) : a;
}

ll lcm(ll a, ll b)
{
    return a * b / gcd(a, b);
}

int main()
{
    u_map m;
    ll N;
    input(N);

    rep(i, 0, N)
    {
        string s;
        input(s);
        m[s] += 1;
    }

    ll M;
    input(M);
    rep(i, 0, M)
    {
        string s;
        input(s);
        m[s] -= 1;
    }

    ll res = -1000000;
    for_each(m.begin(), m.end(), [&](auto &p) {
        res = max(res, p.second);
    });

    cout << (res < 0 ? 0 : res) << endl;

    return 0;
}