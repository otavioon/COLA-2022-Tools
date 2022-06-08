#include<stdio.h>

int main() {
	int n,max,min;
	int a[10001];
	long long sum = 0;
	int k = 0;
	scanf("%d",&n);
	while (n--) {
		scanf("%d", &a[k]);
	}
	if (a[0]>a[1]) {
		max = a[0];
		min = a[1];
	}
	else {
		min = a[0];
		max = a[1];
	}
	sum = min + max;
	for (int i = 2;i < n;i++) {
		if (a[i]>max)
			max = a[i];
		if(a[i]<min)
			min = a[i];
		sum = sum + a[i];
	}
	printf("%d %d %lld\n", min, max, sum);
		
}