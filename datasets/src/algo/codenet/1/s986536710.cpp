#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ii = pair<int, int>;
#define sz(x) (int)(x).size()
/* --- */
int c[4][4];

bool check() {
	for (int i = 1; i < 3; i++)
		for (int j = 1; j < 3; j++)
			if (c[i][j] != c[i][0] + c[0][j] - c[0][0]) return false;
	return true;
}

int main() {
	for (int i = 0; i < 3; i++)
		for (int j = 0; j < 3; j++)
			scanf("%d", &c[i][j]);
	printf("%s\n", check() ? "Yes" : "No");
}

