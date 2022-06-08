
#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <queue>
#include <climits>
#include <functional>
#include <array>
#include <cmath>

using namespace std;

int c[3][3];

int main(){
	
	
	int sum = 0;
	for (int i = 0; i < 3; ++i) {
		for (int k = 0; k < 3; ++k) {
			cin >> c[i][k];
			sum += c[i][k];
		}
	}

	if (sum % 3 == 0)	cout << "Yes" << endl;
	else	cout << "No" << endl;

	return 0;
}
