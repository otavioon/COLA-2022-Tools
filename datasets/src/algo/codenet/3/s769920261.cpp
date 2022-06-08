#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int n, a[10001], b[10001], c[10001];

int lower_bound(int key) {
    int l = -1, r = n;
    while (r - l > 1) {
        int mid = (l + r) / 2;
        if (a[mid] >= key) {
            r = mid;
        } else {
            l = mid;
        }
    }
    return r;
}

int upper_bound(int key) {
    int l = -1, r = n;
    while (r - l > 1) {
        int mid = (l + r) / 2;
        if (c[mid] > key) {
            r = mid;
        } else {
            l = mid;
        }
    }
    return r;
}

int main() {
    cin >> n;
    for (int i = 0; i < n; i++) cin >> a[i];
    for (int i = 0; i < n; i++) cin >> b[i];
    for (int i = 0; i < n; i++) cin >> c[i];
    sort(a, a + n);
    sort(c, c + n);
    int ans = 0;
    for (int i = 0; i < n; i++) {
        ans += lower_bound(b[i]) * (n - upper_bound(b[i]));
    }
    cout << ans << endl;
}
