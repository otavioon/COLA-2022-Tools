#include <stdio.h>
#include <iostream>
#include <cstdlib>
#include <iomanip>
#include <cmath>
#include <vector>
#include <string>
#include <algorithm>
#include <cstdlib>
#include <limits>
#include <numeric>
#include <stack>
#include <set>

using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef vector<int> vi;	//using vi = vector<int>;
typedef vector<vector<int>> vvi;

#define rep(i, N) for (int i = 0; i < N; i++)

vvi memo(1000, vector<int>(1000));

int main()
{
	int n, d;
	cin >> n >> d;
	if (n % (2 * d + 1) == 0)cout << n / (2 * d + 1) << endl;
	else cout << (n / (2 * d + 1))+1 << endl;

	return 0;
}
