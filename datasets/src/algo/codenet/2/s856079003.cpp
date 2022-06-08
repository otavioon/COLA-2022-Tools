#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> pii;
typedef long long ll;
typedef vector<int> vi;

#define pb push_back
#define eb emplace_back
#define mp make_pair
#define fi first
#define se second
#define rep(i,n) rep2(i,0,n)
#define rep2(i,m,n) for(int i=m;i<(n);i++)
#define ALL(c) (c).begin(),(c).end()

const int MN = 200010;

int main() {
	int N; cin >> N;

	multiset<int> s;
	rep(i, N) {
		int t; cin >> t;
		s.insert(t);
	}

	int ans = 0;

	while (s.size()) {
		auto it = s.end();
		--it;
		int x = *it;
		s.erase(it);

		for (int j = 0; j < 30; ++j) {
			int p = (1 << j) - x;
			if (p <= x && s.count(p)) {
				s.erase(s.find(p));
				++ans;
				break;
			}
		}
	}

	cout << ans << endl;
	
	return 0;
}