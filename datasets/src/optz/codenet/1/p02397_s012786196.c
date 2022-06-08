#include<stdio.h>

int main(void)
{
	int i,x[3000],y[3000];
	
	for(i=0;i<=2999;i++){
		scanf("%d %d",&x[i],&y[i]);
		if(x[i]==0 && y[i]==0){
			break;
		}
	}
	for(i=0;i<=2999;i++){
		if(x[i]!=0 && y[i]!=0){
			if(x[i]<=y[i]){
			printf("%d %d\n",x[i],y[i]);
			}else{
				printf("%d %d\n",y[i],x[i]);
			}	
		}else{
			break;
		}
	}
	return 0;
}