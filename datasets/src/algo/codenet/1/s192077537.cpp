#include <iostream>
#include <iomanip>
#include <algorithm>
#include <vector>
#include <map>
#include <stack>
#include <string>
#include <list>
#include <queue>
#include <deque>
#include <math.h>
using namespace std;

typedef pair<int, int> P;
#define ll long long
#define int ll
#define INF (1LL<<60)
#define mod 1000000007

int c[3][3], a[3], b[3];

signed main(){

	for (int i = 0; i < 3; i++)
		for (int j = 0; j < 3; j++)
			cin >> c[i][j];

	// a0+b0 a0+b1 a0+b2
	// a1+b0 a1+b1 a1+b2
	// a2+b0 a2+b1 a2+b2

	a[0] = 0;
	b[0] = c[0][0];
	b[1] = c[0][1];
	b[2] = c[0][2];
	a[1] = c[1][0] - b[0];
	a[2] = c[2][0] - b[0];

	if (c[1][1] != a[1] + b[1] ||
		c[1][2] != a[1] + b[2] ||
		c[2][1] != a[2] + b[1] ||
		c[2][2] != a[2] + b[2])
		cout << "No" << endl;
	else
		cout << "Yes" << endl;


	return 0;
}
