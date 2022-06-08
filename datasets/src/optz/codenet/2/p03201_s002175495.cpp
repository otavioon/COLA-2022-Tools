#include <iostream>
#include <algorithm>
#include <vector>
#include <iomanip>
#include <map>
#include <queue>

static const int MOD = 1000000007;
using ll = long long;
using u32 = unsigned;
using namespace std;

template<class T>
constexpr T INF = ::numeric_limits<T>::max() / 32 * 15 + 208;



int main() {
    int n, ans = 0;
    cin >> n;
    vector<int> v(n), u, used(n, 0);
    for (auto &&i : v) scanf("%d", &i);
    for (int i = 0; i < 31; ++i) {
        u.emplace_back(1 << i);
    }
    sort(v.begin(), v.end(), greater<>());
    for (int i = 31; i >= 0; --i) {
        map<int, queue<int>> m;
        for (int j = 0; j < n; ++j) {
            if(used[j]) continue;
            if(m.count(u[i]-v[j]) && !m[u[i]-v[j]].empty()){
                int k = m[u[i]-v[j]].front(); m[u[i]-v[j]].pop();
                used[j] = used[k] = 1;
                ans++;
            }
            m[v[j]].emplace(j);
        }
    }
    cout << ans << "\n";
    return 0;
}
