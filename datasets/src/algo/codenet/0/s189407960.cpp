#include <iostream>
#include <stack>
#include <algorithm>
#include <vector>
#include <math.h>
#include <stdio.h>
#include <functional>
#include <string>
#include <cstdlib>
#include <numeric>
#include <cstdbool>
#include <cstring>
#include <map> 
#include<set>
#include<queue>
#include <iomanip>

typedef long long ll;


#define rep(i,n) for(ll i=0;i<n;i++)
using namespace std;

template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }

const long long INF = 1000000000000000;
const ll inf = -1e18;
typedef pair<ll, ll> P;
ll ma = 1000000000 + 7;
ll mx = 1000003;
ll h, w, n,m,k; string s;
int dx[4] = { 1, 0, -1, 0 };
int dy[4] = { 0, 1, 0, -1 };
ll gcd(ll x, ll y) {
	if (x % y == 0) return y;
	return gcd(y, x % y);

}
ll lcm(ll a,ll b) {
	ll g = gcd(a, b);
	return a / g * b;
}
void comb(vector<vector <ll> >& v) {
	for (ll i = 0; i < v.size(); i++) {
		v[i][0] = 1;
		v[i][i] = 1;
	}
	for (ll k = 1; k < v.size(); k++) {
		for (int j = 1; j < k; j++) {
			v[k][j] = (v[k - 1][j - 1] + v[k - 1][j])%ma;
		}
	}
}

ll GetDigit(ll num) {
	return log10(num) + 1;
}

int main() {
	cin >> s;
	cin >> k;
	ll cnt = 0;
		if (s.size() == 1) {
			if (k % 2 == 0) {
				cout << k / 2 << endl;
			}
			else {
				cout << (k - 1) / 2 << endl;
			}
			return 0;
		}
		if (k == 1) {
			rep(i, s.size() - 1) {
				if (s[i] == s[i + 1]) {
					s[i + 1] = '+';
					cnt++;
				}
			}
			cout << cnt << endl;
		}
		else {
			string t = s+s;
			ll pm = 0;
			rep(i, t.size() - 1) {
				if (t[i] == t[i + 1]) {
					t[i + 1] = '+';
					if (i + 1 <= s.size() - 1) {
						cnt++;
					}
					else {
						pm++;
					}
				}
			}
			cout << cnt + pm * (k - 1) << endl;
		}
}