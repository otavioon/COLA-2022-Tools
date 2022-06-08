#include"bits/stdc++.h"
using namespace std;

int main() {
    vector<vector<int>> c(3, vector<int>(3));
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            cin >> c[i][j];
        }
    }

    vector<int> a(3), b(3);
    bool ok = false;
    for (int i = -100; i <= 100; i++) {
        a[0] = i;
        for (int j = 0; j < 3; j++) {
            b[j] = c[0][j] - a[0];
        }
        a[1] = c[1][0] - b[0];
        a[2] = c[2][0] - b[0];

        bool flag = true;
        for (int j = 1; j < 3; j++) {
            for (int k = 1; k < 3; k++) {
                if (c[j][k] != a[j] + b[k]) {
                    flag = false;
                }
            }
        }
        if (flag) {
            ok = true;
            break;
        }
    }
    if (ok) {
        cout << "Yes" << endl;
    } else {
        cout << "No" << endl;
    }
}