#include<bits/stdc++.h>
using namespace std;

typedef long long lint;
typedef pair<int, int> P;
#define REP(i, x, n) for(int i = x ; i < n ; i++)
#define rep(i, n) REP(i, 0, n)
#define repr(i, n) for(int i = n - 1 ; i >= 0 ; i--)
#define SORT(c) sort((c).begin(), (c).end())

const int IINF = 1e9 + 10;
const lint LLINF = (lint)1e18 + 10;
const lint MOD = (lint)1e9 + 7;
const int dx[] = {1, 0, -1, 0}, dy[] = {0, 1, 0, -1};
const int dx8[] = {1, 1, 0, -1, -1, -1, 0, 1}, dy8[] = {0, -1, -1, -1, 0, 1, 1, 1};

int main(){
    int n;
    cin >> n;
    vector<string> v(n);
    map<string, int> mpb;
    rep(i, n){
        cin >> v[i];
        ++mpb[v[i]];
    }
    int m;
    cin >> m;
    map<string, int> mpr;
    rep(i, m){
        string s;
        cin >> s;
        ++mpr[s];
    }
    int ans = 0;
    rep(i, n){
        int tmp = mpb[v[i]] - mpr[v[i]];
        ans = max(ans, tmp);
    }
    cout << ans << endl;
    return 0;
}