#include <bits/stdc++.h>
using namespace std;
#define eb emplace_back
#define emp emplace
#define fi first
#define se second
#define INF 0x3f3f3f3f
typedef long long ll;
typedef pair<int, int> ii;

int g[3][3];

int main(void) {
	ios_base::sync_with_stdio(false);

	int ans =0;
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			cin >> g[i][j];
			ans += g[i][j];
		}
	}

	if (ans%3) cout << "No" << endl;
	else cout << "Yes" << endl;

	return 0;
}