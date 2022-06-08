#include<stdio.h>
#include<math.h>
#include<algorithm>
#include<utility>
#include<queue>
#include<string.h>
#include<string>
#include<set>
using namespace std;
typedef long long LL;

#define _CRT_SECURE_NO_WARNINGS
int N;
int c[4][4];
int main() {
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3;j++) {
			scanf("%d", &c[i][j]);
		}
	}
	bool f = true;
	for (int i = 0; i < 3;i++) {
		for (int j = 0; j < 2;j++) {
			for (int k = i + 1; k < 3; k++) {
				if (c[i][j + 1] - c[i][j] != c[k][j + 1] - c[k][j]) {
					f = false;
				}
			}
		}
	}

		if (f) {
			printf("Yes");
		}
		else {
			printf("No");
		}
	
	return 0;
}