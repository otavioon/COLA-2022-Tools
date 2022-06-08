#include <stdio.h>
unsigned int n;
int i;
long a;
long max = -1000000;
long min = 1000000;
long sum = 0;

main(){
 scanf("%d",&n);
   if(n>0 && n<=10000){
   for(i= 0; i<n; i++){
 	scanf("%d ",&a);
 	if(a >= max){
 		max= a;
 	}
        if(a <= min){
 		min =a;
 	}
 	sum += a;
    }
   printf("%d %d %d \n",min,max,sum);
}

 return 0;
}