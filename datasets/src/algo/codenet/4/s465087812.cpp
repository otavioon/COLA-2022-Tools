/**
 *    author:  FromDihPout
 *    created: 2020-06-18
**/

#include <bits/stdc++.h>
using namespace std;


int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int n, k;
    cin >> n >> k;
    set<int> bad;
    for (int i = 0; i < k; i++) {
        int x;
        cin >> x;
        bad.insert(x);
    }
    int amt = n;
    while (1) {
        int copy = amt;
        bool ok = 1;
        while (copy > 0) {
            int digit = copy % 10;
            if (bad.count(digit)) {
                ok = 0;
                break;
            }
            copy /= 10;
        }
        if (ok) {
            cout << amt << endl;
            break;
        }
        amt++;
    }
    return 0;
}