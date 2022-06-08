#define _USE_MATH_DEFINES
#include <bits/stdc++.h>
using namespace std;

#define rep(i, n) REP(i, 0, n)
#define ALL(v) v.begin(), v.end()
#define MSG(a) cout << #a << " " << a << endl;
#define REP(i, x, n) for (int i = x; i < n; i++)
#define OP(m) cout << m << endl
typedef long long ll;
typedef unsigned long long ull;

int main()
{
    int n;
    cin >> n;
    int a[n];
    rep(i, n) cin >> a[i];

    int cnt = 0;
    int nb = 0;
    rep(i, n)
    {
        cnt++;
        if (a[nb] == 2)
        {
            OP(cnt);
            return 0;
        }
        nb = a[nb] - 1;
    }
    OP(-1);
    return 0;
}