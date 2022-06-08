#include<stdio.h>
int main(void){
	int m,n,ai,min,max,sum;
	scanf("%d",&n);
	for(m=0;m<n;m++){
		scanf("%d",&ai);
		if(m==0){
			min=ai;
			max=ai;
			sum=ai;
		}
		else{
			if(ai<min){
				min=ai;
			}
			if(max<ai){
				max=ai;
			}
			sum+=ai;
		}
	}
	printf("????°????%d,?????§???%d,????¨????%d\n",min,max,sum);
	return 0;
}