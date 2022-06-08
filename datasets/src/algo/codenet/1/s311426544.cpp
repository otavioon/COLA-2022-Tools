#include <bits/stdc++.h>
using namespace std;
     
int c[3][3];

void solve() {
    int a[3], b[3];
    a[0] = 0;
    b[0] = c[0][0];
    b[1] = c[0][1];
    b[2] = c[0][2];
    a[1] = c[1][0] - b[0];
    a[2] = c[2][0] - b[0];

    if (c[1][1] == a[1] + b[1] && c[1][2] == a[1] + b[2] && c[2][1] == a[2] + b[1] && c[2][2] == a[2] + b[2]) {
        cout << "Yes" << endl;
    } else {
        cout << "No" << endl;
    }
}

int main() {
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            cin >> c[i][j];
        }
    }
    solve();
}