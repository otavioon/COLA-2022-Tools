#include <bits/stdc++.h>

using namespace std;

typedef long long LL;
typedef pair<int, int> PII;

int a[100001],b[100001],c[100001];


int main() {
    ios_base::sync_with_stdio(false);
    int n;
    cin >> n;
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    for (int i = 0; i < n; ++i) {
        cin >> b[i];
    }
    for (int i = 0; i < n; ++i) {
        cin >> c[i];
    }
    sort (a, a + n);
    sort (b, b + n);
    sort (c, c + n);
    LL ans = 0;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            for (int k = 0; k < n; ++k) {
                if (b[j] > a[i] && c[k] > b[j]) {
                    ans+=n - k;
                    break;
                }
            }
        }
    }
    cout << ans << endl;
    return 0;
}
