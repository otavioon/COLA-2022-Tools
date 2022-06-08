#include <bits/stdc++.h>
#define rep(i,n) for(int (i)=0;(i)<(n);++(i))
#define all(x) (x).begin(),(x).end()
#define dump(x) cout << #x << " = " << (x) << endl
#define YES(n) cout << ((n) ? "YES" : "NO") << endl
#define Yes(n) cout << ((n) ? "Yes" : "No") << endl
#define yes(n) cout << ((n) ? "yes" : "no") << endl

using namespace std;
using ll = long long;
using P = pair<int, int>;

const int INF = 1001001001;
const vector<int> di = {-1,  0, 1, 0};
const vector<int> dj = { 0, -1, 0, 1};

void chmin(int &a, int b) { if (a > b) a = b; }

ll GCD(ll a, ll b) {
    if (b == 0) return a;
    else return GCD(b, a % b);
}
ll LCM(ll a, ll b) {
    ll g = GCD(a, b);
    return a / g * b;
}


int main() {
    int n; cin >> n;
    vector<int> b(n - 1);
    rep(i, n - 1) cin >> b[i];
    reverse(all(b));
    vector<int> a(n, -1);

    rep(i, n) {
        if (a[i] >= 0) continue;
        if (i == 0) a[i] = b[i];
        else {
            if (b[i - 1] >= b[i]) a[i] = b[i];
            else a[i] = b[i - 1];
        }
    }
    a[n - 1] = a[n - 2];

    int sum = 0;
    rep(i, n) sum += a[i];

    cout << sum << endl;
}