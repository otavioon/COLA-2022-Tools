#include <iostream>
#include <algorithm>

using namespace std;

const int kMaxN = 1000000;

int main () {
    int n;
    int a[kMaxN], b[kMaxN], c[kMaxN];

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

    sort(a, a + n);
    sort(b, b + n);
    sort(c, c + n);

    int j = 0;
    int k = 0;
    int ans = 0;
    bool flag = true;

    for (int i = 0; i < n; i++) {
        while (a[j] < b[i] && j < n) {
            j++;
            if (j == n - 1) {
                break;
            }
        }

        while (b[i] >= c[k] && k < n) {
            if (k == n - 1) {
                flag = false;
                break;
            }
            ++k;
        }

        if (!flag) {
            break;
        }

        ans += j * (n - k);
    }

    cout << ans << endl;

}
