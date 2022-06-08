#include <stdio.h>

int main(void){
	int x, y, n, i;	

	for(i = 1; 1; i++){
		scanf("%d %d", &x, &y);
		if(x != 0 && y != 0){
			if(x > y){
				n = x;
				x = y;
				y = n;
			}
		} else{
			break;
		}
	}
	
	printf("%d %d\n", x, y);
	
	return 0;
}