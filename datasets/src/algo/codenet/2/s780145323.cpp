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

    int ans = 0;
    while(!s.empty())
    {
        ll cand = *(s.rbegin());
        ll x = 1;
        while(x < cand)
        {
            x *= 2;
        }
        s.erase(s.find(cand));
        auto itr = s.lower_bound(x-cand);
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
