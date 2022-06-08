/**
 * @author torith
 * @date 2018-10-24
 */

#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main(){

    cin.tie(0);
    ios::sync_with_stdio(false);

    int base1,base2,base3;
    cin >> base1 >> base2 >> base3;
    bool ans = true;
    for (int i = 0; i < 2; ++i) {
        int a,b,c;
        cin >> a >> b >> c;
        int dif = a - base1;
        if (b - dif != base2 || c - dif != base3) ans = false;
    }

    if (ans) cout << "Yes" << "\n";
    else cout << "No" << "\n";

    return 0;
}

