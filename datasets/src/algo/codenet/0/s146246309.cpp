#include <bits/stdc++.h>

using namespace std;

using ll = int64_t;
using Vi = vector<int>;
using Vl = vector<ll>;
using Pii = pair<int, int>;
using Pll = pair<ll, ll>;

constexpr int I_INF = 2147483647;
constexpr ll L_INF = 9223372036854775807LL;

//===




int main()
{
	string S;
	cin >> S;
	int K;
	cin >> K;

	ll ans = 0;
	char now = S[0];
	int idx = 1;
	int lenS = (int)S.size();

	ll cnt = 1;
	for (int i = 1; i < lenS; ++i) {
		if (S[i] == now) {
			++cnt;
		}
		else {
			ans += cnt / 2;
			now = S[i];
			cnt = 1;
		}
	}

	if (cnt != 1) {
		ans += cnt / 2;
	}

	ans = ans * K;
	
	if (S[0] == S[lenS - 1]) {
		if (cnt % 2 == 1) {
			++ans;
		}
	}

	cout << ans << endl;

	return 0;
}