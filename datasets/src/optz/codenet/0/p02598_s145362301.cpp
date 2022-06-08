#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll N = 200010;
const double eps = 1e-6;
template <typename T> void inline read(T &x) {
	T f = 1;
	char ch = getchar();
	for (; '0' > ch || ch > '9'; ch = getchar()) if (ch == '-') f = -1;
	for (x = 0; '0' <= ch && ch <= '9'; ch = getchar()) x = x * 10 + ch - '0';
	x *= f;
}
template <typename T> void write(T x) {
	if (x > 9) write(x / 10);
	putchar(x % 10 + '0');
}
template <typename T> void print(T x) {
	if (x < 0) putchar('-'), x = -x;
	write(x);
	putchar('\n');
}
ll n, m;
double a[N], ans;
bool judge(double mid) {
	ll cnt = 0;
	for (ll i = 1; i <= n; i++) {
		cnt += (ll)ceil(a[i] / mid)-1;
	}
	return cnt <= m;
}
int main() {
	read(n); read(m);
	for (ll i = 1; i <= n; i++) scanf("%lf", &a[i]);
	if (m == 0) {
		double mx = 0;
		for (ll i = 1; i <= n; i++) mx = max(mx, a[i]);
		cout << mx << endl;
		return 0;
	}
	double l = 0, r = 10000000000;
	while (r - l > eps) {
		double mid = (l + r) / 2.0;
//		printf("%.6lf %.6lf\n%.6lf\n", l, r, mid);
		if (judge(mid)) {
			ans = mid;
			r = mid;
		} else {
			l = mid;
		}
	}
//	printf("%.10lf", ans);
	ll tmp = ans;
	if (tmp && judge(tmp)) {
		cout << tmp;
	} else {
		printf("%lld\n", (ll)ceil(ans));
	}
	return 0;
}