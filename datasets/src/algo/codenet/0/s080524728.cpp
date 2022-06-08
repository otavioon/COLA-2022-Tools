#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cstring>
#include <cmath>
#include <limits>
#include <stack>
#include <queue>
#include <map>

using namespace std;

using ll = long long;
using ui = unsigned int;
const ll MOD = 1000000007;


//A
int main() {
	char S[110];
	ll K;
	scanf("%s", S);
	scanf("%lld", &K);
	ll len = strlen(S);

	ll count[4];
	memset(count, 0, sizeof(count));

	char prev_char = ' ';
	for (ll i = 0; i < std::min(4LL, K); i++) {
		for (int j = 0; j < len; j++) {
			char c = S[j];

			if (c == prev_char) {
				count[i]++;
				prev_char = ' ';
			}
			else {
				prev_char = c;
			}
		}
	}

	ll result = 0;
	if (K <= 4) {
		for (auto val : count) {
			result += val;
		}
	}
	else {
		if (count[0] == count[1] && count[1] == count[2] && count[2] == count[3]) {
			result = count[0] * K;
		}
		else if (count[0] != count[1] && count[1] == count[2] && count[2] == count[3]) {
			result = count[0] + count[1] * (K - 1);
		}
		else if (count[0] != count[1] && count[0] == count[2] && count[1] == count[3]) {
			if (K % 2 == 0) {
				result = (count[0] + count[1]) * (K / 2);
			}
			else {
				result = (count[0] + count[1]) * (K / 2) + count[0];
			}
		}
		else {
			//(T-T
			result = count[0] * K;
		}

	}

	printf("%lld\n", result);

	return 0;
}