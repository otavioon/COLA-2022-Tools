#include<bits/stdc++.h>
using namespace std;
#define rep(i,n) for (int i = 0; i < (n); ++i)
#define ALL(x) (x).begin(), (x).end()
typedef long long ll;
typedef pair<int, int> pii;
const int INF = 1e9;
const int MOD = 1000000007;
const double PI = acos(-1);
int dx[4] = {0,1,0,-1};
int dy[4] = {1,0,-1,0};

void solve() {
	int n, k;
	cin >> n >> k;
	set<int> s;
	rep(i,k) {
		int a;
		cin >> a;
		s.insert(a);
	}
	int ans = 0;
	for (int i = n; i <= pow(10, 6); i++) {
		int t = i;
		bool b = true;
		while (t != 0) {
			if (!s.count(t % 10)) t /= 10;
			else {
				b = false;
				break;
			}
		}
		if (b) {
			ans = i;
			break;
		}
	}
	cout << ans << endl;
}

int main() {
	solve();
	return 0;
}