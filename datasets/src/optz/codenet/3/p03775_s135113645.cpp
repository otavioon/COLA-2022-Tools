#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <numeric>
#include <map>
#include <cmath>
#include <math.h>
#include <cstdio>
#include <iomanip>
typedef  long long ll;
using namespace std;


bool is_sosu(ll n){
	if ( n <= 1 ) return false;
	for (ll i = 2; i * i <= n; i++)
	{
		if (n % i == 0) return false;
	}
	return true;
}

vector<ll> yakusu(ll n){
	vector<ll> res;
	for (int i = 1; i * i <= n; i++)
	{
		if (n % i == 0)
		{res.push_back(i);
		if (i != n / i) res.push_back(n / i);
		}
	}
	sort(res.begin(), res.end());
	return res;
}

ll check_digi(ll n){
	ll digit = 0;
	while (n > 0)
	{
		digit++;
		n /= 10;
	}
	return digit;
}

int main(void) {
	ll n;
	cin >> n;
	int ans = 1000;
	for (ll a = 1; a * a <= n; a++)
	{
		if (n % a == 0)
		{
			ll b = n / a;
			int f = max(check_digi(a), check_digi(b));
			ans = min(ans, f);
		}
	}
	cout << ans << endl;

	return 0;
}