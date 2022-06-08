#include <cstdio>
#include <cstdlib>
#include <limits>
#include <cmath>
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <map>
#include <complex>
using namespace std;


int main() {
	int c[3][3];
	int sumc = 0;
	for(int i=0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			cin >> c[i][j];
			sumc += c[i][j];
		}
	}
	sumc /= 3;
	if (sumc == c[0][0] + c[1][1] + c[2][2] && sumc == c[1][0] + c[2][1] + c[0][2] && sumc == c[2][0] + c[0][1] + c[1][2]) {
		cout << "Yes" << endl;
	}
	else
		cout << "No" << endl;
	return 0;
}
