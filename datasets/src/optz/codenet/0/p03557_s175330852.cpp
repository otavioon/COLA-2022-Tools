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


int main(){
    int n;
    cin >> n;
    vector<ll> a(n), b(n), c(n);
    rep(i, n) cin >> a[i];
    rep(i, n) cin >> b[i];
    rep(i, n) cin >> c[i];

    sort(all(a));
    sort(all(b));
    sort(all(c));

    int ans = 0;
    rep(i, n) {
        ll A = a[i];
        int bidx = upper_bound(all(b), A) - b.begin();
        if (bidx < b.size()) {
            for (int j=bidx;j<n;++j) {
                ll B = b[j];
                int cidx = upper_bound(all(c), B) - c.begin();
                if (cidx < n) {
                        ans+= (n - cidx);
                }
            }
        }
    }
    cout << ans << endl;
}