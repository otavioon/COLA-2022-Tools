#include<bits/stdc++.h>
using namespace std;

#define F first
#define S second
#define PB push_back
#define all(x) x.begin(), x.end()

typedef long long ll; 
typedef long double ld;

const int N = 1000 * 1000 + 10, mod = 998244353; 

ll get(ll x)
{
	ll y = 1;
	while(y<=x) y *= 2;
	return y;
}

int32_t main()
{
	ios::sync_with_stdio(0); cin.tie(0);
	multiset<ll> s;
	int n, x;
	cin>> n;
	while(n--) cin>> x, s.insert(x);
	int ans = 0;
	while(s.size() > 1)
	{
		x = *s.rbegin();
		s.erase(s.find(x));
		ll y = get(x) - x;
		if(s.find(y)!=s.end())
		{
			ans ++;
			s.erase(s.find(y));
		}
	}
	cout<< ans << endl;
}
