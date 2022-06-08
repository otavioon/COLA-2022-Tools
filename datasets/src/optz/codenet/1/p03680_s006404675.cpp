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
    int n;
    cin >> n;
    int a[n];
    rep(i, n) {
        cin >> a[i];
        a[i]--;
    }

    int button = 0;
    int cnt = 0;
    rep(i, n) {
        button = a[button];
        cnt++;
        if(button == 1) {
            cout << cnt << endl;
            return 0;
        }
    }

    cout << -1 << endl;
    return 0;
}