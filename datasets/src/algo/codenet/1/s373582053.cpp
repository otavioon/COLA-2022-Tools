#include<iostream>
using namespace std;

int main() {
	int g[3][3];
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			cin >> g[i][j];
		}
	}

	if (g[0][0] + g[1][1] == g[0][1] + g[1][0] && g[0][0] + g[1][2] == g[0][2] + g[1][0] && g[0][0] + g[2][1] == g[0][1] + g[2][0] && g[0][0] + g[2][2] == g[0][2] + g[2][0]) {
		cout << "Yes" << endl;
	}
	else cout << "No" << endl;

	return 0;
}