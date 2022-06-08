/*   _ _ _                     
    | | | | ___  ___           
    | | | || . ||  _|          
    |_____||_  ||_|  _____     
             |_|    |_____|  */
// Time : 19/10/15
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define inf 0x3f3f3f3f
int main(){
#ifdef Wqr_
    freopen("in.txt","r",stdin);
#endif
    std::ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
    string in;
    ll k, ans = 0;
    cin >> in;
    cin >> k;
    ll len = in.length();
    //kase1
    set<char> sett;
    for(auto i : in){
        sett.insert(i);
    }
    if(sett.size() == 1){
        ll ans = (len * k) / 2;
        cout << ans << endl;
        return 0;
    }
    //kase2
    for(int i = 1; i < len; ++i){
        if (in[i] == in[i - 1]) {
            ++ans;
            ++i;
        }
    }
    ans *= k;
    if(in.front() == in.back()){
        ll a = 1, b = 1;
        for (int i = 1; i < len; ++i) {
            if (in[i] == in[i - 1]) ++a;
            else break;
        }
        for (int i = len - 2; i >= 0; i--) {
            if (in[i] == in[i + 1]) ++b;
            else break;
        }
        // cout << a << " " << b << endl;
        ll tmp = -a / 2 + -b / 2 + (a + b) / 2;
        ans += tmp * (k - 1);
    }
    cout << ans << endl;
    return 0;
}