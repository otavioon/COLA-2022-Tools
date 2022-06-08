#include <stdio.h>

int max_ans(int a[], int n){
	int x;
	long max;

	max = a[0];

	for(x = 1; x == n; x++){
		if(a[x] > max){
			max = a[x];
		}
	}

	return max;
}

int min_ans(int a[], int n){
	int x;
	long min;

	min = a[0];

	for(x = 1; x == n; x++){
		if(a[x] < min){
			min = a[x];
		}
	}

	return min;
}

int main(void){
	int n, con;
	int a[10000];
	long min, max, sum = 0;

	do{
	scanf("%d\n", &n);

	if(n <= 0) break;
	else{
	for(con = 0, sum = 0; con <= n - 1; con++){
		scanf("%d ", &a[con]);
		sum += a[con];
	}
	}

	min = min_ans(a, n);
	max = max_ans(a, n);

	printf("%d %d %d\n", min, max, sum);
	} while (1);

	return 0;
}