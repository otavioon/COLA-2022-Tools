#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <math.h>
#include <functional>
#include <iomanip>
#include <bitset>
#include <numeric>
#include <queue>
#include <map>
#include <cstdint>
using namespace std;
#define rep(i, n) for (ll i = 0; i < n; i++)
const long long mod = 1000000007;
typedef long long int ll;
typedef pair<ll, ll> P;
const vector<int> di = { -1, 0, 1, 0 };
const vector<int> dj = { 0, 1, 0, -1 };

ll F(ll a) {
	int digit = 0;
	while (a != 0) {
		a = a / 10;
		digit++;
	}
	return digit;
}

int main() {

	ll n;
	cin >> n;
	ll num = mod;
	for (ll i = 1; i < (n / 2); i++) {
		if (n % i == 0 && (n / i) > i) {
			num = min(num, F(n / i));
		}
		if (i > n / i) break;
	}
	cout << num << endl;
	

	return 0;
}