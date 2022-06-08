#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
using Pair = pair<int, int>;
using Vec = vector<int>;
using Graph = vector<Vec>;
#define INF 1000000007
#define MOD 1000000007
#define SEP " "

int		main(void)
{
	string s;
	ll k;
	cin >> s >> k;
	ll c = 0;
	ll len = s.size();
	for (auto it = s.begin() + 1; it != s.end(); it++)
	{
		if (*it == *(it - 1))
		{
			*it = 'D';
			c++;
		}
	}
	cerr << count(s.begin(), s.end(), s[0]) << endl;
	if (len > 2 && count(s.begin(), s.end(), s[0]) == len-1)
	{
		cout << len * k / 2 << endl;
		return (0);
	}
	ll ans = c * k;
	if (len == 1)
		ans = k / 2;
	if (len > 2 && s[0] == s[len - 1])
		ans += k-1;
	cout << ans << endl;
}
