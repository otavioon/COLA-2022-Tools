#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
typedef long long int ll;
int n;
multiset<ll> s;
ll dp[40];
ll cnt = 0;
int main()
{
    cin >> n;
    rep(i, n)
    {
        ll x;
        cin >> x;
        s.insert(x);
    }
    dp[0] = 1;
    rep(i, 32)
    {
        dp[i + 1] = dp[i] * 2;
    }
    set<ll>::iterator mx, p;
    while (s.size() >= 2)
    {
        mx = --s.end();
        if (mx == s.end())
        {
            continue;
        }
        ll val = *upper_bound(dp, dp + 32, *mx);
        p = s.find(val - *mx);
        if (p != s.end())
        {
            cnt++;
            s.erase(mx);
            s.erase(p);
        }
        else
        {
            s.erase(mx);
        }
    }
    cout << cnt << endl;
}