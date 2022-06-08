#pragma GCC optimize("Ofast")
#include "bits/stdc++.h"
using namespace std;
using ll = long long;
using ull = unsigned long long;
#define PI 3.141592
#define MOD7 1000000007
#define LL_INF 9000000000000000000
#define LL_MINF -9000000000000000000
#define INT_INF 2000000000
#define INT_MINF -2000000000
#define all(a) (a).begin(), (a).end()
#define fi first
#define se second
const int dx[8] = {1, 0, -1, 0, 1, -1, -1, 1};
const int dy[8] = {0, 1, 0, -1, 1, 1, -1, -1};


int main(){
    vector<vector<int>> G(3, vector<int>(3));
    for(int i = 0; i < 3; i++) for(int j = 0; j < 3; j++) cin >> G[i][j];
    bool ok = true;
    for(int i = 0; i < 2; i++){
        int c;
        for(int j = 0; j < 3; j++){
            if(j == 0) c = G[i][j] - G[i + 1][j];
            else if(c != G[i][j] - G[i + 1][j]) ok = false;
        }
    }
    for(int j = 0; j < 2; j++){
        int c;
        for(int i = 0; i < 3; i++){
            if(i == 0) c = G[i][j] - G[i][j + 1];
            else if(c != G[i][j] - G[i][j + 1]) ok = false;
        }
    }
    if(ok) puts("Yes");
    else puts("No");
}