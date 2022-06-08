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
    string s;
    int k;
    cin >> s >> k;
    set<int> d;
    rep(i, k) {
        int x;
        cin >> x;
        d.insert(x);
    }

    int di = s.size();

    string res = "";

    bool larger = false;

    rep(i, di) {
        int nd = s[i] - '0';
        rep(a, 10) {
            if (d.find(a) == d.end()) {
                if (a == 0 && i == 0) continue;
                if (a > nd) larger = true;
                if (!larger && nd > a) continue;
                char c = '0';
                c += a;
                res += c;
                break;
            }
        }
    }
    cout << res << endl;
    return 0;
}
