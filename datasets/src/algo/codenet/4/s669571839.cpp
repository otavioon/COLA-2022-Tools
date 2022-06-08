#include <bits/stdc++.h>
using namespace std;

set<int> D;

bool contains_digit(int n) {
    bool flag = false;
    while (n > 0) {
        flag |= D.count(n % 10) > 0;
        n /= 10;
    }
    return flag;
}

int main() {
    int N, K; cin >> N >> K;
    for (int i = 0; i < K; ++i) {
        int d; cin >> d;
        D.insert(d);
    }

    for (int i = N; i < N*10; ++i) {
        if (!contains_digit(i)) {
            cout << i << endl;
            break;
        }
    }
}