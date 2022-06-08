#include<iostream>
#include<queue>
#include<string>
#include<algorithm>
#include<vector>
#include<map>
#include<cmath>
#include<functional>
#include<set>
using namespace std;
#define int long long
#define REP(i,n) for(int i=0;i<n;i++)
typedef pair<int, int>P;

int a[114514], b[114514], c[114514];
signed main() {
	int n; cin >> n;
	REP(i, n)cin >> a[i];
	REP(i, n)cin >> b[i];
	REP(i, n)cin >> c[i];
	sort(a, a + n);
	sort(b, b + n);
	sort(c, c + n);
	int ans = 0;
	for (int i = 0; i < n; i++) {
		int lb = -1, ub = n;
		while (ub - lb > 1) {
			int mi = (ub + lb) / 2;
			if (a[mi] < b[i]) {
				lb = mi;
			}
			else ub = mi;
		}
		int ls = -1, us = n;
		while (us - ls > 1) {
			int mi = (us + ls) / 2;
			if (c[mi] > b[i]) {
				us = mi;
			}
			else ls = mi;
		}
		ans += ((lb+1)*(n - ls-1));
	//	cout << lb << ' ' << ub << ' ' << ls << ' ' << us << endl;
	}
	cout << ans << endl;
}