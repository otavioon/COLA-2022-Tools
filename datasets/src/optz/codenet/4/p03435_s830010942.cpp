#include<iostream>
#include<vector>
using namespace std;

int main() {
	int grid[3][3];
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			cin >> grid[i][j];
		}
	}
	int diff1[3], diff2[3];
	for (int i = 0; i < 3; i++) {
		diff1[i] = abs(grid[i][0] - grid[i][1]);
		diff2[i] = abs(grid[i][1] - grid[i][2]);
	}
	bool flag = true;
	if (diff1[0] != diff1[1] || diff1[1] != diff1[2]) {
		flag = false;
	}
	if (diff2[0] != diff2[1] || diff2[1] != diff2[2]) {
		flag = false;
	}

	for (int i = 0; i < 3; i++) {
		diff2[i] = abs(grid[0][i] - grid[1][i]);
		diff2[i] = abs(grid[1][i] - grid[2][i]);
	}
	if (diff2[0] != diff2[1] || diff2[1] != diff2[2]) {
		flag = false;
	}
	if (diff2[0] != diff2[1] || diff2[1] != diff2[2]) {
		flag = false;
	}
	if (flag) {
		cout << "Yes" << endl;
	}
	else {
		cout << "No" << endl;
	}
	return 0;
}