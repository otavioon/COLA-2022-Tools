#include <bits/stdc++.h>
using namespace std;
using lint = long long;
using pint = pair<int, int>;
using vi = vector<int>;
#define rep(i, n) for(int i = 0; i < (int)(n); i++)
#define all(v) v.begin(), v.end()
#define endl "\n"

constexpr int MOD = 1000000007;
const int INF = 1 << 30;

int main() {
    int n;
    int k;
    cin >> n >> k;
    set<int> d;
    rep(i, k) {
        int x;
        cin >> x;
        d.insert(x);
    }

    for (int i = n; i < 100000; i++) {
        string s = to_string(i);
        int di = s.size();
        bool f = true;
        rep(j, di) {
            int nd = s[j] - '0';
            if (d.find(nd) != d.end()) f = false;
        }
        if (f) {
            cout << i << endl;
            exit(0);
        }
    }
    return 0;
}
