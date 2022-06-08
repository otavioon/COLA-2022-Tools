#include <iostream>
#include <vector>
#include <algorithm>
#include <iomanip>
#include <cmath>
#include <map>
#include <cmath>
#include <bitset>
#include <string>
#include <queue>

using namespace std;

#define int long long

int func(string s) {
    int cnt = 0;
    bool flag = true;
    for(int i = 1; i < s.size(); i++) {
        if(s[i - 1] == s[i] && flag) {
            cnt++;
            flag = false;
        } else {
            flag = true;
        }
    }
    return cnt;
}

signed main() {
    string s; cin >> s;
    int k; cin >> k;

    int cnt1 = func(s);
    int cnt2 = func(s + s) - cnt1;
    int ans = cnt1 + cnt2 * (k - 1);

    cout << ans << endl;
    return 0;
}