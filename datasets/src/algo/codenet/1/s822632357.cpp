#include "bits/stdc++.h"
using namespace std;
const int MOD = 1e9 + 7;
typedef long long lint;
const int INF = 1e7;
#define rep(i, n) for (int i = 0; i < (n); ++i)
#define trep(i, k, n) for (int i = (k); i < (int)(n); ++i)
typedef pair<int, int> P;
typedef vector<int> vi;
typedef vector<vi> vvi;
int main()
{
    int cc[3][3];
    rep(i, 3)
    {
        rep(j, 3)
        {
            cin >> cc[i][j];
        }
    }
    int a, b, c;
    a = cc[0][0] + cc[1][1] + cc[2][2];
    b = cc[0][1] + cc[1][2] + cc[2][0];
    c = cc[1][0] + cc[2][1] + cc[0][2];
    if (a == b && b == c)
    {
        cout << "Yes" << endl;
    }
    else
    {
        cout << "No" << endl;
    }
    return 0;
}