#include <bits/stdc++.h>
//#include <ext/pb_ds/tree_policy.hpp>
//#include <ext/pb_ds/assoc_container.hpp>

using namespace std;
//using namespace __gnu_pbds;

#define ll  long long
#define PR  pair<int, int>

const int N = 3e5 + 10;
const int MOD = 1e9 + 7;
const long long INF = 5e18;
const double PI = 2 * acos(0.0);
//template<typename T> using ordered_set = tree<T, nulong long_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    vector<int> p2(31, 1);
    for (int i = 1; i < 31; i++) {
        p2[i] = p2[i - 1] * 2;
    }
    int n;
    cin >> n;
    multiset<int> ms;
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        ms.insert(x);
    }
    int ans = 0;
    while (!ms.empty()) {
        int a = *ms.rbegin();
        ms.erase(ms.lower_bound(a));
        for (int i = 30; i >= 0; i--) {
            int need = p2[i] - a;
            if (ms.find(need) != ms.end()) {
                ms.erase(ms.lower_bound(need));
                ans++;
                break;
            }
        }
    }
    cout << ans << '\n';
    return 0;
}
