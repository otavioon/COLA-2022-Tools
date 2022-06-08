#include <stdio.h>

int main(void){
	int i=0,j,fir[3000]={},sec[3000]={},n1,n2;
	do{
		scanf("%d %d",&n1,&n2);
		if(n1!=0 || n2!=0){
			fir[i] = n1;
			sec[i] = n2;
			i++;
		}
	}while(n1!=0 || n2!=0);
	
	for(j=0;j<i;j++){
		if(fir[j]<sec[j])
			printf("%d %d\n",fir[j],sec[j]);
		else
			printf("%d %d\n",sec[j],fir[j]);
	}
	return 0;
}