#include <iostream>
#include <string>
#include <algorithm>
#include <functional>
#include <vector>
#include <utility>
#include <cstring>
#include <iomanip>
#include <numeric>
#include <cmath>
#include <queue>
#include <map>
#include <set>
using namespace std;
typedef long long ll;
typedef pair<ll, bool> P;
typedef pair<ll, P> PP;
const int INF = 1<<30; 
const int MOD = 1e9 + 7;
const int dy[] = {1, 0, -1, 0};
const int dx[] = {0, 1, 0, -1};
int main()
{
    cin.tie(0);
    ios::sync_with_stdio(false);
    ll n;
    cin >> n;
    multiset<ll> mst;
    for(int i = 0; i < n; i++)
    {
        int x; cin >> x;
        mst.insert(x);
    }
    ll ans = 0;
    while(!mst.empty())
    {
        //auto itr = max_element(mst.begin(), mst.end());
        auto itr = mst.end();
        itr--;
        ll t = 1;
        for(int i = 0; i < 30; i++)
        {
            ll val = *itr - t;
            if(val < 0) break;
            auto it = mst.find(val);
            if(it != mst.end()) 
            {
                mst.erase(it);
                ans++;
                break;
            }
            t *= 2;
        }
        mst.erase(itr);
    }
    cout << ans << endl;
    return 0;
}