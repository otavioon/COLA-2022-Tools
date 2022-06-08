#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n, q;
    cin >> n >> q;
    unordered_map<int, int> umap;
    vector<pair<int, int>> LIST(n - 1);

    for (int i = 0; i < n - 1; i++) {
        int a, b;
        cin >> a >> b;
        LIST[i] = make_pair(a, b);
    }

    for (int i = 0; i < q; i++) {
        int p, x;
        cin >> p >> x;
        umap[p] += x;
    }

    sort(LIST.begin(), LIST.end());

    for (int i = 0; i < n - 1; i++) {
        umap[LIST[i].second] += umap[LIST[i].first];
    }

    for (int i = 0; i < n; i++) {
        cout << umap[i + 1] << " ";
    }

    return 0;
}