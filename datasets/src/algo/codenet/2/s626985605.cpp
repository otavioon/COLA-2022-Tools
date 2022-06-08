#include <iostream>
#include <cstdio>
#include <set>

using namespace std;

typedef long long ll;

ll n;
ll ans;
multiset<ll> se;

int main()
{
    scanf("%lld", &n);
    for(ll i = 0; i < n; i++)
    {
        ll t;
        scanf("%lld", &t);
        se.insert(t);
    }
    while(!se.empty()) {
        ll x = *se.rbegin();
        ll y;
        auto t = se.find(x);
        se.erase(t);
        for(ll i = 32; i >= 0; i--)
        {
            if((1 << i) > x) y = (1 << i) - x;
        }
        auto t2 = se.find(y);
        if(t2 != se.end()) se.erase(t2), ans++;
    }
    cout<<ans<<endl;
    return 0;
}
