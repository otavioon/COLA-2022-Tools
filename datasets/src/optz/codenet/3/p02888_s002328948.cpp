#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep2(i, s, n) for (int i = (s); i < (int)(n); i++)

const int INF_32 = 1LL << 30;
const int64_t INF_64 = 1LL << 60;
const int MOD = 1000000007;

typedef long long ll;

ll GCD(ll a, ll b) { return b ? GCD(b, a % b) : a; }

ll LCM(ll x, ll y)
{
    return x * y / GCD(x, y);
}

using Graph = vector<vector<int>>;

typedef pair<int, int> P;

int main()
{
    int n;
    cin >> n;
    vector<int> l(n);
    rep(i, n)
    {
        cin >> l.at(i);
    }
    sort(l.begin(), l.end());
    int ans = 0;
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            int bound = lower_bound(l.begin(), l.end(), l.at(i) + l.at(j)) - l.begin();
            int count = bound - 1 - j;
            ans += count;
        }
    }
    cout << ans << endl;
}