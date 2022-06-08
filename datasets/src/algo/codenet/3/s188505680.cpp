#include <bits/stdc++.h>
using namespace std;

const int maxn = 1e5 + 5;
int a[maxn], b[maxn], c[maxn];

int main() {
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) cin >> a[i];
    for (int i = 0; i < n; i++) cin >> b[i];
    for (int i = 0; i < n; i++) cin >> c[i];
    sort(a, a + n);
    sort(b, b + n);
    sort(c, c + n);
    long long res = 0;
    int h = 0, t = 0;
    for (int i = 0; i < n; i++) {
        while (a[h] < b[i] && h < n) h++;
        while (b[i] >= c[t] && t < n) t++;
        res += h * (n - t);
    }
    cout << res << endl;
}
