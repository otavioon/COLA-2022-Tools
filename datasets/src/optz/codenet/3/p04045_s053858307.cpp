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
	
	int n, k, i, j, x;
	cin >> n >> k;
	vector<bool> valid(10, true);
	for (i = 0; i < k; i++) {
		cin >> x;
		valid[x] = false;
	}

	do {
		bool ok = true;
		x = n;
		while (x > 0) {
			if (!valid[x % 10]) {
				ok = false; break;
			}
			x /= 10;
		}
		if (ok) break;

		n++;
	} while (1);
	cout << n << "\n";

	return 0;
}
