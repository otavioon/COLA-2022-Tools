#include <bits/stdc++.h>

#define debug(x) cerr << #x << ": " << x << endl
#define debugArray(x, n)                                                       \
    for(long long hoge = 0; (hoge) < (n); ++(hoge))                            \
    cerr << #x << "[" << hoge << "]: " << x[hoge] << endl
using namespace std;

using ll = long long;
using ull = unsigned long long;
const ll INF = LLONG_MAX / 2;
const ll MOD = 1e9 + 7;

signed main() {
    cin.tie(0);
    ios::sync_with_stdio(0);
    int c[3][3];
    for(int i = 0; i < 3; i++) {
        for(int j = 0; j < 3; j++) {
            cin >> c[i][j];
        }
    }
    bool isok = true;
    for(int i = 1; i < 3; i++) {
        for(int j = 0; j < 3; j++) {
            isok &= c[0][j] == c[i][j];
        }
    }
    cout << (isok ? "Yes" : "No") << endl;
    return 0;
}