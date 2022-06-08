#include<bits/stdc++.h>
#define ll long long
#define rep(i, n) for(int i=0; i<n; i++)
#define REP(i, n) for(int i=0; i<=n; i++)
#define repr(i, n) for(int i=n; i>0; i--)
#define REPR(i, n) for(int i=n; i>=0; i--)
const ll INF = 1LL<<60;
const int INT_INF = 1e9;
const ll MOD = 1e9+7;
template<class T> void puts(T x) { std::cout << x << std::endl; }
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }
using namespace std;

int c[3][3];

int main() {
    rep(i, 3) {
        rep(j, 3) {
            cin >> c[i][j];
        }
    }

    if (c[0][1] - c[0][0] == c[1][1] - c[1][0] && c[1][1] - c[1][0] == c[2][1] - c[2][0]
     && c[0][2] - c[0][1] == c[1][2] - c[1][1] && c[1][2] - c[1][1] == c[2][2] - c[2][1]){
        cout << "Yes" << endl;
    } else {
        cout << "No" << endl;
    }
}
