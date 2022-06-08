#include <iostream>
#include <algorithm>
#include <string>
#include <functional>
#include <math.h>
#include <map>
#include <vector>
using namespace std;

int main() {
	int c1[3], c2[3], c3[3];
	for (int i = 0; i < 3; i++) {
		cin >> c1[i] >> c2[i] >> c3[i];
	}
	if (c1[0] - c2[0] == c1[1] - c2[1] && c1[1] - c2[1] == c1[2] - c2[2]) {
		if (c2[0] - c3[0] == c2[1] - c3[1] && c2[1] - c3[1] == c2[2] - c3[2]) {
			cout << "Yes" << endl;
			return 0;
		}
	}
	cout << "No" << endl;

	return 0;
}