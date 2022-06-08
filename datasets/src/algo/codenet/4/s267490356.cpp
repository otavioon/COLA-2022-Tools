#include <bits/stdc++.h>
using namespace std;

#define sswap(x, y) { x+=y; y=x-y; x-=y; }
#define LSOne(S) ((S) & (-S))

#define EPS 1e-6
#define MOD 1000000007

#define fi first
#define se second
#define pb push_back
#define ende '\n'

#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define mset(x, y) memset(&x, (y), sizeof(x))

using ll = long long;
using ii = pair<int, int>;
using vi = vector<int>;


int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);

	string n;
	int k;
	cin >> n >> k;

	set<int> s;
	while (k--) {
		int e; cin >> e;
		s.insert(e);
	}
	
	int esq = 0;
	for (int i = 0; i < n.size(); i++) {
		if (s.count(n[i]-'0')) {
			int k = (esq ? 0 : (n[i]-'0'+1) % 10);
			while (s.count(k)) k = (k+1)%10;
			esq = 1;
			n[i] = k+'0';
		}
	}
	cout << n << ende;
  return 0;
}
