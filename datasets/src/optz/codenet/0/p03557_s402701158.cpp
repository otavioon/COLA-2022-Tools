#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); i++)
#define chmin(x,y) x = min(x,y)
#define chmax(x,y) x = max(x,y)
using namespace std;
typedef long long ll;

int main() {
    int n;
    cin>>n;
    vector<ll> a(n),b(n),c(n);
    rep(i,n) cin>>a[i];
    rep(i,n) cin>>b[i];
    rep(i,n) cin>>c[i];
    
    ll ans = 0;
    for(ll i=0;i<n;i++){
        ll d = lower_bound(a.begin(), a.end(), b[i]) - a.begin();
        ll e = c.end() - upper_bound(c.begin(), c.end(), b[i]);
        ans += d*e;
    }
    cout<<ans<<endl;
    
    return 0;
}
