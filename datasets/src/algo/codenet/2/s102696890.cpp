
#include <bits/stdc++.h>
using namespace std;

#define forn(i,n) for(int i=0;i<(int)(n);i++)
#define si(c) ((int)(c).size())
#define forsn(i,s,n) for(int i = (int)(s); i<((int)n); i++)
#define dforsn(i,s,n) for(int i = (int)(n)-1; i>=((int)s); i--)
#define all(c) (c).begin(), (c).end()
#define D(a) cerr << #a << "=" << (a) << endl;
#define pb push_back
#define eb emplace_back
#define mp make_pair

typedef long long int ll;
typedef vector<int> vi;
typedef pair<int,int> pii;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

    multiset<int> c;
    int n, ans = 0; cin >> n;
    while (n--) {
        int x; cin >> x;
        c.insert(x);
    }
    while (!c.empty()) {
        auto x = *c.begin();
        c.erase(c.begin());
        for (int l = 30; l >= 0; l--) {
            auto y = (1<<l)-x;
            if (c.count(y)) {
                auto it = c.find(y);
                c.erase(it);
                ans++;
            }
        }
    }
    cout << ans << endl;

    return 0;
}
