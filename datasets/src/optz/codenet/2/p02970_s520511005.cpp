#pragma GCC optimize ("Ofast")
#include <bits/stdc++.h>
#include <math.h>
#define pb push_back
using namespace std;
using ll = long long;
const char E = '\n';
const int N = 105;
const ll mod = 1e9+7;
const int lim = 1e5;

mt19937_64 mt_rnd_64(chrono::steady_clock::now().time_since_epoch().count());
ll rnd(ll l, ll r) {
    return (mt_rnd_64() % (r-l+1)) + l;
}

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int n, d;
	cin >> n >> d;
	cout << n/(2*d+1) + bool (n%(2*d+1));
    return 0;
}
