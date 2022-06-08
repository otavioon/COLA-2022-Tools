#include <iostream>
#include <cstdio>
#include <string>
#include <algorithm>
#include <utility>
#include <cmath>
#include <vector>
#include <stack>
#include <queue>
#include <set>
#include <map>
#define rep(i, n) for(int i = 0; i < n; i++)
using namespace std;
typedef long long ll;
const ll mod = 1000000007;

int main() {
    int c[3][3];
    rep(i, 3) {
        rep(j, 3) {
            cin >> c[i][j];
        }
    }

    if( (c[0][1] + c[1][0] == c[0][0] + c[1][1]) && (c[0][2] + c[1][0] == c[0][0] + c[1][2]) 
        && (c[0][1] + c[2][0] == c[0][0] + c[2][1]) && (c[0][2] + c[2][0] == c[0][0] + c[2][2]) ) {
            cout << "Yes";
    }
    else {
        cout << "No";
    }

    cout << endl;
    return 0;
}