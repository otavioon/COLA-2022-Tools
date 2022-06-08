#include <bits/stdc++.h>

#define TYPE(c)   remove_reference_t<decltype(c)>
#define REP(i, n) for(TYPE(n) i = 0; i < n; i++)
#define FOR(v, c) for(TYPE(c.begin()) v = c.begin(); v != c.end(); v++)
#define ALL(c)    c.begin(), c.end()
#define SORT(c)   sort(ALL(c))
#define RSORT(c)  sort(ALL(c), greater<TYPE(c)::value_type>())
#define UNIQUE(c) c.erase(unique(ALL(c)), c.end())

using namespace std;
using ll = long long;

constexpr int MOD  = (int)1e9 + 7;
constexpr int INF  = (int)1e9 + 1;
constexpr ll  LINF = (ll)1e18 + 1;
template<typename T> constexpr bool chmax(T& a, const T& b)
{ if(a < b) { a = b; return true; } else { return false; } }
template<typename T> constexpr bool chmin(T& a, const T& b)
{ if(b < a) { a = b; return true; } else { return false; } }
template<typename S, typename T> ostream& operator<<(ostream &os, const pair<S, T>& p)
{ return os << "(" << p.first << "," << p.second << ")"; }
ostream& operator<<(ostream &os, const string& s)
{ FOR(v, s) os << *v; return os; }
template<typename T> auto operator<<(ostream& os, const T& t)
    -> typename conditional<true, ostream&, decltype(*t.begin())>::type
{ os << "["; FOR(v, t) { if(v != t.begin()) os << ","; os << *v; } os << "]"; return os; }

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);

    int N;
    std::cin >> N;
    int K;
    std::cin >> K;
    std::set<int> D;
    REP(i, K) {
        int d;
        std::cin >> d;
        D.insert(d);
    }

    for(int i = N; i <= 10 * N; i++) {
        bool ok  = true;
        auto num = i;
        while(num) {
            if(D.find(num % 10) != D.end()) {
                ok = false;
                break;
            }
            num /= 10;
        }
        if(ok) {
            std::cout << i << std::endl;
            break;
        }
    }

    return 0;
}
