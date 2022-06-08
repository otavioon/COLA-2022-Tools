#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
#define rep(i,n) for (int (i)=0; (i) < (n); (i)++)

int main()
{
    ll N; cin >> N;
    vector<ll> a(N, 0);
    rep(i,N) {
        ll tmp; cin >> tmp;
        a[i] = tmp - 1;
    }
    ll ansi = 0;
    ll ans = 0;
    rep(i,N) {
        ans++;
        if (a[ansi] == 1) {
            cout << ans << endl;
            exit(0); 
        }
        ansi = a[ansi];
    }
    cout << -1 << endl;



}
