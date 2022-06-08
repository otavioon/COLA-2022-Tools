#include <algorithm>
#include <bitset>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cctype>
#include <functional>
#include <iomanip>
#include <iostream>
#include <iterator>
#include <map>
#include <queue>
#include <set>
#include <string>
#include <vector>
#define ll long long
#define imfor(i, n) for(int i = 0; i < n; i++)
using namespace std;
ll MOD = 1000000007;

int main() {
    int c[9];
    imfor(i, 9) {
        cin >> c[i];
    }
    if (c[3] - c[0] == c[4] - c[1] && c[5] - c[2] == c[3] - c[0]) {
        if (c[6] - c[0] == c[7] - c[1] && c[8] - c[2] == c[6] - c[0]) {
            cout << "Yes" << endl;
            return 0;
        }
    }
    cout << "No" << endl;
}