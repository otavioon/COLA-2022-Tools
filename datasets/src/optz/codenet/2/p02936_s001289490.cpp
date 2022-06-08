// https://atcoder.jp/contests/abcXXX/tasks/abcXXX_x

#include <iostream>
#include <vector>
#include <tuple>

using namespace std;
using ll = long long;
using ull = unsigned long long;
using pll = pair<ll, ll>;

struct C1 {
    ll N_{};
    ll Q_{};
    vector<vector<ll>> m_{};
    vector<ll> parents_{};
    vector<ll> added_values_{};
    vector<ll> added_value_total_{};
    explicit C1(ll N, vector<pll> r, vector<pll> v) : N_(N), Q_(v.size()) {
        parents_.resize(N);
        added_values_.resize(N, 0);
        added_value_total_.resize(N, -1);
        for(ll i=0; i < Q_; ++i) {
            auto p = v[i];
            added_values_[p.first-1] += p.second;
        }
        m_.resize(N_);
        for(ll i=0; i < N_-1; ++i) {
            auto p = r[i];
            m_[p.first-1].emplace_back(p.second-1);
            m_[p.second-1].emplace_back(p.first-1);
        }
        dfs(0, -1);
    }
    void dfs(ll cur, ll prev = -1) {
        parents_[cur] = prev;
        for(ll n : m_[cur]) {
            if (n != prev) {
                dfs(n, cur);
            }
        }
    }

    vector<ll> resolve() {
        vector<ll> ret{};
        for(ll i=0; i < N_; ++i) {
            ll value = 0;
            ll n = i;
            while(n != -1) {
                value += added_values_[n];
                n = parents_[n];
                if (n != -1 && added_value_total_[n] != -1) {
                    value += added_value_total_[n];
                    n = -1;
                }
            }
            ret.emplace_back(value);
            added_value_total_[i] = value;
        }
        return ret;
    }
};

int main() {
    ll N, Q;
    cin >> N >> Q;
    vector<pll> r{};
    for (int i=0; i < N-1; ++i) {
        ll a, b;
        cin >> a >> b;
        r.emplace_back(a,b);
    }
    vector<pll> v{};
    for (int i=0; i < Q; ++i) {
        ll p, x;
        cin >> p >> x;
        v.emplace_back(p, x);
    }
    C1 c{N, move(r), move(v)};
    auto ans = c.resolve();
    for(ll x : ans) {
        cout << x << " ";
    }
    cout << endl;
    return 0;
}
