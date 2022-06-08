#include<stdio.h>
int main(void)
{
	int x[3000],y[3000],i,j,a;
	i=j;
	i=1;
	while(1){
		scanf("%d %d",&x[i],&y[i]);
		if(x[i]>y[i]){
			a=x[i];
			x[i]=y[i];
			y[i]=a;
		}
		if(x[i]==0 && y[i]==0){
			break;
		}
		i++;
		j++;
	}
	i=1;
	while(i<=j){
		if(x[i]==0 && y[i]==0){
			break;
		}
		else{
			printf("%d %d\n",x[i],y[i]);
			i++;
		}
	}
	return 0;
}