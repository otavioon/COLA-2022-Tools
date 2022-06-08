#include <bits/stdc++.h>
using namespace std;
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
typedef long long ll;
// Welcome to my source code!

int main() {
    int c[3][3];
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            cin >> c[i][j];
        }
    }
    cout << (c[0][0] - c[1][0] == c[0][1] - c[1][1] && c[0][1] - c[1][1] == c[0][2] - c[1][2] && c[1][0] - c[2][0] == c[1][1] - c[2][1] && c[1][1] - c[2][1] == c[1][2] - c[2][2] ? "Yes" : "No") << endl;
}