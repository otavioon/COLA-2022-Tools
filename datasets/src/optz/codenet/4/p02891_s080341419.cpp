#include<bits/stdc++.h>

#define ff first
#define ss second
using namespace std;
#define maxn 2000006
#define pb push_back
#define ll long long
#define lll __int128
#define vll vector<ll>
#define mll map<ll,ll>
#define MOD 1000000007
#define pll pair<ll,ll>
#define ull unsigned long long
#define f(i,x,n) for(int i=x;i<=n;i++)
#define fr(i,x,n) for(int i=x;i>=n;i--)
inline void fastio() {ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);}

int dx[] = { -1, 0, 1, 0, -1, -1, 1, 1};
int dy[] = {0, 1, 0, -1, -1, 1, 1, -1};



int main() {
	fastio();

	string s; cin >> s;
	ll n = s.length();
	ll k; cin >> k;
	s = s + s[0];
	ll ans = 0;
	f(i, 0, n) {
		ll j = i;
		while (s[j + 1] == s[j] and j < n) j++;
		ans += ((j - i + 1) / 2);
		i = j;
	}

	cout << ans*k - (s[n - 1] == s[n] and s[n - 2] != s[n - 1]);

	return 0;
}