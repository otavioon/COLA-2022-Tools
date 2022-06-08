#include <iostream>
#include <algorithm>

using namespace std;

typedef long long ll;
ll n, a[200005], now, b[200005], cnt[200005], tow[200005], ans;
bool vis[200005];

ll ef(ll l, ll r, ll v)
{
	if (l == r)
	{
		if (a[l] == v) return l;
		else return 0;
	}
	ll mid = (l + r) / 2;
	if (a[mid] >= v) return ef(l, mid, v);
	else return ef(mid + 1, r, v);
}

int main()
{
	cin >> n;
	for (ll i = 1; i <= n; i++)
	{
		cin >> a[i];
	} 
	sort(a + 1, a + n + 1);
	for (ll i = 1; i <= n; i++)
	{
		if (a[i] != a[i - 1]) b[i] = b[i - 1] + 1;
		else b[i] = b[i - 1];
		cnt[b[i]]++;
		tow[b[i]] = a[i];
		//cout << b[i] << " ";
	}
	now = 1;
	while (now <= a[n]) now *= 2;
	for (ll i = b[n]; i >= 1; i--)
	{
		if (now / 2 > tow[i]) now /= 2;
		ll x = ef(1, n, now - tow[i]);
		x = b[x];
		if (x == 0) continue;
		ll res = min(cnt[i], cnt[x]);
		if (x != i)
		{
			cnt[i] -= res;
			cnt[x] -= res;
		}
		else
		{
			res /= 2;
			cnt[i] -= res;
		}
		//cout << x << " " << tow[x] << " " << tow[i] << " " << res << endl;
		ans += res;
	}
	cout << ans << endl;
	return 0;
}
