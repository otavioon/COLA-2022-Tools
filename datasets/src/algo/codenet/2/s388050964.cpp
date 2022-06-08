#include <bits/stdc++.h>
#define fr(i, n) for (int i = 0; i < n; i++)
#define frab(i, a, b) for (int i = a; i < b; i++)
#define pb push_back
#define mp make_pair
#define fi first
#define se second

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

const ll INF = 1e9 + 10;
const ll MOD = 1e9 + 7;
const ld EPS = 1e-9;
const ld PI = acos(-1);
const int M = 1e3 + 10;
const int N = 1e6 + 10;

int a[N];

void solve() {
    int n;
    scanf("%d", &n);
    multiset<int> m;
    fr(i, n) {
        scanf("%d", &a[i]);
        m.insert(a[i]);
    }

    int ans = 0;
    //cout << m.size() << endl;
    while (m.size()) {
        auto it = m.end();
        it--;
        int cnt = 0;
        int cur = *it;
        int cur2 = cur;
        m.erase(it);
        while (cur) {
            cnt++;
            cur >>= 1;
        }
        int sum = (1 << cnt);
        int second = sum - (cur2);

        auto it2 = m.find(second);
        if (it2 != m.end()) {
            ans++;
            m.erase(it2);
        }
    }
    cout << ans;

}

int main() {
    //freopen("a.in", "r", stdin);
    //ios_base::sync_with_stdio(false);
    solve();

    return 0;

}
