#include <iostream>

using namespace std;

int main(void) {
	int a[9], i = 0;
	for (; i < 9; i++)
		scanf("%d", &a[i]);
	if (a[0] + a[5] + a[7] == a[1] + a[3] + a[8] && a[1] + a[3] + a[8] == a[2] + a[4] + a[6])
		printf("Yes\n");
	else
		printf("No\n");
	return 0;
}