#include<stdio.h>

int main() {
	int n,max,min;
	int a[10001];
	long sum = 0;
	int k = 0;
	scanf("%d",&n);
	while (n--) {
		scanf("%d", &a[k]);
		sum = sum + a[k];
		k++;
	}
	if (a[0]>a[1]) {
		max = a[0];
		min = a[1];
	}
	else {
		min = a[0];
		max = a[1];
	}
	for (int i = 2;i < n;i++) {
		if (a[i]>max)
			max = a[i];
		if(a[i]<min)
			min = a[i];
	}
	printf("%d %d %d\n", min, max, sum);
		
}