#include <bits/stdc++.h>
 
using namespace std;

#ifdef ARTEM
	#define deb(x) x
#else
	#define deb(x)
	const int inf = 1000500;
#endif

void solve();

int main() {
	solve();
}

/* ================ actual code starts here ================ */

int ans = inf;
set<int> can_use;

void rec(int a, int b) {
	if(a >= b) {
		ans = min(ans, a);
		return;
	}

	for(int i : can_use) {
		if(!a && !i)
			continue;

		rec(a * 10 + i, b);
	}
}

void solve() {
	int n, k;
	cin >> n >> k;
	for(int i = 0; i < 10; i++)
		can_use.insert(i);

	for(int i = 0, x; i < k; i++) {
		cin >> x;
		can_use.erase(x);
	}

	rec(0, n);
	cout << ans << endl;
}