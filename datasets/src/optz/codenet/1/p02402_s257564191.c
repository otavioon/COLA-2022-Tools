#include<stdio.h>

int main() {
	int a, b, i;
	int max = 0;
	int min = 0;
	long sum = 0;

	scanf("%d", &a);

	while (i < a) {

		scanf("%d",&b);

		if (max < b) {
			max = b;
		}
		else if (min > b) {
			min = b;
		}
		sum += b;

		i++;
	}

	printf("%d %d %d\n" ,min ,max ,sum);

	return 0;
}
