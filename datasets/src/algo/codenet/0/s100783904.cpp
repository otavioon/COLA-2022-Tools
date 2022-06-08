#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <string>

using ll = long long;

using namespace std;

int main() {
    string s;
    long k;
    cin >> s >> k;
    char prev = '\0';
    long one=0, two=0, len=s.size();
    bool row2 = false, all = true;
    for (long i=0; i<2*len; i++) {
        char c = s[i % len];
        if (row2 || prev != c) {
            if (prev != '\0' && prev != c) all = false;
            prev = c;
            row2 = false;
            continue;
        }
        if (i < len) one++;
        else two++;
        row2 = true;
    }
    if (all) cout << one * (k - k / 2) + two * (k / 2) << '\n';
    else cout << one + two * (k - 1) << '\n';
    return 0;
}