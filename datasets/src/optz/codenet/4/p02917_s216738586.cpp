#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ii = pair<ll, ll>;
using iii = pair<ii, ll>;
#define vt vector
#define pb push_back
#define pf push_front
#define mp make_pair
#define fi first
#define se second
#define __lcm(a, b) a * b / __gcd(a, b)
const ll MOD = 1e9 + 7;
const ll INF = 2e9;
const ll N = 1e2 + 5;

int n, ans;
int a[N], b[N];

void solve() {
    cin >> n;
    for(int i = 1; i < n; i++) {
        cin >> b[i];
    }
    a[1] = b[1];
    for(int i = 2; i <= n; i++) {
        a[i] = b[i - 1];
        if(b[i] < b[i - 1]) a[i] = b[i];
    }
    a[n] = b[n - 1];
    for(int i = 1; i <= n; i++) {
        ans += a[i];
    }
    cout << ans << "\n";
}

int main() {
    
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    
    solve();
    
}