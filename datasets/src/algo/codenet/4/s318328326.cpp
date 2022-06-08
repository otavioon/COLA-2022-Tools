#include <iostream>
#include <vector>

using namespace std;
typedef long long ll;
#define REP(i,n) for (ll i = 0; i < (n); ++i)

bool check(ll x, const vector<bool>& ng){
    while(x > 0){
        if(ng.at(x % 10)){
            return false;
        }
        x /= 10;
    }
    return true;
}

int main(){
    ll n, k;
    cin >> n >> k;
    vector<bool> ng(10, false);
    REP(i, k){
        ll di;
        cin >> di;
        ng.at(di) = true;
    }

    for(ll ans = n; ans <= 100000; ++ans){
        if(check(ans, ng)){
            cout << ans << endl;
            return 0;
        }
    }
    return 0;
}
