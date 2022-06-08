#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
ll n;
ll ans = 0;
multiset<ll> a;
ll num[40];
int main()
{
    for (int i = 0; i < 33; i++)
    {
        num[i] = 1LL << i;
    }
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        ll x;
        cin >> x;
        a.insert(x);
    }
    multiset<ll>::iterator p;
    for (p = a.end(); p != a.begin(); p--)
    {
        ll x = *upper_bound(num, num + 32, *p);
        ll y = x - *p;
        if (*a.find(y) == y)
        {
            ans++;
            a.erase(a.find(y));
            p--;
        }
    }
    cout << ans << endl;
    return 0;
}