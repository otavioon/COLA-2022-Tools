#include<algorithm>
#include<string>
#include<stdio.h>
#include<iostream>
#include<vector>
#include<queue>
#include<stack>
#include<set>
#include<utility>
#include<functional>
#include<cassert>
#include<cmath>
#include<math.h>
using namespace std;
typedef long long int ll;
typedef pair<int, int> P;
typedef vector<ll> vint;
typedef vector<vint> vvint;
#define PI 3.1415926535;
#define MOD 1000000007;


vint a, b, c;
ll up(ll x) {
	ll l = 0, r = a.size()-1;
	while (r-l>1) {
		ll m = (l + r) / 2;
		if (x>a[m]) {
			l = m;
		}
		else {
			r = m;
		}
	}
	return l;
}

ll down(ll x) {
	ll l = 0, r = c.size()-1;
	while (r - l > 1) {
		ll m = (l + r) / 2;
		if (x>=c[m]) {
			l = m;
		}
		else {
			r = m;
		}
	}
	return l;
}

int main(void) {
	ll n;
	cin >> n;
	ll cnt=0;
	a.resize(n+2);
	b.resize(n+2);
	c.resize(n+2);
	a[0] = b[0] = c[0] = -1;
	a[n+1] = b[n + 1] = c[n + 1] = 2000000000;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}
	for (int i = 1; i <= n; i++) {
		cin >> b[i];
	}
	for (int i = 1; i <= n; i++) {
		cin >> c[i];
	}

	sort(a.begin(), a.end());
	sort(b.begin(), b.end());
	sort(c.begin(), c.end());

	for (int i = 1; i <= n; i++) {
		cnt+=up(b[i])*(n-down(b[i]));
	}
	cout << cnt << endl;
	return 0;
}