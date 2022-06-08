#include <iostream>
#include <map>
#include <vector>
#include <set>
#include <algorithm>

using namespace std;

int main() {
	int N, K;
	cin >> N >> K;

	set<int> numset;
	int tmp = 0;
	while (cin >> tmp) {
		numset.insert(tmp);
	}

	int ans = N;
	int m = 0;
	while (ans < 10*N) {
		tmp = ans;
		while (tmp) {
			m = tmp % 10;
			if (numset.count(m))
				break;
			tmp /= 10;
		}
		if (tmp == 0) {
			cout << ans << endl;
			break;
		}
		ans++;
	}

	return 0;
}
