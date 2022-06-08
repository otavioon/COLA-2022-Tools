#include <bits/stdc++.h>
using namespace std;

const int maxn = 1e5 + 5;
int a[maxn], b[maxn], c[maxn];

int main() {
    int n;
    cin >> n;
    for (int i = 1; i <=n; i++) cin >> a[i];
    for (int i = 1; i <=n; i++) cin >> b[i];
    for (int i = 1; i <=n; i++) cin >> c[i];
    sort(a+1, a + n+1);
    sort(b+1, b + n+1);
    sort(c+1, c + n+1);
    long long res = 0;
    int h = 1, t = 1;
    for (int i = 1; i <=n; i++) {
        while (a[h] < b[i] && h <=n) h++;
        while (b[i] >= c[t] && t <=n) t++;
        long long tmp1 = n - t + 1;
        long long tmp2 = h-1;
        res += tmp1 * tmp2;
    }
    cout << res << endl;
}
