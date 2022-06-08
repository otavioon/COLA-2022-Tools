#include "bits/stdc++.h"
using namespace std;

#define fi first
#define se second
#define pb push_back
#define int long long
#define all(x) (x).begin(), (x).end()

using LL = long long;
using LD = long double;
using pii = pair <int, int>;
using vii = vector <pii>;

const int INF = 1e18;
const int MOD = 1e9 + 7;
const int N = 2e5 + 5;

int a[N];
multiset <int> S;

int32_t main() {
    ios::sync_with_stdio(false); cin.tie(nullptr);

    int n;
    cin>>n;

    for(int i = 0; i < n; i++) {
        cin>>a[i];
        S.insert(a[i]);
    }

    int ans = 0;
    while(!S.empty()) {
        auto it = prev(S.end());
        int x = *it;
        S.erase(it);
        for(int i = 0; i <= 32; i++) {
            int y = (1LL<<i) - x;
            if(S.find(y) != S.end()) {
                S.erase(S.find(y));
                ans++;
                break;
            }
        }
    }

    cout<<ans<<"\n";
    return 0;
}