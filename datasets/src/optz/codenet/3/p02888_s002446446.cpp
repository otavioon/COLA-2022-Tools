#include "bits/stdc++.h"

using namespace std;
using ll = long long int;

int main()
{
    int n;
    cin >> n;
    vector<int> L(n);
    for (int i = 0; i < n; i++)
    {
        cin >> L[i];
    }

    sort(L.begin(), L.end());

    int ans = 0;
    for (int a = 0; a < n; a++)
    {
        for (int b = a + 1; b < n; b++)
        {
            auto lower = lower_bound(L.begin() + b + 1, L.end(), L[b]);
            auto upper = lower_bound(L.begin() + b + 1, L.end(), L[a] + L[b]);

            /*for (auto it = lower; it < upper; it++)
                cout << L[a] << " " << L[b] << " " << *it << endl;*/

            int count = distance(lower, upper);
            ans += count;
        }
    }

    cout << ans << endl;
}