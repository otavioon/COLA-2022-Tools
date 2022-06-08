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

long xxx(long x)
{
	for (long i = 0; i < 64; ++i) {
		if (x < (1 << i)) {
			return (1 << i) - x;
		}
	}
	return 0;
}

int main()
{
	long N;
	std::multiset<long, std::greater<long> > A;
	int n = 0;

	std::cin >> N;
	for (long i = 0; i < N; ++i) {
		long j;
		std::cin >> j;
		A.insert(j);
	}

	while (A.size() >= 2) {
		auto it = A.begin();
		long v = *it;
		A.erase(it);
		long u = xxx(v);
		auto jt = A.find(u);
		if (jt != A.end()) {
			A.erase(jt);
			++n;
			continue;
		}
	}

	std::cout << n << "\n";
}