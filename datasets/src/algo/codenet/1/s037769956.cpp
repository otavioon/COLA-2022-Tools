#include <iostream>
using namespace std;

int main() {
	int c[3][3] = {};

	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			cin >> c[i][j];
		}
	}

	if ((c[1][1]-c[1][3]== c[2][1] - c[2][3] == c[3][1] - c[3][3]) && (c[1][2] - c[1][1] == c[2][2] - c[2][1] == c[3][2] - c[3][1])) {
		cout << "No" << endl;
	}
	else {
		cout << "Yes" << endl;
	}

	return 0;
}