#include <algorithm>
#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define all(x) (x).begin(), (x).end()
#define ll long long
#define INF 100000000000000000

int main() {
    int sum = 0;
    rep(i, 3) {
        rep(j, 3) {
            int a;
            cin >> a;
            sum += a;
        }
    }
    if (sum % 3 == 0)
        cout << "Yes" << endl;
    else
        cout << "No" << endl;
}