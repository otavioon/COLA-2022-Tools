#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    int n; cin >> n;
    vector<int> a(n);
    for(int i=0; i<n; i++) cin >> a[i];
    sort(a.begin(),a.end());
    ll ans = 0;
    for(ll mid = n - 1; mid >= 0; mid--) {
        for(ll low = mid - 1; low >= 0; low--) {
            auto itr = lower_bound(a.begin(), a.end(), a[mid] + a[low]);
            ll ng = distance(itr, a.end());
            ans += (n - 1 - mid) - ng;
        }
    }
    cout << ans << endl;
}