// #define MODULAR_ARITHMETIC
// #define INDEXED_SET
#ifndef LOCAL_DEBUG
#pragma GCC optimize("O3")
#pragma comment(linker, "/stack:200000000")
#pragma GCC optimize("unroll-loops")
#endif

#include <stdarg.h>
#include <stdio.h>
#include <iostream>
#include <vector>
#include <algorithm>
#include <math.h>
#include <map>
#include <bitset>
#include <chrono>
#include <iomanip>
#include <numeric>
#include <assert.h>
#include <set>
#define pb push_back
#define mp make_pair
#define f(i, a, b) for (int i = a; i < b; i++)
#define revf(i, b, a) for (int i = b; i >= a; i--)
#define srt(v) sort(v.begin(), v.end())
#define rev_srt(v) sort(v.rbegin(), v.rend())
using namespace std;

#ifdef MODULAR_ARITHMETIC
template <typename T>
T add(T a, T b, T c)
{
    T res = a + b;
    return (res >= c ? res - c : res);
}
template <typename T>
T mod_neg(T a, T b, T c)
{
    T res;
    if (abs(a - b) < c)
        res = a - b;
    else
        res = (a - b) % c;
    return (res < 0 ? res + c : res);
}
template <typename T>
T mul(T a, T b, T c)
{
    ll res = (ll)a * b;
    return (res >= c ? res % c : res);
}
ll mulmod(ll a, ll b, ll m)
{
    ll q = (ll)(((LD)a * (LD)b) / (LD)m);
    ll r = a * b - q * m;
    if (r > m)
        r %= m;
    if (r < 0)
        r += m;
    return r;
}
template <typename T>
T expo(T e, T n)
{
    T x = 1, p = e;
    while (n)
    {
        if (n & 1)
            x = x * p;
        p = p * p;
        n >>= 1;
    }
    return x;
}
template <typename T>
T power(T e, T n, T m)
{
    T x = 1, p = e;
    while (n)
    {
        if (n & 1)
            x = mul(x, p, m);
        p = mul(p, p, m);
        n >>= 1;
    }
    return x;
}
template <typename T>
T extended_euclid(T a, T b, T &x, T &y)
{
    T xx = 0, yy = 1;
    y = 0;
    x = 1;
    while (b)
    {
        T q = a / b, t = b;
        b = a % b;
        a = t;
        t = xx;
        xx = x - q * xx;
        x = t;
        t = yy;
        yy = y - q * yy;
        y = t;
    }
    return a;
}
template <typename T>
T mod_inverse(T a, T n)
{
    T x, y, z = 0;
    T d = extended_euclid(a, n, x, y);
    return (d > 1 ? -1 : mod_neg(x, z, n));
}
#endif

#ifdef INDEXED_SET
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/rope>
using namespace __gnu_pbds;
using namespace __gnu_cxx;
typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> indexed_set;
#endif

#define sp << ' ' <<
#define endl '\n'
#define precision(x) cout << fixed << setprecision(x);
#define fio                  \
    ios::sync_with_stdio(0); \
    cin.tie(0);              \
    cout.tie(0);

template <typename T>
ostream &operator<<(ostream &os, vector<pair<T, T>> &v)
{
    int n = v.size();
    for (int i = 0; i < n; i++)
        os << v[i].first sp v[i].second << "\n";
    return os;
}

template <typename T>
ostream &operator<<(ostream &os, vector<T> &v)
{
    int n = v.size();
    for (int i = 0; i < n; i++)
        os << v[i] << " ";
    os << endl;
    return os;
}

template <typename T>
istream &operator>>(istream &is, vector<T> &v)
{
    int n = v.size();
    for (int i = 0; i < n; i++)
        is >> v[i];
    return is;
}

typedef long long ll;
typedef pair<int, int> pii;
typedef long double ld;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<ll> vll;
typedef vector<vll> vvll;
typedef vector<pii> vpii;
typedef vector<vpii> vvpii;

ll mod = 1e9 + 7;
const int MAX = 5 * 1e5 + 5;

void solvetestcase()
{
    string str;
    ll k;
    vll v;
    cin >> str;
    cin >> k;
    int count = 1;
    ll n = str.size();
    f(i, 1, n)
    {
        if (str[i] == str[i - 1])
        {
            count++;
        }
        else
        {
            v.pb(count);
            count = 1;
        }
    }
    v.pb(count);
    if (v.size() == 1)
    {
        cout << (k * n) / 2 << endl;
        return;
    }
    // cout << v;
    if (str[0] == str[n - 1])
    {
        ll sum = 0;
        f(i, 1, v.size() - 1)
        {
            sum += v[i] / 2;
        }
        ll ans;
        ans = sum * k + ((v[0] + v[v.size() - 1]) / 2) * (k - 1) + v[0] / 2 + v[v.size() - 1] / 2;

        cout << ans << endl;
        return;
    }
    ll sum = 0;
    f(i, 0, v.size()) sum += v[i] / 2;
    cout << sum * k << endl;
}

int main()
{
    fio;
    int t = 1;

    // UNCOMMENT FOR TESTCASES	\
	cin >> t;

    f(T, 1, t + 1)
    {
        // UNCOMMENT FOR CODEJAM,HACKERCUP	\
		cout << "Case #" << T << ": ";
        solvetestcase();
    }
};

/*
    AUTHOR:     KUNAL TAWATIA
    EDUCATION:  INDIAN INSTITUTE OF TECHNOLOGY, JODHPUR
*/