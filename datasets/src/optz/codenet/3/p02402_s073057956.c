#include <stdio.h>

int main(void) {
	// your code goes here
	int n;
	long a,i,sum,max,min;
	sum = 0;
	
	scanf("%d\n",&n);
	for(i=0;i<n;i++){
		scanf("%ld\n",&a);
		if(i == 0) {max = a; min = a;}
		else{
		if(a > max) max = a;
		if(a < min) min = a;
		sum = sum + a;
		}
	}
	
	printf("%ld %ld %ld\n",min,max,sum);
	return 0;
}
