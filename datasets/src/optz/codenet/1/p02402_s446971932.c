#include <stdio.h>

int main(void){
	int n, con;
	int a[10000];
	long min, max, sum;

	do{
	scanf("%d\n", &n);

	if(n <= 0) break;
	else{
	for(con = 1, sum = 0; con <= n; con++){
		scanf("%d", &a[con - 1]);

		if(con == 1){
			min = a[con - 1];
			max = a[con - 1];
		}

		if(a[con - 1] < min){
			min = a[con - 1];
		} else if(a[con - 1] > max){
			max = a[con - 1];
		}

		sum += a[con - 1];
	}
	}

	printf("%d %d %d\n", min, max, sum);
	} while (1);

	return 0;
}