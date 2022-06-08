#include <iostream>
#include <list>
#include <stack>
#include <set>
#include <iomanip>
#include <random>
#include <time.h>
#include <vector>
#include <queue>
#include <functional>
#include <map>
#include <string>
#include <cstdlib>
#include <typeinfo>
#include <math.h>
#include <algorithm>
using namespace std;
typedef long long int ll;
typedef pair<ll, ll> P;
int main() {
	cin.tie(0);
	ios::sync_with_stdio(false);
	ll n, a[100010], b[100010], c[100010], bc[100010] = {}, cnt = 0;
	cin >> n;
	for (int i = 0; i < n; i++)cin >> a[i];
	for (int i = 0; i < n; i++)cin >> b[i];
	for (int i = 0; i < n; i++)cin >> c[i];
	sort(a, a + n); sort(b, b + n); sort(c, c + n);
	for (int i = 0; i < n; i++) {
		while (a[cnt] < b[i]) {
			if (cnt == n - 1)break;
			cnt++;
		}
		bc[i] = cnt;
	}
	cnt = 0;
	ll ans = 0, yojo = 0;
	for (int i = 0; i < n; i++) {
		while (b[cnt] < c[i]) {
			if (cnt == n - 1)break;
			yojo += bc[cnt];
			cnt++;
		}
		ans += yojo;
	}
	cout << yojo << endl;
	return 0;
}

