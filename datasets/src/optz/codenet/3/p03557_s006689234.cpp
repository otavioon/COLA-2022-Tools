#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main()
{
    int n; cin >> n;
    vector<int> a(n), b(n), c(n);
    for (int i = 0; i < n; ++i) cin >> a[i];
    for (int i = 0; i < n; ++i) cin >> b[i];
    for (int i = 0; i < n; ++i) cin >> c[i];
    long ans = 0L;

    sort(a.begin(), a.end());
    sort(c.begin(), c.end());

    for (int i = 0; i < n; ++i) {
        auto lower = lower_bound(a.begin(), a.end(), b[i]);
        auto upper = upper_bound(c.begin(), c.end(), b[i]);

        int l = lower - a.begin();
        int u = c.end() - upper;
        ans += (long)l * u;
    }

    cout << ans << endl;

    return 0;
}