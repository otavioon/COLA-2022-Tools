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
    set<int> good;
    for (int i = 0; i <= 9; i++) {
        good.insert(i);
    }
    for (int i = 0; i < k; i++) {
        int x;
        cin >> x;
        good.erase(x);
    }
    int digits[8], len = 0;
    while (n > 0) {
        digits[len] = n % 10;
        len++;
        n /= 10;
    }
    set<int>::iterator low;
    int carry = 0, ans = 0, power = 1;
    for (int i = 0; i < len; i++) {
        digits[i] = (digits[i] + carry) % 10;
        carry = 0;
        low = lower_bound(good.begin(), good.end(), digits[i]);
        if (low == good.end()) {
            low = lower_bound(good.begin(), good.end(), 0);
            carry = 1;
        }
        ans += *low * power;
        power *= 10;
    }
    cout << ans << endl;
    return 0;
}