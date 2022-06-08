#include <bits/stdc++.h>
using namespace std;
using LL = long long;
#define FOR(i, x, y) for (decay<decltype(y)>::type i = (x), _##i = (y); i < _##i; ++i)
#define FORD(i, x, y) for (decay<decltype(x)>::type i = (x), _##i = (y); i > _##i; --i)
#ifdef zerol
#define dbg(args...) do { cout << "DEBUG: " << #args << " -> "; err(args); } while (0)
#else
#define dbg(...)
#endif
void err() { cout<< endl; }
template<template<typename...> class T, typename t, typename... Args>
void err(T<t> a, Args... args) { for (auto x: a) cout << x << ' '; err(args...); }
template<typename T, typename... Args>
void err(T a, Args... args) { cout << a << ' '; err(args...); }
// -----------------------------------------------------------------------------

const int N = 2E5 + 100;
multiset<LL> S;

int main() {
    int n; cin >> n;
    FOR (i, 0, n) {
        int x; cin >> x;
        S.insert(x);
    }
    int ans = 0;
    while (!S.empty()) {
        LL t = *S.begin();
        S.erase(S.begin());
        FOR (i, 0, 33) {
            LL s = 1LL << i;
            auto it = S.find(s - t);
            if (it != S.end()) {
                S.erase(it);
                ans++;
            }
        }
    }
    cout << ans << endl;
    return 0;
}