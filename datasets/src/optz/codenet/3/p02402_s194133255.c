#include <stdio.h>

int main(void){
	long n,a,i,min,max;
	long sum=0;
	scanf("%d",&n);
	for(i=0;i<n;i++){
		scanf("%d",&a);
		sum+=a;
		if(i==0){
			min=a;
			max=a;
		}else if(a>max){
			max=a;
		}else if(a<min){
			min=a;
		}
	}
	printf("%d %d %d\n",min,max,sum);
	return 0;
}