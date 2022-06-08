#include <bits/stdc++.h>

using namespace std;
using llong = long long;
using ldbl = long double;
using lpair = pair<llong, llong>;

#define ALL(x) x.begin(), x.end()

const llong inf = 1'000'000'000'000'007ll;
const llong mod = 1e9+7;

int main() {
	string S;
	llong K;
	cin >> S >> K;

	string mask = S, nmaskS = S;
	llong mres = 0, nmres = 0;
	for (int i = 1; mask[i]; ++i) {
		if (mask[i] == mask[i-1]) {
			++mres;
			mask[i] = '-';
		}
	}
	if (nmaskS[0] != mask[mask.size()-1]) {
		cout << mres*K << endl;
	} else {
		nmaskS[0] = '-';
		++nmres;
		for (int i = 1; nmaskS[i]; ++i) {
			if (nmaskS[i] == nmaskS[i-1]) {
				++nmres;
				nmaskS[i] = '-';
			}
		}

		if (S[0] == nmaskS[nmaskS.size()-1]) {
			cout << mres + nmres*(K-1) << endl;
		} else {
			cout << (mres + nmres)*K/2 + mres*(K&1) << endl;
		}
	}

	return 0;
}