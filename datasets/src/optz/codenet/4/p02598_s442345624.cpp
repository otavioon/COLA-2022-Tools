#include <bits/stdc++.h>
using namespace std;

#define rep(i,n) for(i = 0;i < n;++i)
#define all(v) v.begin(), v.end()
using ll = long long;

int main()
{
    ll i,j;
    ll n,k;
    cin >> n >> k;
    vector<ll> a(n);
    ll ma = -1e9;
    for(i = 0;i < n;++i){
        cin >> a.at(i);
        ma = max(a.at(i), ma);
    }
    ll sup = 0;
    ll inf = ma;
    while((inf - sup) > 1){
        ll mid = (sup + inf)/2;
        ll cnt = 0;
        for(i = 0;i < n;++i){
            if(a.at(i)%mid == 0){
                cnt += a.at(i)/mid-1;
            }else{
                cnt += a.at(i)/mid;
            }
        }
        if(cnt > k) sup = mid;
        else inf = mid;
    }
    cout << inf << endl;

    return 0;
}