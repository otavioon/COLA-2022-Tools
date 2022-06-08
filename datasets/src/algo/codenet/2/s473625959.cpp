#include <iostream>
#include <string>
#include <array>
#include <vector>
#include <queue>
#include <stack>
#include <list>
#include <set>
#include <map>
#include <algorithm>
#include <cmath>
#include <iomanip>

#define FOR(i, a, b) for(decltype(b) i = (a); i < (b); ++i)
#define REP(i, n) FOR(i, 0, n)

typedef long long ll;
typedef unsigned long long ull;
typedef unsigned int uint;

using namespace std;

#ifdef INPUT
#include <sstream>
stringstream input(R"(
6
1 2 4 6 16 32 64
)");
#define cin input
#endif

int main()
{
	int n;
	cin >> n;

	multiset<int, greater<int>> a;

	REP (i, n)
	{
		int x;
		cin >> x;
		a.insert(x);
	}

	int r = 0;

	for (auto it = a.begin(); it != a.end(); ++it)
	{
		int x = 1;
		for (int t = *it; t; t >>= 1)
			x <<= 1;
		x -= *it;
		auto it2 = a.upper_bound(x);
		if (it2 == a.begin())
			continue;
		--it2;
		if (it2 == it)
			continue;
		if (*it2 != x)
			continue;
		a.erase(it2);
		++r;
	}

	cout << r << endl;

	return 0;
}
