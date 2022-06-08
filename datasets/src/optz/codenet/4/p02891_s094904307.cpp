#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef pair<int, int> pair2;
typedef pair<int, pair<int, int> > pair3;
typedef pair<int, pair<int, pair<int, int> > > pair4;
#define MAXN 200013
#define INF 1000000000000000000LL
#define MOD 1000000007LL
#define IINF 1000000000
#define mp make_pair
#define pb push_back
#define remove pop
#define all(x) x.begin(), x.end()

char values[MAXN];

int dp[MAXN][2];
pair2 from[MAXN][2];

int main() {
	if (fopen("FILENAME.in", "r")) {
		freopen("FILENAME.in", "r", stdin);
		freopen("FILENAME.out", "w", stdout);
	}
	ios_base::sync_with_stdio(false); 
	cin.tie(NULL);

	string s;
	ll k;

	cin >> s >> k;

	if (s.size() == 1) {
		cout << (k / 2) << endl;
		return 0;
	}

	int n = s.size();

	s = s + s + s + s + s;

	for (int i = 0; i < s.size(); i++) {
		values[i] = s[i];
	}


	for (int i = 0; i <= s.size() + 1; i++) {
		dp[i][0] = IINF;
		dp[i][1] = IINF;
	}

	dp[0][0] = 0;
	for (int i = 0; i < s.size(); i++) {
		if (dp[i + 1][0] > dp[i][1]) {
			dp[i + 1][0] = dp[i][1];
			from[i + 1][0] = mp(i, 1);
		}

		if (dp[i + 1][1] > dp[i][0] + 1) {
			dp[i + 1][1] = dp[i][0] + 1;
			from[i + 1][1] = mp(i, 0);
		}

		if (dp[i + 1][1] > dp[i][1] + 1) {
			dp[i + 1][1] = dp[i][1] + 1;
			from[i + 1][1] = mp(i, 1);
		}

		if (i == 0 || values[i - 1] != values[i]) {
			if (dp[i + 1][0] > dp[i][0]) {
				dp[i + 1][0] = dp[i][0];
				from[i + 1][0] = mp(i, 0);
			}
		}
	}

	pair2 anspos = mp(s.size(), 0);
	if (dp[s.size()][1] < dp[s.size()][0]) {
		anspos.second = 1;
	}

	int totalCost = dp[anspos.first][anspos.second];

	int endCost = 0;
	int startCost = 0;
	int midCost = 0;

	while (anspos.first != 0) {
		if (anspos.first == n * 4) {
			endCost = totalCost - dp[anspos.first][anspos.second];
		}
		if (anspos.first == n) {
			startCost = dp[anspos.first][anspos.second];
			midCost = totalCost - endCost - startCost;
		}
		anspos = from[anspos.first][anspos.second];
	}

	//cout << "have " << startCost << ' ' << midCost << ' ' << endCost << endl;

	assert(midCost % 3 == 0);

	midCost /= 3;

	if (k == 1) {
		cout << startCost << endl;
	} else {
		cout << (startCost + endCost + (1LL * midCost * (k - 2)));
	}


}