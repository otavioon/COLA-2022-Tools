#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <set>

using namespace std;


int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int n, k; cin >> n >> k;
	set<int> arr;
	int tmp;
	for (int i = 0; i < k; ++i) {
		cin >> tmp;
		arr.insert(tmp);
	}

	int ans = n;
	while (true) {
		int tmp = ans;
		bool done = true;
		while (tmp > 0) {
			if (arr.find(tmp % 10) != arr.end()) {
				++ans;
				done = false;
				break;
			}
			else tmp /= 10;
		}
		if (done) {
			cout << ans << "\n";
			return 0;
		}
	}

}