#define _USE_MATH_DEFINES
#include "bits/stdc++.h"
using namespace std;
#define FOR(i,j,k) for(int (i)=(j);(i)<(int)(k);++(i))
#define rep(i,j) FOR(i,0,j)
#define each(x,y) for(auto &(x):(y))
#define mp make_pair
#define MT make_tuple
#define all(x) (x).begin(),(x).end()
#define debug(x) cout<<#x<<": "<<(x)<<endl
#define smax(x,y) (x)=max((x),(y))
#define smin(x,y) (x)=min((x),(y))
#define MEM(x,y) memset((x),(y),sizeof (x))
#define sz(x) (int)(x).size()
#define RT return
using ll = long long;
using pii = pair<int, int>;
using vi = vector<int>;
using vll = vector<ll>;

void solve() {
    int N;
    cin >> N;
    multiset<int> S;
    rep(i, N) {
        int a;
        cin >> a;
        S.insert(a);
    }

    int ans = 0;
    while (!S.empty()) {
        auto it = S.end();
        --it;
        int x = *it;
        S.erase(it);
        for (int i = 30; i >= 0; --i) {
            int sum = 1 << i;
            it = S.find(sum - x);
            if (it!=S.end()) {
                ans++;
                S.erase(it);
                break;
            }
        }
    }
    cout << ans << endl;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout << fixed << setprecision(15);
	solve();
	return 0;
}