#include<iostream>
#include<queue>
#include<string>
#include<algorithm>
#include<vector>
#include<map>
#include<cmath>
#include<functional>
#include<set>
using namespace std;
#define int long long
int c[3][3];
signed main() {
	for (int i = 0; i < 3; i++)
		for (int j = 0; j < 3; j++)cin >> c[i][j];

	int flg = 0;
	
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			if (c[i][j] != c[i][i] + c[j][j] - c[j][i]) {
				puts("No"); return 0;
			}
		}
	}puts("Yes");
}