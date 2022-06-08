#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using namespace std;
using ll = long long;
using P = pair<int, int>;

void solve()
{
    int sum = 0;
    rep(i, 9)
    {
        int x;
        cin >> x;
        sum += x;
    }
    rep(a, 101)
    {
        rep(b, 101)
        {
            if (sum % 3 == 0)
            {
                cout << "Yes" << endl;
                return;
            }
        }
    }
    cout << "No" << endl;
}

int main()
{
    solve();
    return 0;
}