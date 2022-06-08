#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>
#include<map>
#include<set>
#include<stack>
#include<cmath>
#include<sstream>
#include<string>
using namespace std;
typedef long long ll;
ll mod = 1e9+7;
#define rep(i,n) for(int i = 0; i < (n); ++i)

int main(){
    ll n;
    cin >> n;
    map<ll, int> mp;
    ll tmp_num = n;
    for ( ll i = 2; i * i < n; ++i ) {
        if ( tmp_num == 1 ) {
            break;
        }
        while(1) {
            if ( tmp_num % i != 0 ) {
                break;
            }
            ++mp[i];
            tmp_num /= i;
        }
    }
    if ( tmp_num != 1 ) {
        ++mp[tmp_num];
    }

    vector<ll> fv;
    ll common_num = 1;
    for ( auto tmp_num : mp ) {
//        cout << tmp_num.first << " " << tmp_num.second << endl;
        if ( tmp_num.second % 2 == 1 ) {
            fv.push_back(tmp_num.first);
        }
        else {
            rep(i, tmp_num.second/2) {
                common_num *= tmp_num.first; 
            }
        }
    }

//    for ( auto tmp_num : fv ) {
//        cout << tmp_num << endl;
//    }
//    cout << common_num << endl;

    auto keta = [&] ( ll a ) {
        ll cnt = 0;
        while(1) {
            if ( a == 0 ) break;
            ++cnt;
            a /= 10;
        }
        return cnt;
    };

//    ll a = 0;
//    ll b = 0;
//    if ( fv.empty() ) {
//        a = n;
//        b = 1;
//        ll keta_num = keta(n);
//        cout << keta_num << endl;
//        return 0;
//    }

    ll ans = 1e18;
    for ( auto tmp_num : fv ) {
        ll bigger_num = max(tmp_num, n / tmp_num / common_num );
        ll keta_num = keta(bigger_num);
        ans = min(ans, keta_num);
    }
    cout << ans << endl;
    return 0;
}
