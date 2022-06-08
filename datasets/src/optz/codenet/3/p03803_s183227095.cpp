#include <bits/stdc++.h>

using namespace std;

int main() {
	int x, y;
	scanf("%d %d", &x, &y);
	if (x == y) puts("Draw");
	if (x == 1 || y == 1) {
		if (x == 1) puts("Alice");
		else if (y == 1) puts("Bob");
	}
	if (x > y) puts("Alice");
	else puts("Bob");
	return 0;
}