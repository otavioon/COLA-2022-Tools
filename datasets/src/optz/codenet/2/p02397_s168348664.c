#include <stdio.h>
int main(void){
	
	int x[3000],y[3000];
	int i=0,a,z;
	for(i=0;i<3000;i++){
		scanf("%d %d",&x[i],&y[i]);
		if(x[i]==0 && y[i]==0)break;
		if(x[i]>=y[i]){
			z=x[i];
			x[i]=y[i];
			y[i]=z;
		}
	}
	for(a=0;a<i;a++){
		printf("%d %d\n",x[a],y[a]);
	}
	
	return 0;
}
