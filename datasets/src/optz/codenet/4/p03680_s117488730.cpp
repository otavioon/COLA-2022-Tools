#include <iostream>
#include <string>
#include <sstream>
#include <iomanip> 
#include <math.h>
#include <stdio.h>
#include <string.h>
#include <queue>
#include <stack>
#include <vector>
#include <map>
#include <set>
#include <functional>
#include <algorithm>
#include <unordered_map>
#include <unordered_set>
#include <bitset>

using namespace std;


int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	int n, i, j, k, ans, x;
	cin >> n;
	vector<int> a(n + 1);
	for (i = 1; i <= n; i++) cin >> a[i];
	set<int> s;
	s.insert(1);
	x = 1;
	while (s.find(a[x]) == s.end()) {
		s.insert(a[x]);
		x = a[x];
		if (x == 2) break;
	}

	if (s.find(2) == s.end()) cout << "-1\n";
	else cout << s.size() - 1 << "\n";

	return 0;
}
