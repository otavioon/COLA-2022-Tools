#include <iostream>
#include <string>
#include <algorithm>
#include <functional>
#include <vector>
#include <stack>
#include <queue>
#include <set>
#include <map>
#include <cstdio>
#include <cmath>
#include <tuple>
#define rep(i, n) for(i = 0; i < n; i++)
#define rrep(i, n) for(i = n - 1; i >= 0; i--)
#define int long long
using namespace std;

string s;
int k;

signed main() {
	int i, j;
	
	cin >> s >> k;
	
	int n = s.length();
	
	if (s[0] != s[n - 1]) {
		int len = 1;
		int cst = 0;
		for (i = 1; i < n; i++) {
			if (s[i - 1] != s[i]) {
				cst += len / 2;
				len = 1;
			}
			else {
				len++;
			}
		}
		cst += len / 2;
		cout << cst * k << endl;
		return 0;
	}
	
	//s[0] == s[n - 1]
	rep(i, n) if (s[i] != s[0]) break;
	rrep(j, n) if (s[j] != s[n - 1]) break;
	
	int l = i;
	int r = j;
	if (l >= r) {
		cout << n * k / 2 << endl;
		return 0;
	}
	
	int len = 1;
	int cst = 0;
	for (i = l + 1; i <= r; i++) {
		if (s[i - 1] != s[i]) {
			cst += len / 2;
			len = 1;
		}
		else {
			len++;
		}
	}
	cst += len / 2;
	
	int aida = (l + n) - r - 1;
	int cst2 = aida / 2;
	
	int cst3 = (n - (r + 1)) / 2;
	
	cout << cst2 * (k - 1) + cst * k + cst3 << endl;
	return 0;
}