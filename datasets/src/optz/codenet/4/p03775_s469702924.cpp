#include<bits/stdc++.h>

using namespace std;

typedef long long ll;

int main() {
    ll a;
    cin >> a;
    set<ll>s;
    for (ll i = 1; i * i <= a ; i++) {
        if(a % i == 0) {
            s.insert(i);
            s.insert(a/i);
        }
    }
    vector<ll>v(s.begin(), s.end());
    ll l = INT_MAX, p;
    ll g, ans = INT_MAX;
    for (ll i = 0; i < v.size(); i++) {
        for (ll j = 0; j < v.size(); j++) {
            ll z = v[i] * v[j];
            if(z == a) {
                // p = abs(v[i] - v[j]);
               // if(p <= l) {
                   // l = p;
                    string w = to_string(v[i]);
                    string u = to_string(v[j]);
                    ll o = w.size();
                    ll k = u.size();
                    g = max(o, k);
                    ans = min(ans, g);

               // }
            }
        }
    }

    cout << ans << endl;
    return 0;
}
