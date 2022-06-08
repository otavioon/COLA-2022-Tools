#include "bits/stdc++.h"
#define rep(i,n) for(int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int, int>;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    int n;
    cin >> n;
    vector<int> l(n);
    rep(i,n) cin >> l[i];
    sort(l.begin(), l.end());
    int ans = 0;
    for(int a = 0; a < n; a++){
        for(int b = a+1; b < n; b++){
            for(int c = b+1; c < n; c++){
                if(l[a] + l[b] > l[c]) ans++;
            }
        }
    }
    cout << ans << endl;
    return 0;
}