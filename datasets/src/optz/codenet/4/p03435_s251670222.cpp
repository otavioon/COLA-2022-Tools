#include <bits/stdc++.h>

#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define ll long long

using namespace std;


int main() {

    ll tmp[9];
    ll sum = 0;
    string ans = "Yes";


    rep(i,9){
        cin >> tmp[i];
        sum += tmp[i];
    }
    if(tmp[0] + tmp[4] + tmp[8] != tmp[2] + tmp[4] + tmp[6]) ans = "No";
    if(tmp[0] + tmp[4] + tmp[8] != tmp[0] + tmp[5] + tmp[7]) ans = "No";
    if(tmp[0] + tmp[4] + tmp[8] != tmp[1] + tmp[3] + tmp[8]) ans = "No";
    if(tmp[0] + tmp[4] + tmp[8] != tmp[1] + tmp[5] + tmp[6]) ans = "No";
    if(tmp[0] + tmp[4] + tmp[8] != tmp[2] + tmp[3] + tmp[7]) ans = "No";


    cout << ans;
    return 0;
}









