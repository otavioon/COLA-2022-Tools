#include<stdio.h>

int main(void){
	int x[3000],y[3000],i,temp;
	
	i=0;
	while(1){
		scanf("%d %d",&x[i],&y[i]);
		if(x[i]==0&&y[i]==0){
			break;
		}
		if(x[i]>y[i]){
		temp=x[i];
		x[i]=y[i];
		y[i]=temp;
		printf("%d %d\n",i+1,x[i]);
		}
                      i++;
	}
	return 0;
}