#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <cctype>
#include <set>
#include <map>
#include <cmath>
#include <queue>
#include <stack>
#include <iomanip>
#include <cstdio>
#include <numeric>
#include <functional>
#include <cstdlib>
#include <regex>
#include <list>
int main() {
	std::vector<int>a(2);
	for (int i = 0;; i++) {
		std::cin >> a[0] >> a[1];
		if (a[0] == 0 && a[1] == 0)
			break;
		std::sort(a.begin(), a.end());
		std::cout << a[0] << ' ' << a[1] << std::endl;
	}
	return 0;
}
