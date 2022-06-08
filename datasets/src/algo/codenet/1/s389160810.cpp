#include <iostream>
#include <algorithm>
#include <functional>
#include<vector>
#include<math.h>
#include<string>
using namespace std;


int main() {
	int C[9];

	for (int i = 0; i < 9; i++) {
		cin >> C[i];
	}

	if ((C[4] + C[0] == C[1] + C[3]) && (C[7] + C[0] == C[6] + C[1]) && (C[5] + C[0] == C[2] + C[3]) && (C[0] + C[8] == C[2] + C[6])) {
		cout << "Yes" << endl;
	}
	else {
		cout << "No" << endl;
	}

	return 0;
}