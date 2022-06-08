#include<string>
#include<iostream>
#include<algorithm>
#include<set>
#include<math.h>
#include<vector>
#include<sstream>
#include<queue>
#include<functional>
#include<bitset>
#include<cstdio>
#include<iomanip>
#include<map>
#include <string.h>
using namespace std;
int bd[3][3];
int a[3], b[3];
int main() {
	for (int i = 0; i < 9; i++) {
		cin >> bd[i / 3][i % 3];
	}
	for (int i = 0; i < 3; i++) {
		b[i] = bd[0][i];
	}
	a[1] = bd[1][0] - b[0];
	a[2] = bd[2][0] - b[0];
	for (int i = 0; i < 9; i++) {
		if (a[i / 3] + b[i % 3] != bd[i / 3][i % 3]) {
			cout << "No" << endl;
			return 0;
		}
	}
	cout << "Yes" << endl;
	return 0;
}
