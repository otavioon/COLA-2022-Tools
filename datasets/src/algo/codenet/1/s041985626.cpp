#include "bits/stdc++.h"
using namespace std;
#define ll long long int
#define rep(i,n) for( int i = 0; i < n; i++ )
#define REP(i,s,t) for( int i = s; i <= t; i++ )
#define dump(x)  cerr << #x << " = " << (x) << endl;
#define INF 2000000000
#define mod 1000000007
#define INF2 1000000000000000000


int main(void)
{
    cin.tie(0);
    ios::sync_with_stdio(false);
    int c[3][3] = {{}};
    rep(i, 3) rep(j, 3) cin >> c[i][j];
    int A = c[0][0] + c[1][1] + c[2][2];
    int B = c[0][1] + c[1][2] + c[2][0];
    int C = c[0][2] + c[1][0] + c[2][1];
    if (A == B && B == C) cout << "Yes" << endl;
    else cout << "No" << endl;


    return 0;
}
