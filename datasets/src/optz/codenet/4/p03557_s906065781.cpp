#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace std;
#define ll long long
#define ld long double
#define f first
#define s second
using namespace __gnu_pbds;
template<class T> using ordered_set = tree<T,null_type,less<T>,rb_tree_tag,tree_order_statistics_node_update>;

ordered_set< pair<ll,ll> > up , dw;
const int N = 2e5+5;
ll n , m , a[N] , b[N] , c[N];

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    cin >> n;
    for(int i=1; i<=n; i++)
    {
        cin >> a[i];
        up.insert({a[i] , i});
    }
    for(int i=1; i<=n; i++)
        cin >> b[i];
    for(int i=1; i<=n; i++)
    {
        cin >> c[i];
        dw.insert({c[i] , i});
    }

    ll ans=0 , u , d;
    for(int i=1; i<=n; i++)
    {
        u = up.order_of_key({b[i] , -1e9});
        d = dw.order_of_key({b[i] , 1e9});
        d = dw.size() - d;
        ans += (u*d);
    }

    cout << ans << '\n';

    return 0;
}