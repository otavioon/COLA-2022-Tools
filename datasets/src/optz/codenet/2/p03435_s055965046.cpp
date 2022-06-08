#include <iostream>
#include <algorithm>
#include <string>
#include <queue>
#include <cmath>
#include <map>

using namespace std;
using ll = long long;

int main() {
	vector<vector<ll>> c(3, vector<ll>(3));
	for (ll i = 0; i < 3; i++)
	{
		for (ll j = 0; j < 3; j++)
		{
			cin >> c[i][j];
		}
	}
	for (ll i = 0; i < 2; i++)
	{
		if (c[1][i + 1] - c[1][i] == c[0][i + 1] - c[0][i] == c[2][i + 1] - c[2][i] &&
			c[i + 1][0] - c[i][0] == c[i + 1][1] - c[i][1] == c[i + 1][2] - c[i][2]) continue;
		else {
			cout << "No" << endl;
			return 0;
		}
	}
	cout << "Yes" << endl;
	return 0;
}