#include <bits/stdc++.h>
using namespace std;
using ll = long long;
int main()
{
    int n;
    cin >> n;
    multiset<ll> s;
    for(int i = 0; i < n; i++)
    {
        ll a;
        cin >> a;
        s.insert(a);
    }
    ll ans = 0;
    while(!s.empty())
    {
        ll cand = *s.rbegin();
        s.erase(s.find(cand));
        ll x = 1;
        while(x <= cand)
        {
            x *= 2;
        }
        auto itr = s.find(x-cand);
        if(itr == s.end())
        {
            continue;
        }
        else
        {
            ans++;
            s.erase(itr);
        }
    }
    cout << ans << endl;
}

