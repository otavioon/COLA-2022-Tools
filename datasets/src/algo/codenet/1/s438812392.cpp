#include <iostream>

using namespace std;

int main(void)
{
	int c[3][3], a, b;

	for (int i = 0; i < 3; i++){
		for (int j = 0; j < 3; j++) cin >> c[i][j];
	}

	a = c[0][0] - c[1][0];
	b = c[0][0] - c[2][0];
	if ((a == c[0][1] - c[1][1]) && (a == c[0][2] - c[1][2]) && (b == c[0][1] - c[2][1]) && (b == c[0][2] - c[2][2])) cout << "Yes" << endl;
	else cout << "No" << endl;

	return 0;
}

			

