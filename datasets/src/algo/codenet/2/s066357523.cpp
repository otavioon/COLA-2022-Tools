//pantyhose(black) + glasses = infinity

#include <bits/stdc++.h>
using namespace std;

#define debug(x) cerr << #x << " = " << x << '\n';
#define BP() cerr << "OK!\n";
#define PR(A, n) {cerr << #A << " = "; for (int _=1; _<=n; ++_) cerr << A[_] << ' '; cerr << '\n';}
#define PR0(A, n) {cerr << #A << " = "; for (int _=0; _<n; ++_) cerr << A[_] << ' '; cerr << '\n';}
#define FILE_NAME "data"

const int INF = 2e9;

int n;
multiset<int, greater<int> > a;

void read_input() {
    cin >> n;
    for (int i=1; i<=n; ++i) {
        int x;
        cin >> x;
        a.insert(x);
    }
}

void solve() {
    int res = 0;
    while (a.size()) {
        int x = *a.begin();
        a.erase(a.begin());
        for (int i=1; i<=INF; i<<=1) {
            if (a.count(i-x)) {
                ++res;
                a.erase(a.find(i-x));
                break;
            }
        }
    }
    cout << res;
}

int main() {
	#ifdef GLASSES_GIRL
		freopen(FILE_NAME".inp", "r", stdin);
		freopen(FILE_NAME".out", "w", stdout);
	#endif
	ios::sync_with_stdio(0); cin.tie(0);
	read_input();
    solve();
}

