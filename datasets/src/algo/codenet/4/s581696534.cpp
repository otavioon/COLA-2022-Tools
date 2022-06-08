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

    string N;
    std::cin >> N;
    reverse(ALL(N));
    int K;
    std::cin >> K;
    std::set<int> D;
    REP(i, K) {
        int d;
        std::cin >> d;
        D.insert(d);
    }

    int  ans   = 0;
    bool carry = false;
    REP(i, N.size()) {
        auto n = N[i] - '0';
        if(carry) {
            n++;
            carry = false;
            if(n == 10) {
                n = 0;
                carry = true;
            }
        }
        while(D.find(n) != D.end()) {
            n++;
            if(n == 10) {
                n = 0;
                carry = true;
            }
        }
        ans += n * pow(10, i);
    }

    if(carry) {
        for(size_t i = 1; i < 10; i++) {
            if(D.find(i) == D.end()) {
                ans += i * pow(10, N.size());
                break;
            }
        }
    }

    std::cout << ans << std::endl;

    return 0;
}
