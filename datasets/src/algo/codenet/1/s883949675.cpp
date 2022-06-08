#include "bits/stdc++.h"
#define readInt(x) scanf("%d", &x)
#define readStr(x) scanf("%s", x)
#define rep(i, n) for(int i=0; i<(n); ++i)
#define write(x) cout << (x) << endl
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
const int INF = 1 << 28;
const int MAX = 1e5 + 10;

int c[3][3];

int main()
{
    rep(i, 3) {
        rep(j, 3)
            cin >> c[i][j];
    }

    for (int j = 1; j < 3; j++) {
        int c0jrel = c[0][j] - c[0][0];
        for (int i = 1; i < 3; i++) {
            if (c[i][j] - c[i][0] != c0jrel) {
                write("No");
                return 0;
            }
        }
    }
    write("Yes");
}