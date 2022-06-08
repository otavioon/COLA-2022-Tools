#pragma GCC optimize("O3")
/*{{{*/
#include <bits/stdc++.h>
#ifdef LOCAL
int c_ = 0;
#define cout (c_?cerr:cout)
#define debug(...) \
{if(!c_++)cerr<<"\033[96;1m"; \
__VA_ARGS__; \
if(!--c_)cerr<<"\033[0m";}
#else
#define debug(...) {}
#endif
#define assrt(...) debug(\
if (not (__VA_ARGS__)) \
    exit((cerr << __LINE__ << ": " << #__VA_ARGS__ << '\n', 0));\
)
#define st first
#define nd second
#define all(...) (__VA_ARGS__).begin(), (__VA_ARGS__).end()
using namespace std; using ll = long long;
template < typename t > using V = vector< t >;
template < typename t, size_t s > using A = array< t, s >;
void print() {cout << '\n';}
template< typename t, typename... v >
void print(const t& a, const v&... b)
{cout << a << (sizeof...(b)?" ":""); print(b...);}
template< typename t > void print_range(t a, const t& b)
{ while (a != b) cout << (*a++) << ' '; cout << '\n';}
#define dump(...) debug(print(#__VA_ARGS__,'=',__VA_ARGS__))
#define dump_range(...) debug(cerr<<#__VA_ARGS__ << ": "; print_range(__VA_ARGS__))
/*}}}*/

constexpr int nax = 2e5;

int n, res;
multiset< int > S;

int32_t main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n;

    for (int i = 0; i < n; ++i)
    {
        int v; cin >> v;
        S.insert(v);
    }

    while (not S.empty())
    {
        int v = *S.rbegin(); S.erase(prev(S.end()));
        int a = 1;
        while (a <= v) a <<= 1;
        if (S.find(a - v) != S.end())
        {
            auto it = S.find(a - v);
            S.erase(it);
            ++res;
        }
    }

    print(res);
}