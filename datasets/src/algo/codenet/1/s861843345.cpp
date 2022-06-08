#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <algorithm>
#include <math.h>
#include <map>
#include <vector>
#include <list>
#include <queue>
#include <stack>

using namespace std;


int main() {
	int c[3][3], sum = 0;
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			cin >> c[i][j];
			sum += c[i][j];
		}
	}
	if (sum % 3 == 0)cout << "Yes" << endl;
	else cout << "No" << endl;



	return 0;
}
