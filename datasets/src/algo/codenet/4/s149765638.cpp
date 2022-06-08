#include <iostream>
#include <vector>
#include <set>
#include <queue>
#include <algorithm>
#include <string>
#include <cmath>
#include <functional>
#include <iomanip>

#define _USE_MATH_DEFINES
#include <math.h>
using namespace std;
#define MAX 10
int r[MAX];
int main() {
	string n;
	int k;
	cin >> n >> k;
	for (int i = 0; i < k; ++i)
	{
		cin >> r[i];
	}
	bool f = true,f2 = false;
	for (int i = 0; i < n.length(); ++i)
	{
		if (count(r, r + k, int(n[i] - '0')) > 0 && f)
		{
			int t = int(n[i] - '0');
			f = false;
			f2 = true;
			while (count(r, r + k, t) > 0)
			{
				++t;
				if (t == 10 ) {
					if(!i) f = false;
					t = 0;
				}
			}
			char s = char(t + '0');
			n = n.substr(0, i) + s + n.substr(i + 1);
			if (f) {
				int j = 1;
				while (count(r, r + k, j) > 0)
				{
					++j;
				}
				s = char(j + '0');
				n = s + n;
				++i;
			}
		}
		else {
				int j = 0;
				while (count(r, r + k, j) > 0)
				{
					++j;
				}
				char c = j + '0';
				if (n[i] > j) {
					n = n.substr(0, i) + c + n.substr(i + 1);
				}
		}
	}
	int i = 0;
	while (n[0] == '0' && i < n.length() - 1) {
		n = n.substr(1);
	}
	cout << n << endl;
	return 0;
}