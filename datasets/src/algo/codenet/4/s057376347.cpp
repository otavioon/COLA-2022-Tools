#include <bits/stdc++.h>
using namespace std;

bool is_ok(int n, const vector<bool> &d) {
    while (n > 0) {
        if (d.at(n % 10)) return false;
        n /= 10;
    }
    return true;
}

int main() {
    int n, k;
    cin >> n >> k;
    vector<bool> d(10);
    for (int i = 0; i < k; i++) {
        int x;
        cin >> x;
        d.at(x) = true;
    }

    for (int i = 0; i <= 10000; i++) {
        if (is_ok(n + i, d)) {
            cout << n + i << endl;
            return 0;
        }
    }
}   