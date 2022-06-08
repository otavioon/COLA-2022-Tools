#include <stdio.h>
#pragma warning(disable:4996)

int a[10000], stts[10000] = { 0 };
int main() {
	int n;
	scanf("%d", &n);

	for (int i = 1; i <= n; i++) {
		scanf("%d", &a[i]);
	}

	int cnt = 0, pt = 1;
	while(pt!=2 && stts[a[pt]]!=1){
		stts[pt] = 1;
		pt = a[pt];
		cnt++;
	}

	if (stts[a[pt]] == 1 && pt != 2) {
		printf("-1\n");
	}
	else {
		printf("%d\n", cnt);
	}

	return 0;
}