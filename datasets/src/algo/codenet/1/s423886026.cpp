#include <iomanip>
#include <random>
#include <time.h>
#include <vector>
#include <queue>
#include <functional>
#include <map>
#include <string>
#include <cstdlib>
#include <typeinfo>
#include <math.h>
#include <algorithm>
#include <iostream>
using namespace std;
typedef long long ll;
typedef pair<ll, ll> P;

int main() {
	ll c[3][3];
	for (int i = 0; i < 3; i++)for (int j = 0; j < 3; j++)cin >> c[i][j];
	cout << (c[0][0] + c[1][1] + c[2][2] == c[0][1] + c[1][2] + c[2][0] && c[0][0] + c[1][1] + c[2][2] == c[0][2] + c[1][0] + c[2][1] ? "Yes" : "No") << endl;
	return 0;
}
