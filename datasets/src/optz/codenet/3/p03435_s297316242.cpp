#include <bits/stdc++.h>
#define repl(i, l, r) for (ll i = l; i < r; i++)
#define rep(i, n) repl(i, 0, n)
using namespace std;
using ll = long long;
using Graph = vector<vector<int>>;
using P = pair<ll, ll>;

int c[3][3];

int main()
{
    rep(i, 3) {
        rep(j, 3) cin >> c[i][j];
    } 
    vector<int> x(3);
    rep(i, 3) x[i] = c[i][1] - c[i][0]; 
    vector<int> y(3);
    rep(i, 3) y[i] = c[i][2] - c[i][1]; 
    sort(x.begin(), x.end());
    sort(y.begin(), y.end());
    if(x[0] == x[2] && y[0] == y[2]) cout << "Yes" << endl;
    else cout << "No" << endl;
    return 0;
}
