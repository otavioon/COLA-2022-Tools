#include <bits/stdc++.h>

using namespace std;

bool cmp(pair<int, int> &a, pair<int, int> &b) {
    if (a.first != b.first) {
        return a.first < b.first;
    } else {
        return a.second < b.second;
    }
}

int main() {
    int n, q;
    cin >> n >> q;
    vector<pair<int, int>> a(n - 1);
    for (int i = 0; i < n - 1; i++) {
        cin >> a[i].first >> a[i].second;
    }
    sort(a.begin(), a.end(), cmp);

    vector<int> res(n + 1, 0);
    for (int i = 0; i < q; i++) {
        int p, x;
        cin >> p >> x;
        res[p] += x;
    }

    for (int i = 0; i < n - 1; i++) {
        res[a[i].second] += res[a[i].first];
    }

    for (int i = 1; i <= n; i++) {
        cout << res[i] << ' ';
    }
    cout << endl;
    return 0;
}