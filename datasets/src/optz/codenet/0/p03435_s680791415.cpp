#include <stdio.h>
#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
#include <functional>
#include <map>
#include <iomanip>
#include <math.h> 
#include <stack>
#include <queue>
#include <cstdlib>
#include <bitset>

using namespace std;
int mat[3][3] = { 0 };
struct Myst
{
	int a[3] = { 0,0,0 };
	int b[3] = { 0,0,0 };
	bool af[3] = { false, false, false };
	bool bf[3] = { false, false, false };
}st;

int func(int i, int j, Myst sst) {

	if (j >= 3) {
		i++;
		j = 0;
		if (i >= 3) {
			cout << "Yes" << endl;
			

			exit(0);
		}
	}

	if (sst.af[i] == true && sst.bf[j] == true) {
		if (sst.a[i] + sst.b[j] == mat[i][j]) {
			func(i, j + 1, sst);
		}
		else {
			return 0;
		}
	}

	if (sst.af[i] == true) {
		sst.b[j] = mat[i][j] - sst.a[i];
		sst.bf[j] = true;
		func(i, j + 1, sst);
	}else
	if (sst.bf[j] == true) {
		sst.a[i] = mat[i][j] - sst.b[j];
		sst.af[i] = true;
		func(i, j + 1, sst);
	}
	else {

		for (int k = 0; k <= mat[i][j]; k++) {
			sst.a[i] = k;
			sst.b[j] = mat[i][j] - k;
			sst.af[i] = true;
			sst.bf[j] = true;
			func(i, j + 1, sst);
		}

	}
}

int main() {
	int i, j, k;
	Myst sst;

	for (i = 0; i < 3; i++) {
		for (j = 0; j < 3; j++) {
			cin >> mat[i][j];
		}
	}


	func(0, 0, sst);



	cout << "No" << endl;







	getchar();
	getchar();
	return 0;
}