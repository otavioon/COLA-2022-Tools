#include<iostream>
#include<algorithm>
#include <cassert>
#include<string>
#include<vector>
#include <utility>
#include <math.h>
#include<cmath>
#include<map>
#include <limits>
# include <iomanip>
#define INF 1000000009;

using namespace std;
int gcd(int a, int b) {
	while (a % b != 0) {
		int c = 0;
		c = a % b;
		a = b;
		b = c;
	}
	return  b;
}
int kaizyo(int a) {
	long long ans = 1;
	for (int i = a; i > 0; i--) {
		ans *= i;
		ans = ans % 1000000007;
		//cout << ans << endl;
	}
	ans = ans % 1000000007;
	return ans;
}

	
	int dx[4] = { 1,0,-1,0 }, dy[4] = { 0,1,0,-1 };
	


int main() {
	int manji[5][5];
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			cin >> manji[i][j];
		}
	}
	int a1 = 0, a2 = 0, a3 = 0;
	for (int i = 0; i < 2; i++) {
		
			a1 = abs(manji[i][0] - manji[i + 1][0]);
			a2 = abs(manji[i][1] - manji[i + 1][1]);
			a3 = abs(manji[i][2] - manji[i + 1][2]);
			if (a1 != a2 || a2 != a3) {
				cout << "No" << endl;
				return 0;
		}
	}
	for (int j = 0; j < 2; j++) {

		a1 = abs(manji[0][j] - manji[0][j+1]);
		a2 = abs(manji[1][j] - manji[ 1][j+1]);
		a3 = abs(manji[2][j] - manji[ 2][j+1]);
		if (a1 != a2 || a2 != a3) {
			cout << "No" << endl;
			return 0;
		}
	}
	cout << "Yes" << endl;
	return 0;
}
