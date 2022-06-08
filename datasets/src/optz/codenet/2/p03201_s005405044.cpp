#include<bits/stdc++.h>
using namespace std;

#define x first
#define y second
#define pb push_back
#define eb emplace_back
#define rep(i,a,b) for(auto i = (a); i != (b); ++i)
#define REP(i,n) rep(i,0,n)
#define all(v) (v).begin(), (v).end()
#define sz(v) ((int) (v).size())

typedef long long ll;
typedef long double ld;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<ii> vii;

// sum to 2^30
const int maxn = 2e5 + 10;
int A[maxn];

map<int, int> cnt[31];

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n;
	scanf("%d", &n);
	REP(i, n) scanf("%d", &A[i]);

	sort(A, A + n);

	ll ret = 0;
	REP(i, n) {
		int x = A[n-1-i];


		// 2^j >= x

		int y = -1;

		int j = 0;
		while ((1<<j) < x) j++;
		while (j < 31) {
			int ty = (1 << j) - x;
			if (cnt[j].find(ty) != cnt[j].end() && cnt[j][ty] > 0) {
				y = ty;
				break;
			}
			j++;
		}

		if (y >= 0) ret++;

		for (int k = 0; k < 31; k++) {
			if (y >= 0) {
				if (y < (1<<k)) cnt[k][y]--;
			} else {
				// cerr << "add " << x << endl;
				if (x < (1<<k)) cnt[k][x]++;
			}
		}
	}

	/* for (int k = 0; k < 31; k++) {
		cerr << k << ": ";
		for (auto x : cnt[k]) cerr << x.x << "->"<<x.y << " ";
		cerr << endl;
	} */

	cout << ret << endl;
	return 0;
}