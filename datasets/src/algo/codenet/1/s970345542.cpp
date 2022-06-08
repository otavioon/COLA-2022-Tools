#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

#define rep(i, n) for (int i = 0; i < (n); i++)
#define rep2(i, a, b) for (int i = (a); i < (b); ++i)
#define all(a) (a).begin(), (a).end()
#define all2(a, b) (a).begin(), (a).begin() + (b)
#define debug(vari) cerr << #vari << " = " << (vari) << endl;

int main()
{
    int n, m;

    rep(i, 3)
    {
        int a, b, c;
        cin >> a >> b >> c;

        if (!i)
        {
            n = abs(a - b);
            m = abs(b - c);
        }
        else
        {
            if ((n != abs(a - b)) || (m != abs(b - c)))
            {
                cout << "No" << endl;
                return 0;
            }
        }
    }
    cout << "Yes" << endl;
}
