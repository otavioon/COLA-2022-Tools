#include <iostream>
#include <fstream>
#include <cmath>
#include <string>
#include <vector>
#include <map>
#include <queue>
#include <set>
#include <unordered_set>
#include <bitset>
#include <limits>
#include <algorithm>

#define MOD_BIG 1000000007
using std::string;
using std::cin;
using std::cout;
using std::cerr;
using std::endl;
using ll = long long;
using std::vector;

template<typename T> void ndarray(vector<T> &vec, int len) { vec.resize(len); }
template<typename T, typename... Args> void ndarray(vector<T> &vec, int len, Args... args) {
    vec.resize(len);
    for (auto &v : vec) ndarray(v, args...);
}

//////////////////////////////////////

//////////////////////////////////////

int main() {
    
    string S;
    ll K;
    cin >> S >> K;
    
    ll cnt = 0;
    char b = S[0];
    ll n = S.length();
    for (int i = 1; i < n; i++) {
        if (b == S[i]) {
            cnt += 1;
            b = '!';
        } else {
            b = S[i];
        }
    }
    bool f1 = false;
    if (b == S[0]) {
        f1 = true;
    }
    ll cnt2 = 0;
    for (int i = 0; i < n; i++) {
        if (b == S[i]) {
            cnt2 += 1;
            b = '!';
        } else {
            b = S[i];
        }
    }
    bool f2 = false;
    if (b == S[0]) {
        f2 = true;
    }
    //cerr << cnt << endl;
    //cerr << cnt2 << endl;
    ll ans = 0;
    if (f1 && f2) {
        ans = cnt + cnt2*(K-1);
    } else if (f1 && !f2) {
        ans = (cnt + cnt2)*(K/2) + cnt*(K%2);
    } else if (!f1 && f2) {
        ans = cnt + (2*cnt2)*((K-1)/2);
    } else {
        ans = (cnt + cnt2)*(K/2) + cnt*(K%2);
    }
    
    cout << ans << endl;
    
    return 0;
}
