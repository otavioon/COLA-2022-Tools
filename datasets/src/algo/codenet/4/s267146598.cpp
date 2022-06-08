#include <bits/stdc++.h>
#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define trav(a, x) for(auto& a : x)
#define all(x) x.begin(), x.end()
#define endl "\n"
#define sz(x) (int)(x).size()
#define _USE_MATH_DEFINES
using namespace std;
typedef long long int lli;
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    vector<bool> d(10);
    int n, k;
    cin >> n >> k;
    rep(i, 0, k) {
        int now;
        cin >> now;
        d.at(now) = true;
    }
    for (int i = n;; i++) {
        int now = i;
        bool ans = true;
        while (now != 0) {
            int next = now % 10;
            if (d.at(next))
                ans = false;
            now /= 10;
        }
        if (ans) {
            cout << i << endl;
            return 0;
        }
    }
    return 0;
}