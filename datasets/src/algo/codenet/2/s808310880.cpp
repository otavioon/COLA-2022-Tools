#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
using namespace std;
using namespace __gnu_pbds;

#define all(x) begin(x), end(x)
#define x first
#define y second
typedef long long ll;
typedef long double ld;

template<typename T>
using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

template<typename T>
using normal_queue = priority_queue<T, vector<T>, greater<T>>;

const int MAX_N = 2e5 + 10;

pair<int, bool> a[MAX_N];

signed main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n;
	cin >> n;
	for (int i = 0; i < n; ++i)
		cin >> a[i].x, a[i].y = 1;
	sort(a, a + n);
	int ans = 0;
	for (int i = n; i--; ) {
		if (!a[i].y)
			continue;
		for (int j = 31; j--; ) {
			int h = (1 << j) - a[i].x;
			int k = lower_bound(a, a + i, pair<int, bool>{h, 1}) - a;
			if (k == i || a[k] != pair<int, bool>{h, 1})
				continue;
			a[k].y = 0;
			++ans;
			// cout << i << " " << k << endl;
			break;
		}
	}
	cout << ans << "\n";
	return 0;
}