#include <bits/stdc++.h>

#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define ll long long

using namespace std;


int main() {

    ll tmp;
    ll sum = 0;


    rep(i,9){
        cin >> tmp;
        sum += tmp;
    }

    cout << ((sum%3 == 0)?"Yes":"No");

    return 0;
}









