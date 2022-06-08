// https://atcoder.jp/contests/agc029/tasks/agc029_b

#include <algorithm>
#include <array>
#include <cmath>
#include <iostream>
#include <map>
#include <numeric>
#include <set>
#include <tuple>
#include <vector>
using namespace std;

typedef long long ll;
const int INF = 100100100;
const int MOD = (int)1e9 + 7;
const double EPS = 1e-9;
#define ALL(obj) (obj).begin(), (obj).end()
#define ALLR(obj) (obj).rbegin(), (obj).rend()

// long gcd(long a, long b) { return b ? gcd(b, a % b) : a; }
// long lcm(long a, long b) { return a * b / gcd(a, b); }

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n, ans = 0;
    cin >> n;
    // 値に対して個数を持つ。ペアとして使用する際に個数を数える。
    multiset<int> m;

    for (int i = 0; i < n; i++) {
        int a;
        cin >> a;
        m.insert(a);
    }

    // 大きい値から順に処理する
    while (!m.empty()) {
        auto it = --m.end();
        int x = *(it);
        m.erase(it);
        // xより大きい２のべき乗を作成
        // while (p <= x)
        //     p *= 2;
        uint32_t p = (1u << (32 - __builtin_clz(x)));

        int y = p - x; // ペアとなるyは1通り
        auto itr = m.find(y);
        if (itr != m.end()) {
            m.erase(itr);
            ans++;
        }
    }
    cout << ans << endl;

    return 0;
}