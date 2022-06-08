#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;
typedef long double ld;

typedef set<int>::iterator sit;
typedef map<int, int>::iterator mit;
typedef vector<int>::iterator vit;

const int INF = 1e9 + 7;
const int MOD = 1e9 + 7;
const int MAXN = 1e6 + 3;

#define _ % MOD
#define __ %= MOD

#define each(it, s) for (auto it = s.begin(); it != s.end(); ++it)
#define sortA(v) sort(v.begin(), v.end())
#define sortD(v) sort(v.begin(), v.end(), greater<auto>())
#define fill(a) memset(a, 0, sizeof(a))

#define swap(a, b) \
	{              \
		a = a + b; \
		b = a - b; \
		a = a - b; \
	}
#define rep(i, n) for (ll i = 0; i < (n); ++i)
#define repA(i, a, n) for (ll i = a; i <= (n); ++i)
#define repD(i, a, n) for (ll i = a; i >= (n); --i)
#define watch(x) cout << (#x) << " is " << (x) << endl

#define fi first
#define se second
#define mp make_pair
#define pb push_back

#define fbo find_by_order
#define ook order_of_key

#define pv(a)                                 \
	{                                         \
		rep(i, a.size()) cout << a[i] << " "; \
		cout << endl;                         \
	}
#define mark(v) cout << "Here--" << v << endl;

const double EPS = (1e-7);
int dcmp(double x, double y) { return fabs(x - y) <= EPS ? 0 : x < y ? -1 : 1; }

ll gcd(ll a, ll b)
{
	if (b == 0)
		return a;
	else
		return gcd(b, a % b);
}
ll power(ll x, ll y)
{
	ll res = 1;
	while (y > 0)
	{
		if (y & 1)
			res = res * x;
		y = y >> 1;
		x = x * x;
	}
	return res;
} // modular exponent

int main()
{
	ios_base::sync_with_stdio(false); // don't use printf and scanf
	cin.tie(NULL);					  // cout<<fixed<<setprecision
	string n;
	ll k;
	cin >> n >> k;
	set<int> nt;
	rep(i, k)
	{
		ll x;
		cin >> x;
		nt.insert(x);
	}

	ll num = stoll(n);

	ll ans;
	while (1)
	{
		n = to_string(num);
		bool flag = true;

		rep(i, n.size())
		{
			if (nt.find(n[i] - '0') != nt.end())
			{
				flag = false;
				break;
			}
		}
		if (flag == true)
		{
			ans = num;
			break;
		}
		num++;
	}
	cout << ans << endl;
	return 0;
}