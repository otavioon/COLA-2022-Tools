#include <bits/stdc++.h>
#define SORT(a) sort(a.begin(), a.end())
#define RSORT(a) sort(a.rbegin(), a.rend())
#define REP(i, n) for (int i = 0; i < n; i++)
#define RREP(i, n) for (int i = n - 1; 0 <= i; i--)
#define FOR(i, start, end) for (int i = start; i < end; i++)
#define RFOR(i, start, end) for (int i = start - 1; 0 <= i; i--)
#define ALL(a) a.begin(), a.end()
using ll = long long;
using namespace std;
constexpr int INF32       = 1'050'000'000;
constexpr long long INF64 = 4'000'000'000'000'000'000;
constexpr int MOD7        = 1'000'000'007;
constexpr int MOD9        = 1'000'000'009;
template <class T> inline bool chmin(T &a, T b) {
    if (a > b) {
        a = b;
        return true;
    }
    return false;
}
template <class T> inline bool chmax(T &a, T b) {
    if (a < b) {
        a = b;
        return true;
    }
    return false;
}
void print() { std::cout << '\n'; }
template <class H, class... T> void print(H &&head, T &&... args) {
    std::cout << head;
    sizeof...(args) == 0 ? std::cout << "" : std::cout << ' ';
    print(std::forward<T>(args)...);
}
template <class T> void print(std::vector<T> &v) {
    for (int i = 0; i < v.size(); i++) {
        std::cout << v[i];
        i == v.size() - 1 ? std::cout << '\n' : std::cout << ' ';
    }
}
template <class T> void print(std::vector<std::vector<T>> &v) {
    for (int i = 0; i < v.size(); i++) {
        for (int j = 0; j < v[i].size(); j++) {
            std::cout << v[i][j];
            j == v[i].size() - 1 ? std::cout << '\n' : std::cout << ' ';
        }
    }
}
void scan() {}
template <class H, class... T> void scan(H &&head, T &&... args) {
    std::cin >> head;
    scan(std::forward<T>(args)...);
}
template <class T> void scan(std::vector<T> &v) {
    for (auto &&i : v) {
        scan(i);
    }
}

// 文字列を圧縮する。first に文字、second に個数
vector<int> run_length(string &s) {
    vector<int> ans(1, 1);
    for (int i = 1; i < s.size(); i++) {
        if (s[i - 1] == s[i])
            ans[ans.size() - 1]++;
        else
            ans.emplace_back(1);
    }
    return ans;
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);

    string s;
    ll K;
    scan(s, K);
    ll cnt   = 0;
    auto run = run_length(s);

    for (auto &&i : run) {
        if (1 < i)
            cnt += i / 2;
    }
    ll ans    = cnt * K;
    string ss = s;
    if (s.size() <= 4) {
        REP(i, min(20, (int)K)) ss += s;
    }
    int cc = 0;
    if (ss[0] == ss[ss.size() - 1]) {
        cc += 2;
        if (ss[0] == ss[1])
            cc++;
        if (ss[ss.size() - 1] == ss[ss.size() - 2])
            cc++;

        if (cc == 2) {
            ans += (K - 1);
        }
        if (cc == 4 && s.size() == 3) {
            ans += K / 2;
        }
        if (cc == 4 && run.size() == 1)
            ans = (ll)s.size() * K / 2;
    }

    if (s.size() == 1) {
        ans = K / 2;
    }

    print(ans);

    return 0;
}