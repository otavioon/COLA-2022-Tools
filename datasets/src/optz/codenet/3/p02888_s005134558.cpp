#include <vector>
#include <iostream>
#include <stack>
#include <string>
#include <algorithm>
#include <unordered_set>

using namespace std;
typedef long long ll;
typedef vector<int> VI;

int main(void)
{
	int n;
	cin >> n;
	vector<double> vs(n);
	for (int i = 0; i < n; i++) {
		cin >> vs[i];
	}
	sort(vs.begin(), vs.end());
	ll sum = 0;
	for (int i = 0; i < n - 1; i++) {
		for (int j = i + 1; j < n; j++) {
			auto a = vs[i];
			auto b = vs[j];
			auto ab = a + b - 0.01;
			auto f = vs.begin() + j + 1;
			auto u = upper_bound(f, vs.end(), ab);
			sum += u - f;
		}
	}
	cout << sum << endl;
	return 0;
}