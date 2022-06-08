#include <bits/stdc++.h>
using namespace std;
using LL = long long;
using PII = pair<int, int>;
#define FI(i,a,b) for(int i=(a);i<=(b);++i)
#define FD(i,b,a) for(int i=(b);i>=(a);--i)
#define DEBUG(x) cerr << #x << ": " << (x) << endl;
constexpr LL inv(LL x, LL m) { return x > m ? inv(x % m, m) : x > 1 ? inv(m % x, m) * (m - m / x) % m : x; }
constexpr LL mpow(LL a, LL k, LL m) { LL r(1); for (a %= m; k; k >>= 1, a = a * a % m) if (k & 1)r = r * a % m; return r; }

int main() {
    int n;
    scanf("%d", &n);
    multiset<int> S;
    for (int x, i = 1; i <= n; i++) scanf("%d", &x), S.insert(x);
    int ans = 0;
    while (!S.empty()) {
        int x = *S.rbegin(), y = 1;
        S.erase(S.find(x));
        while (y <= x) y *= 2;
        if (S.find(y - x) != S.end()) S.erase(S.find(y - x)), ans++;
    }
    printf("%d\n", ans);
}
