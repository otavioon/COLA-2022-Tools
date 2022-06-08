// #pragma GCC target("avx2")
#pragma GCC optimize("O3", "unroll-loops")

// #include <bits/extc++.h>
// using namespace __gnu_pbds;

#include <bits/stdc++.h>
using namespace std;

#define int long long
#define double long double
// template <typename T>
// using pbds_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
using pii = pair<int, int>;
template<typename T>
using prior = priority_queue<T, vector<T>, greater<T>>;
template<typename T>
using Prior = priority_queue<T>;

#define X first
#define Y second
#define ALL(x) (x).begin(), (x).end()
#define eb emplace_back
#define pb push_back

#define fastIO() ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0)
#define RANDOM() random_device __rd; \
                 mt19937 __gen = mt19937(__rd()); \
                 uniform_int_distribution<int> __dis(0, 1); \
                 auto rnd = bind(__dis, __gen);

const int INF = 1E18;
const int mod = 1E9 + 7;

int32_t main() {
    fastIO();
    
    int v[3][3];
    for (int i = 0; i < 9; ++i) cin >> v[i/3][i%3];
    
    for (int i = 0; i < 3; ++i) {
        int minVal = min({v[i][0], v[i][1], v[i][2]});
        v[i][0] -= minVal, v[i][1] -= minVal, v[i][2] -= minVal;
    }
    
    for (int i = 0; i < 3; ++i) {
        set<int> check;
        check.insert(v[0][i]), check.insert(v[1][i]), check.insert(v[2][i]);
        if (check.size() != 1) return cout << "No\n", 0;
    }
    
    cout << "Yes\n";
    
    return 0;
}