#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define PI 3.14159265358979323846
#define int long long
constexpr int INF = numeric_limits<int>::max() / 2;
constexpr long long INFL = numeric_limits<long long>::max() / 2;
constexpr int MOD = 1000000007;
using Graph = vector<vector<int>>;



signed main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    int c[3][3];
    rep(i,3){
        rep(j,3){
            cin>>c[i][j];
        }
    }
    string ans="Yes";
    if(c[1][0]-c[0][0]!=c[1][1]-c[0][1] || c[1][1]-c[0][1]!=c[1][2]-c[0][2]) ans="No";
    if(c[2][0]-c[0][0]!=c[2][1]-c[0][1] || c[2][1]-c[0][1]!=c[2][2]-c[0][2]) ans="No";
    cout << ans << endl;




}
