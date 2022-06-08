#include<stdio.h>

int main(void) {
	int n, i, a;
	int min, max;
	long sum = 0;
	
	scanf("%d", &n);
	
	for(i = 0; i < n; i++) {
		scanf("%d", &a);
		if(i==0) {
			min = a;
			max = a;
		} else if(a > max) {
			max = a;
		} else if(a < min) {
			min = a;
		}
		
		sum+=a;
	}
	
	printf("%d %d %ld\n", min, sum, max);
	
	return 0;
}