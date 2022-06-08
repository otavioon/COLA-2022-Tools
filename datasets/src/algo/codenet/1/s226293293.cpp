#include<stdio.h>
#include<string>
#include<iostream>
#include<math.h>
#include<vector>
#include<set>
#include<algorithm>
#include<list>
using namespace std;

int main() {
	int c[3][3];
	for (int i = 0;i < 3;i++) {
		cin >> c[i][0] >> c[i][1] >> c[i][2];
	}
	int sum = 0;
	for (int i = 0;i < 3;i++) {
		for (int j = 0;j < 3;j++) {
			sum += c[i][j];
		}
	}
	if (sum % 3 == 0) cout << "Yes\n";
	else cout << "No\n";

	return 0;
}