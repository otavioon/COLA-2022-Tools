
#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <map>
#include <cmath>
#include <queue>
#include <set>
#include <stack>
#include <numeric>




typedef long long ll;
#define PI 3.14159265359
#define rep(i, n) for (ll i = 0; i < (ll)(n); i++)
#define mp make_pair
#define all(v) v.begin(),v.end()
#define rall(v) v.rbegin(),v.rend()
#define decp(n) cout<<fixed<<setprecision((int)n)
#define _GLIBCXX_DEBAC
#include <functional>
/*map<Keyの型, Valueの型> 変数名;
queue<型> 変数名;
priority_queue<型> 変数名;
priority_queue<型, vector<型>, greater<型>> 変数名;*/
//copy(v1.begin(), v1.end(), back_inserter(v2));
using namespace std;

ll gcd(ll a, ll b) {
	ll c;
	if (a < b) {
		c = a; a = b; b = c;
	}
	while (b != 0) {
		c = a % b; a = b; b = c;
	}
	return a;
}

ll lcm(ll a, ll b) {
	ll c;
	c = a * b / gcd(a, b);
	return c;
}

int sort_greater(int m, int n) {
	vector<int> a(m);
	for (int i = 0; i < m; i++) {
		cin >> a[i];
	}
	sort(a.begin(), a.end(), greater<int>());
	for (int i = 0; i < n; i++) {
		cout << a[i];
	}
	return 0;
}

int bubblesort(int a[], int n) {
	int sw = 0;
	bool flag = 1;
	for (int i = 0; flag; i++) {
		flag = 0;
		for (int j = n - 1; j >= i + 1; j--) {
			if (a[j] < a[j - 1]) {
				swap(a[j], a[j - 1]);
				flag = 1;
				sw += 1;
			}
		}
	}
	return sw;
}

int a_z()
{
	for (int i = 0; i <= ('Z' - 'A'); i++) {
		cout << (char)('A' + i);
	}
	return 0;
}

int selecttionsort(int a[], int n) {
	int t, sw = 0, minj;
	for (int i = 0; i < n - 1; i++) {
		minj = i;
		for (int j = 0; j < n - 1; j++) {
			if (a[j] < a[minj]) {
				minj = j;
			}
		}
		t = a[i]; a[i] = a[minj]; a[minj] = t;
		if (i != minj) sw += 1;

	}
	return sw;
}

bool is_prime(int x) {
	if (x <= 1) return false;
	for (int i = 2; i * i <= x; i++) {
		if (x % i == 0) return false;
	}
	return true;
}

const ll mod = 1000000007;

map<string, int> memo;

using P=pair<int, int>;
/*void dfs(int v, int p = -1) {
	for (int u : to[v]) {
		if (u == p) continue;
		ans[u] += ans[v];
		dfs(u, v);
	}
}*/
ll findIndex(int value, vector<ll> a)
{

	for (ll i = 0; i < (ll)a.size(); i++) {
		if (a[i] == value) {
			return i;
		}
	}
	return -1;
}

ll nCr(ll n, ll r) {
	ll a = 1;
	for (ll i = n; i > n - r; --i) {
		a = a * i;
	}
	for (ll i = 1; i < r + 1; ++i) {
		a = a / i;
	}
	return a;
}

void comb(vector<vector <long long int> >& v) {
	for (ll i = 0; i < v.size(); i++) {
		v[i][0] = 1;
		v[i][i] = 1;
	}
	for (ll k = 1; k < v.size(); k++) {
		for (ll j = 1; j < k; j++) {
			v[k][j] = (v[k - 1][j - 1] + v[k - 1][j]);
		}
	}
}



int main() {
	int a, b;
	cin >> a >> b;
	cout << (a - 1) * (b - 1);
	return 0;
}











