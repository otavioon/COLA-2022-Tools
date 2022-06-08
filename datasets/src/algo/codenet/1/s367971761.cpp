#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

#define REP(i, a, b) for (int i = int(a); i < int(b); i++)
#define dump(val) cerr << __LINE__ << ":\t" << #val << " = " << (val) << endl

using namespace std;

typedef long long int lli;

int main() {
    int c[3][3];
    REP (i, 0, 3) REP (j, 0, 3) cin >> c[i][j];
    int a2 = c[1][0] - c[0][0], a3 = c[2][0] - c[0][0];
    if (a2 + c[0][1] == c[1][1] && a2 + c[0][2] == c[1][2] && a3 + c[0][1] == c[2][1] && a3 + c[0][2] == c[2][2]) {
        cout << "Yes" << endl;
    } else {
        cout << "No" << endl;
    }
    return 0;
}