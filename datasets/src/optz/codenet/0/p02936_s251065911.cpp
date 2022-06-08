//Generated at 2019-08-18 20:31:13 UTC+8
//Created by Alphagocc
#if __cplusplus < 201103L
#define ___TR1(x) <tr1/x>
#else
#define ___TR1(x) <x>
#endif
#ifndef _GLIBCXX_NO_ASSERT
#include <cassert>
#endif
#include <cctype>
#include <cerrno>
#include <cfloat>
#include <climits>
#include <clocale>
#include <cmath>
#include <cstdarg>
#include <cstddef>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include ___TR1(cstdbool)
#include ___TR1(cstdint)
#include ___TR1(ctgmath)
#include ___TR1(cfenv)
#include ___TR1(cinttypes)
#if __cplusplus >= 201103L
#include <ccomplex>
#include <cstdalign>
#else
#include <tr1/complex>
#endif
#include <algorithm>
#include <bitset>
#include <complex>
#include <deque>
#include <exception>
#include <fstream>
#include <functional>
#include <iomanip>
#include <iostream>
#include <iterator>
#include <limits>
#include <list>
#include <locale>
#include <map>
#include <memory>
#include <new>
#include <numeric>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <stdexcept>
#include <streambuf>
#include <string>
#include <typeinfo>
#include <utility>
#include <valarray>
#include <vector>
#include ___TR1(array)
#include ___TR1(random)
#include ___TR1(tuple)
#include ___TR1(unordered_map)
#include ___TR1(unordered_set)
#if __cplusplus >= 201103L
#include <atomic>
#include <chrono>
#include <condition_variable>
#include <forward_list>
#include <future>
#include <initializer_list>
#include <mutex>
#include <ratio>
#include <regex>
#include <scoped_allocator>
#include <system_error>
#include <thread>
#include <type_traits>
#include <typeindex>
#endif
#ifdef USE_PBDS
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/priority_queue.hpp>
#endif
#define FORCE_INLINE __inline__ __attribute__((always_inline)) 
// struct IO
struct IO
{
    bool goodReadBit;
    IO()
    {
        goodReadBit = 1;
        space       = ' ';
    }
    template <typename T>
    FORCE_INLINE void __RI(T &x)
    {
        int ch = getchar(), neg = 1;
        x = 0;
        for (; !(isdigit(ch) || ch == '-' || ch == EOF); ch = getchar())
            ;
        if (ch == EOF)
        {
            goodReadBit = 0;

            return;
        }
        if (ch == '-') neg = -1, ch = getchar();
        for (; isdigit(ch); ch = getchar()) x = x * 10 + ch - 48;
        x *= neg;
    }
    FORCE_INLINE void R(int &x) { __RI(x); }
    FORCE_INLINE void R(int64_t &x) { __RI(x); }
    template <typename T1, typename T2>
    FORCE_INLINE void R(std::pair<T1, T2> &x)
    {
        R(x.first);
        R(x.second);
    }
    template <typename T>
    FORCE_INLINE void R(std::vector<T> &x)
    {
        for (typename std::vector<T>::iterator it = x.begin(); it != x.end(); ++it) { R(*it); }
    }
    template <typename T>
    FORCE_INLINE void R(T &x)
    {
        std::cin >> x;
        if (!std::ios::goodbit) goodReadBit = 0;
    }
    template <typename T, typename... Args>
    FORCE_INLINE void RA(T *a, int n)
    {
        for (int i = 0; i < n; ++i) R(a[i]);
    }
#if __cplusplus >= 201103L
    template <typename T, typename... Args>
    FORCE_INLINE void R(T &x, Args &... args)
    {
        R(x), R(args...);
    }
    template <typename T, typename... Args>
    FORCE_INLINE void RA(T *a, int n, Args... args)
    {
        for (int i = 0; i < n; ++i) RA(a[i], args...);
    }
#endif
    bool goodRead() { return goodReadBit; }
    char space;
    template <typename T>
    FORCE_INLINE void __WI(T x)
    {
        if (x == 0) putchar('0');
        if (x < 0) putchar('-'), x = -x;
        char ch[128];
        int  pos = 0;
        while (x) ch[pos++] = x % 10 + 48, x /= 10;
        while (pos) putchar(ch[--pos]);
    }
    FORCE_INLINE void W() {}
    FORCE_INLINE void W(const int &x) { __WI(x); }
    FORCE_INLINE void W(const int64_t &x) { __WI(x); }
    FORCE_INLINE void W(const unsigned int &x) { __WI(x); }
    FORCE_INLINE void W(const uint64_t &x) { __WI(x); }
    FORCE_INLINE void W(const double &x) { printf("%lf", static_cast<double>(x)); }
    FORCE_INLINE void W(const char &x) { putchar(x); }
    FORCE_INLINE void W(const std::string &x) { printf("%s", x.c_str()); }
    template <typename T1, typename T2>
    FORCE_INLINE void W(const std::pair<T1, T2> &x)
    {
        W(x.first);
        W(space);
        W(x.second);
    }
    template <typename T>
    FORCE_INLINE void W(const std::vector<T> &x)
    {
        for (typename std::vector<T>::const_iterator it = x.begin(); it != x.end(); it++)
        {
            W(*it);
            W(space);
        }
        W('\n');
    }
    template <typename T>
    FORCE_INLINE void W(const T &x)
    {
        std::cout << x;
    }
    FORCE_INLINE void WL() { W('\n'); }
    template <typename T>
    FORCE_INLINE void WL(const T &x)
    {
        W(x), W('\n');
    }
    FORCE_INLINE void WS() { W(space); }
    template <typename T>
    FORCE_INLINE void WS(const T &x)
    {
        W(x), W(space);
    }
    template <typename T>
    FORCE_INLINE void WA(T *a, int n)
    {
        for (int i = 0; i < n; i++) WS(a[i]);
        WL();
    }
#if __cplusplus >= 201103L
    template <typename T, typename... Args>
    FORCE_INLINE void W(const T &x, const Args &... args)
    {
        W(x), W(space), W(args...);
    }
    template <typename... Args>
    FORCE_INLINE void WL(const Args &... args)
    {
        W(args...), W('\n');
    }
    template <typename T, typename... Args>
    FORCE_INLINE void WA(T *a, int n, Args... args)
    {
        for (int i = 0; i < n; i++) WA(a[i], args...);
    }
#endif
    template <typename T>
    FORCE_INLINE IO &operator>>(T &x)
    {
        R(x);
        return (*this);
    }
    template <typename T>
    FORCE_INLINE IO &operator<<(const T &x)
    {
        W(x);
        return (*this);
    }
} io; // struct IO
namespace Alphagocc
{
#if __cplusplus >= 201103L
decltype(std::chrono::high_resolution_clock::now()) tStart;
};
void      TimeBegin() { Alphagocc::tStart = std::chrono::high_resolution_clock::now(); }
long long TimeEnd()
{
    return (std::chrono::high_resolution_clock::now() - Alphagocc::tStart).count();
#endif
} // namespace Alphagocc
#if __cplusplus >= 201103L
std::random_device randomDevice;
std::mt19937       randomGenerator(randomDevice());
#else
std::tr1::random_device randomDevice;
std::tr1::mt19937       randomGenerator(randomDevice());
#endif
using namespace std;
#if __cplusplus < 201103L
using namespace tr1;
#endif
#define REP(i, x, y) for (int i = x; i < y; i++)
const int8_t  INFC = 0x3f;
const int16_t INFS = 0x3f3f;
const int32_t INF  = 0x3f3f3f3f;
const int64_t INFL = 0x3f3f3f3f3f3f3f3fLL;

using DataT = int64_t;
using vi    = vector<DataT>;
template <typename DataT = int, typename ContainerT = vector<DataT>>
struct SegTree
{
    int        n;
    ContainerT node, lazy;
    SegTree(ContainerT v)
    {
        int s = int(v.size());
        n     = 1;
        while (n < s) { n <<= 1; }
        node.resize(2 * n - 1);
        lazy.resize(2 * n - 1, 0);

        for (int i = 0; i < s; i++) { node[i + n - 1] = v[i]; }
        for (int i = n - 2; i >= 0; i--) { node[i] = node[i * 2 + 1] + node[i * 2 + 2]; }
    }

    void eval(int k, int l, int r)
    {
        if (lazy[k])
        {
            node[k] += lazy[k];
            if (r - l > 1)
            {
                lazy[2 * k + 1] += lazy[k] / 2;
                lazy[2 * k + 2] += lazy[k] / 2;
            }

            lazy[k] = 0;
        }
    }

    void add(int a, int b, DataT x, int k = 0, int l = 0, int r = -1)
    {
        if (r < 0) r = n;
        eval(k, l, r);
        if (b <= l || r <= a) { return; }
        if (a <= l && r <= b)
        {
            lazy[k] += (r - l) * x;
            eval(k, l, r);
        }
        else
        {
            add(a, b, x, 2 * k + 1, l, (l + r) / 2);
            add(a, b, x, 2 * k + 2, (l + r) / 2, r);
            node[k] = node[2 * k + 1] + node[2 * k + 2];
        }
    }

    DataT query(int a, int b, int k = 0, int l = 0, int r = -1)
    {
        if (r < 0) r = n;
        eval(k, l, r);
        if (b <= l || r <= a) { return 0; }
        if (a <= l && r <= b) { return node[k]; }
        DataT vl = query(a, b, 2 * k + 1, l, (l + r) / 2);
        DataT vr = query(a, b, 2 * k + 2, (l + r) / 2, r);
        return vl + vr;
    }

    void set(int a, DataT x)
    {
        add(a, a + 1, -get(a));
        add(a, a + 1, x);
    }

    DataT get(int a) { return query(a, a + 1); }
};

const int MAXN = 3e5;

vector<int> G[MAXN];
vector<int> a;

pair<int, int> p[MAXN];

void dfs(int u, int la)
{
    p[u].first = a.size();
    a.push_back(0);
    for (auto v : G[u])
    {
        if (la != v) dfs(v, u);
    }
    p[u].second = a.size();
}

int main()
{
    int n, q;
    io >> n >> q;
    for (int i = 0; i < n - 1; i++)
    {
        int x, y;
        io >> x >> y;
        --x, --y;
        G[x].push_back(y);
        G[y].push_back(x);
    }
    dfs(0,-1);
    SegTree<> segTree(a);
    while (q--)
    {
        int x, y;
        io >> x >> y;
        --x;
        segTree.add(p[x].first, p[x].second, y);
    }
    for (int i = 0; i < n; i++) { io.WS(segTree.get(p[i].first)); }
    return 0;
}