#include "iostream"
#include "climits"
#include "list"
#include "queue"
#include "stack"
#include "set"
#include "functional"
#include "algorithm"
#include "string"
#include "map"
#include "unordered_map"
#include "unordered_set"
#include "iomanip"
#include "cmath"
#include "random"
#include "bitset"
#include "cstdio"
#include "numeric"
#include "ctime"

using namespace std;

const long long int MOD = 1000000007;
//const int MOD = 998244353;

//long long int N, M, K, H, W, L, R;
long long int N, M, K, H, W, L, R;


int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	cin >> N;
	map<long long int, int>m;
	for (int i = 0; i < N; i++) {
		cin >> M;
		m[-M]++;
	}
	long long int st = 1;
	while (st < MOD * 2)st <<= 1;
	int ans = 0;
	for (auto &i : m) {
		for (long long int j = st; j > 1; j >>= 1) {
			if (-i.first > j / 2)break;
			if (-i.first * 2 == j) {
				ans += i.second / 2;
				i.second %= 2;
				break;
			}
			auto it = m.find(-(j + i.first));
			if (it == m.end())continue;
			int add = min(i.second, it->second);
			ans += add;
			i.second -= add;
			it->second -= add;
		}
	}
	cout << ans << endl;
	return 0;
}
