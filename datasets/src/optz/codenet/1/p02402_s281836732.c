#include <stdio.h>

int main(void){
	int n, con;
	int inp;
	long min, max, sum = 0;

	do{
	scanf("%d\n", &n);

	if(n <= 0) break;
	else{
	for(con = 0; con < n; con++){
		scanf("%d", &inp);
		sum += inp;
		if(con == 0) min = inp; max = inp;
		if(inp < min){
			min = inp;
		}
		if(inp > max){
			max = inp;
		}
	}
	}

	printf("%ld %ld %ld\n", min, max, sum);
	} while (n <= 0);

	return 0;
}