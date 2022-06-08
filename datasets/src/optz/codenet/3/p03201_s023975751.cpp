#include <bits/stdc++.h>
#define REP(i, n) for (int i = 0; (i) < (int)(n); ++ (i))
#define REP3(i, m, n) for (int i = (m); (i) < (int)(n); ++ (i))
#define REP_R(i, n) for (int i = int(n) - 1; (i) >= 0; -- (i))
#define REP3R(i, m, n) for (int i = int(n) - 1; (i) >= (int)(m); -- (i))
#define ALL(x) begin(x), end(x)
#define dump(x) cerr << #x " = " << x << endl
#define unittest_name_helper(counter) unittest_ ## counter
#define unittest_name(counter) unittest_name_helper(counter)
#define unittest __attribute__((constructor)) void unittest_name(__COUNTER__) ()
using ll = long long;
using namespace std;
template <class T> using reversed_priority_queue = priority_queue<T, vector<T>, greater<T> >;
template <class T, class U> inline void chmax(T & a, U const & b) { a = max<T>(a, b); }
template <class T, class U> inline void chmin(T & a, U const & b) { a = min<T>(a, b); }
template <typename X, typename T> auto vectors(X x, T a) { return vector<T>(x, a); }
template <typename X, typename Y, typename Z, typename... Zs> auto vectors(X x, Y y, Z z, Zs... zs) { auto cont = vectors(y, z, zs...); return vector<decltype(cont)>(x, cont); }
template <typename T> ostream & operator << (ostream & out, vector<T> const & xs) { REP (i, int(xs.size()) - 1) out << xs[i] << ' '; if (not xs.empty()) out << xs.back(); return out; }

int solve(int n, vector<int> const & a) {
    unordered_map<int, int> f;
    for (int a_i : a) {
        f[a_i] += 1;
    }

    unordered_map<int, vector<int> > g;
    unordered_map<int, int> degree;
    queue<int> que;
    for (int a_i : a) if (not g.count(a_i)) {
        REP (k, 31) {
            int a_j = (1 << k) - a_i;
            if (f.count(a_j)) {
                g[a_i].push_back(a_j);
            }
        }
        degree[a_i] = g[a_i].size();
        if (degree[a_i] == 1) {
            que.push(a_i);
        }
    }

    int ans = 0;
    while (not que.empty()) {
        int a_i = que.front();
        que.pop();
        for (int a_j : g[a_i]) {
            int delta = min(f[a_i], f[a_j]);
            if (a_i == a_j) {
                delta /= 2;
            } else {
                f[a_i] -= delta;
            }
            f[a_j] -= delta;
            ans += delta;
        }
        for (int a_j : g[a_i]) {
            degree[a_j] -= 1;
            if (degree[a_j] == 1) {
                que.push(a_j);
            }
        }
    }
    return ans;
}

int main() {
    int n; cin >> n;
    vector<int> a(n);
    REP (i, n) cin >> a[i];
    cout << solve(n, a) << endl;
    return 0;
}
