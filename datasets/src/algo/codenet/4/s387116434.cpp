#include<bits/stdc++.h>
#define int long long

using namespace std;

signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    stack<int> ans;
    set<int> d;
    int n, k, t;
    cin >> n >> k;
    for (int i = 0; i < k; i++)
        cin >> t, d.insert(t);

    bool check = true;
    for (; check; n++)
    {
        check = false;
        int tmp = n;
        while (!check && tmp)
        {
            if (d.count(tmp % 10))
                check = true;
            tmp /= 10;
        }
    }
    cout << n << '\n';

    return 0;
}
