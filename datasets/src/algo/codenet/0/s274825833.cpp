#include <bits/stdc++.h>
 
using namespace std;
typedef long long ll;

int N;
string s;
ll K;

int main()
{
    ios_base::sync_with_stdio(0);
    cin >> s >> K;
    N = s.length();

    char c = s[0];
    bool all = true;
    for (int i = 0; i < N; i++)
        if (s[i] != c)
            all = false;

    if (all)
    {
        ll ct = N * (ll) K;
        cout << ct / 2 << "\n";
        return 0;
    }

    int nlo = 0, nhi = N - 1;
    while (s[nlo] == c)
        nlo++;
    while (s[nhi] == c)
        nhi--;
    nhi = N - 1 - nhi;

    ll ans = (nlo / 2) + (nhi / 2);
    int cc = 1;
    for (int i = nlo + 1; i < N - nhi; i++)
    {
        if (s[i] == s[i-1])
        {
            cc++;
        }
        else
        {
            ans += K * (cc / 2);
            cc = 1;
        }
    }
    ans += K * (cc / 2);
    ans += (K - 1) * ((nlo + nhi) / 2);
    cout << ans << "\n";
}