#include <bits/stdc++.h>
#include <stdio.h>

#define INF 1e18
#define REP(i, n) for (int i=0; i<n; i++)
#define print(x) cout << x << endl
#define debug(x) cout << #x << " = "<< x << endl

const double PI=3.141592653589793238462643383279502884197169399375105820974944;

typedef long long ll;

using namespace std;

void solve() {
    int total = 0;
    REP(i, 3) {
        REP(j, 3) {
            int tmp;
            cin >> tmp;
            total += tmp;
        }
    }
    if (total % 3 == 0) {
        print("Yes");
    } else {
        print("No");
    }
    
}

signed main() {
    solve();
}
