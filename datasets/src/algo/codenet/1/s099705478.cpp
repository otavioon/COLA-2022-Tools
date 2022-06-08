#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

#define rep(i, n) for (int i = 0; i < (n); i++)
#define rep2(i, a, b) for (int i = (a); i < (b); ++i)
#define all(a) (a).begin(), (a).end()

int main()
{
    int a, b;
    rep(i, 3)
    {
        int x, y, z;
        cin >> x >> y >> z;

        if (!i)
        {
            a = abs(y - x);
            b = abs(z - y);
        }
        if (a != abs(y - x) || b != abs(z - y))
        {
            cout << "No" << '\n';
        }
    }

    cout << "Yes" << '\n';
    return 0;
}
