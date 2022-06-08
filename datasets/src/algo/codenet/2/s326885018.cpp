#include<bits/stdc++.h>

#define pb push_back
#define mp make_pair
#define X first
#define Y second
#define ll long long
#define pii pair<int, int>
#define is insert
#define er erase

using namespace std;

int solve();

#define TASK ""

int main()
{
    #ifdef DEBUG
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #else
        //freopen(TASK".in", "r", stdin);
        //freopen(TASK".out", "w", stdout);
    #endif // DEBUG
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    solve();
    return 0;
}

int n;

multiset<ll> s;

int ans = 0;

int solve()
{
    cin >> n;
    for (int i = 0; i < n; ++i)
    {
        ll x;
        cin >> x;
        s.is(x);
    }
    while (!s.empty())
    {
        ll v = *s.rbegin();
        s.er(s.find(v));
        for (ll i = 31; i >= 0; --i)
        {
            ll val = (1ll << i) - v;
            if (s.find(val) != s.end())
            {
                //cerr << v << ' ' << val << endl;
                ans++;
                s.er(s.find(val));
                break;
            }
        }
    }
    cout << ans << endl;
    return 0;
}
