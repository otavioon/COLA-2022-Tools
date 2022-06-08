#include <bits/stdc++.h>

#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define ll long long

using namespace std;


int main() {

    ll tmp[9];
    ll sum = 0;


    rep(i,9){
        cin >> tmp[i];
        sum += tmp[i];
    }
    if(tmp[0] + tmp[4] + tmp[8] != tmp[2] + tmp[4] + tmp[6]) cout << "No";
    else cout << ((sum%3 == 0)?"Yes":"No");

    return 0;
}









