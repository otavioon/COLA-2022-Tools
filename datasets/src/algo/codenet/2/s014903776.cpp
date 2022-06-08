#include <iostream>
#include <string>

#include <vector>
#include <deque>
#include <list>
#include <set>
#include <unordered_set>
#include <map>
#include <unordered_map>

#include <algorithm>

int xxx(int x)
{
	for (int i = 0; i < 64; ++i) {
		if (x < (1 << i)) {
			return (1 << i) - x;;
		}
	}
	return 0;
}

int main()
{
	long N;
	std::set<int, std::greater<int> > A;
	int n = 0;

	std::cin >> N;
	for (int i = 0; i < N; ++i) {
		int j;
		std::cin >> j;
		A.insert(j);
	}

	for (auto it = A.begin(); A.size() >= 2 && it != A.end();) {
		int v = *it;
		if ((v & (-v)) == v) {
			A.erase(it++);
			continue;
		}
		int u = xxx(v);
		std::cout << "v = " << v << ", u = " << u << "\n";
		auto jt = A.find(u);
		if (jt != A.end()) {
			A.erase(it++);
			A.erase(jt);
			++n;
			continue;
		}
		++it;
	}

	std::cout << n << "\n";
}