#include <bits/stdc++.h>


using namespace std;
typedef long long ll;
#define REP(i,n) for(int i=0; i<int(n); i++)
#define FOR(i,m,n) for(int i=int(m); i<int(n); i++)
#define ALL(obj) (obj).begin(),(obj).end()
#define VI vector<int>
#define VLL vector<long long>
#define VVI vector<vector<int>>
#define VVLL vector<vector<long long>>
#define VC vector<char>
#define VS vector<string>
#define VVC vector<vector<char>>
#define VB vector<bool>
#define VVB vector<vector<bool>>
#define fore(i,a) for(auto &i:a)

typedef pair <int, int> P;
template<class T> bool chmax(T &a, T b) { if (a < b) { a = b; return true; } return false; }
template<class T> bool chmin(T &a, T b) { if (a > b) { a = b; return true; } return false; }
const int  INF = 1 << 30;
const ll INFL = 1LL << 60;
const ll mod = 998244353;




int main() {

	string s;
	cin >> s;
	ll k;
	cin >> k;
	ll n = s.size();
	char a;
	a = s[0];
	bool b = true;

	REP(i, s.size()) {
		if (s[i] != a)b = false;
	}
	if (b) {
		cout << k * n / 2 << endl;
		return 0;
	}
	if (s[0] != s[n - 1]) {
		ll ans = 0;
		REP(i, n - 1) {
			if (s[i] == s[i + 1]) {
				s[i + 1] = '_';
				ans++;
			}
		}
		cout << ans * k << endl;
		return 0;
	}


	ll c = 0;
	ll d = n-1;

	while (true) {
		if (s[0] == s[c])c++;
		else break;
	}
	while (true) {
		if (s[0] == s[d])d--;
		else break;
	}


	ll ans = 0;
	ans += c / 2;
	ans += (n - d - 1) / 2;
	ll e = c + (n - d - 1);
	ans += (e / 2)*(k - 1);
	ll cnt = 0;

	FOR(i, c, d) {
		if (i + 1 == n - 1)break;
		if (s[i] == s[i + 1]) {
			s[i + 1] = '_';
			cnt++;
		}
	}
	ans += cnt * k;

	cout << ans << endl;



}


