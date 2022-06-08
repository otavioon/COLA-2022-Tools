#include"bits/stdc++.h"
using namespace std;
#define REP(k,m,n) for(int (k)=(m);(k)<(n);(k)++)
#define rep(i,n) REP((i),0,(n))
using ll = long long;

ll find_opponent(ll now) {
    ll base = 1;
    while (base <= now)base *= 2;
    base -= now;
    return base;
}

int main()
{
    multiset<ll> ms;
    int N;
    cin >> N;
    rep(i, N) {
        ll a;
        cin >> a;
        ms.insert(a);
    }

    ll res = 0;
    while (!ms.empty()) {
        auto itr = ms.end();
        itr--;
        ll now = *itr;
        ms.erase(itr);

        itr = ms.find(find_opponent(now));
        if (itr == ms.end())continue;
        res++;
        ms.erase(itr);
    }
    cout << res << endl;
    return 0;
}
