#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxx = 1e5 + 7;
const int Inf = 1 << 30;
int a[5][5];

int main() {
	//Sum矩阵 = 3 * (a1 + a2 + a3) + 3 * (b1 + b2 + b3);
	//Sum对角线 = (a1 + a2 + a3) + (b1 + b2 + b3);
	//Sum矩阵 = 3 * Sum对角线
	int sum = 0;
	for(int i = 1; i <= 3; i++) {
		for(int j = 1; j <= 3; j++) {
			cin >> a[i][j];
			sum += a[i][j];
		}
	}
	int tt = a[1][1] + a[2][2] + a[3][3];
	if(sum % 3) puts("No");
	else {
		if(sum % tt) puts("No");
		else {
			if(sum / tt != 3) puts("No");
			else puts("Yes");
		}
	}
}