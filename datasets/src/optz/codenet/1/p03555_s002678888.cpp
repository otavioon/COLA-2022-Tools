#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;

int main() {
    vector<vector<char>> c(2, vector<char>(3));

    for (int i=0; i<2; ++i) {
        for (int j=0; j<3; ++j) {
            cin >> c[i][j];
        }
    }

    if (c[0][0]==c[1][2] && c[0][1]==c[1][1] && c[0][2]==c[1][0]) {
        cout << "YES" << endl;
    }
    else {
        cout << "NO" << endl;
    }
    return 0;
}
