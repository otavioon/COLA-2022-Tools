#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn = 1000 + 5;
int arr[maxn];
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    for (int i = 0; i < n; ++i)
        cin >> arr[i];
    ll res = 0;
    sort(arr, arr + n);
    for (int i = 0; i < n; ++i)
        for (int j = i + 1; j + 1 < n; ++j) {
            auto ptr = lower_bound(arr + j + 1, arr + n, arr[i] + arr[j]);
            res += ptr - (arr + j + 1);
        }
    cout << res << '\n';
    return 0;
}