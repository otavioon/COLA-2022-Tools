#include <algorithm>
#include <climits>
#include <cmath>
#include <csignal>
#include <cstdio>
#include <cstdlib>
#include <iomanip>
#include <iostream>
#include <string>
#include <vector>

using ll = long long;
using namespace std;

int dfs(int now, int sum, int n, vector<bool> &d) {
    if (now >= 1000000) {
        return now;
    }
    if (sum >= n) {
        return sum;
    }
    int ret = 1e8;
    for (int i=0; i<=9; i++) {
        if (d.at(i)) {
            ret = min(ret, dfs(now*10, sum + now*i, n, d));
        }
    }
    return ret;
}

int main() {
    int n = 0, k = 0;
    cin >> n >> k;
    int buf = 0;
    vector<bool> d(10, true);
    for (int i=0; i<k; i++) {
        cin >> buf;
        d.at(buf) = false;
    }
    cout << dfs(1, 0, n, d) << endl;
    return 0;
}
