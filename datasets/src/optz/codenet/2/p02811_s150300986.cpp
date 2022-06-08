#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define eb emplace_back
#define fi first
#define se second
#define endl '\n'
#define fcin ios::sync_with_stdio(false); cin.tie(nullptr);
#define INF 0x3f3f3f3f
#define all(x) x.begin(), x.end()
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

typedef unsigned long long ll;
typedef pair<int, int> pii;

ll gcd(ll a, ll b){
    return b == 0 ? a : gcd(b, a%b);
}

ll lcm(ll a, ll b){
    return (a / gcd(a, b)) * b;
}

int main(){
    fcin;
    ll n, m;
    cin >> n >> m;

    vector<ll> a(n);
    for(ll i = 0; i < n; i++) cin >> a[i];

    ll L = a[0]/2;
    for(ll i = 1; i < n; i++) L = lcm(L, a[i]/2);
    
    ll ans = 0;
    for(ll i = 0; i < n; i++) if((L / (a[i] / 2)) % 2 == 0) return cout << 0, 0;

    for(ll i = L; i <= m; i += 2LL*L) ans++;

    cout << ans << endl;
    return 0;
}

