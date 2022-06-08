#define _USE_MAT_DEFINES
#include<iostream>
#include <iomanip>
#include<stdio.h>
#include<string>
#include<vector>
#include<algorithm>
#include<cmath>
#include <queue>
#include <utility>
#include <map>
#include <set>
#include <deque>
#include <numeric>
#include <functional>
using namespace std;

#define INF 1e9

int main() {
    vector<vector<int>>c(3, vector<int>(3));
    vector<int>a(3), b(3), max_(3, 0);
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            cin >> c[i][j];
            max_[i] = max(max_[i], c[i][j]);
        }
    }

    for (int i = 0; i <= max_[0]; i++) {
        for (int j = 0; j <= max_[1]; j++) {
            for (int k = 0; k <= max_[2]; k++) {
                bool ok = true;
                a[0] = i; a[1] = j; a[2] = k;
                b[0] = c[0][0] - a[0];
                b[1] = c[0][1] - a[0];
                b[2] = c[0][2] - a[0];
                if (b[0] < 0 || b[1] < 0 || b[2] < 0) {
                    ok = false;
                    continue;
                }
                else {
                    for (int l = 1; l < 3; l++) {
                        for (int m = 0; m < 3; m++) {
                            if (c[l][m] != a[l] + b[m])ok = false;
                        }
                        if (!ok)break;
                    }
                }
                if (ok) {
                    cout << "Yes" << endl;
                    return 0;
                }
            }
        }
    }
    cout << "No" << endl;

    return 0;
}