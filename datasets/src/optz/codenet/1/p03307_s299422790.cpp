#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;

    for (int i = 1; i <= 2000000000; i++) {
        if (i % 2 == 0 && i % n == 0) {
            cout << i << endl;
            return 0;
        }
    }

    return 0;
}
