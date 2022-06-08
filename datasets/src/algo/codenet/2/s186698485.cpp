#include <bits/stdc++.h>
using namespace std;
#define IOS ios::sync_with_stdio(false); cin.tie(0);
#define FOR(i,s,n) for(int i = s; i < (n); i++)
#define REP(i,n) FOR(i,0,n)
#define ALL(n) (n).begin(), (n).end()
#define RALL(n) (n).rbegin(), (n).rend()
#define ATYN(n) cout << ( (n) ? "Yes":"No") << '\n';
#define CFYN(n) cout << ( (n) ? "YES":"NO") << '\n';
#define OUT(n) cout << (n) << '\n';
using ll = long long;
using ull = unsigned long long;
using pii = pair<int,int>;
using pll = pair<ll,ll>;

int main(void)
{
    IOS
    int n; cin >> n;
    multiset<int> mst;

    REP(i,n) {
        int a; cin >> a;
        mst.insert(a);
    }

    int ans = 0;
    while(!mst.empty()) {
        auto back = mst.end();
        back--;
        int x = *back;
        mst.erase(back);
        double l2 = log2(x);
        if (l2 == floor(l2)) {
            auto it = mst.find(x);
            if (it != mst.end()) {
                ans++;
                mst.erase(it);
            }
        } else {
            int x2 = pow(2,ceil(l2));
            auto it = mst.find(x2-x);
            if (it != mst.end()) {
                ans++;
                mst.erase(it);
            }
        }
    }

    cout << ans << '\n';

    return 0;
}