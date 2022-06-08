#include <stdio.h>

int main(){
	int x[10000],y[10000];
	int i = 0, j;

	int c;

	x[0] = 1; y[0] = 1;

	while(1){
		scanf("%d",&x[i]);
		scanf("%d",&y[i]);
		//printf("input = %d %d\n",x[i],y[i]);
		if(x[i] == 0 && y[i] == 0) break;

		if(x[i] > y[i]){
			c = x[i];
			x[i] = y[i];
			y[i] = c; 
		}

		i++;
	}

	for(j = 0;j < i;j++){
		printf("%d %d\n",x[j],y[j]);
	}

	return 0;
}