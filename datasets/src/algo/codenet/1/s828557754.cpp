#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <string>
#include <queue>
#define FOR(i,a,b) for(int i=(a);i<(b);++i)
#define REP(i,n)  FOR(i,0,n)

using namespace std;

int c[3][3];

int main()
{
    REP(i, 3) {
        REP(j, 3) {
            cin >> c[i][j];
        }
    }
    if (c[0][0] - c[0][1] != c[1][0] - c[1][1] || c[1][0] - c[1][1] != c[2][0] - c[2][1]) {
        cout << "No" << endl;
        return 0;
    }
    if (c[0][0] - c[0][2] != c[1][0] - c[1][2] || c[1][0] - c[1][2] != c[2][0] - c[2][2]) {
        cout << "No" << endl;
        return 0;
    }
    cout << "Yes" << endl;
    return 0;
}