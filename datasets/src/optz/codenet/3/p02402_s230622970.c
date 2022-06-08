#include <stdio.h>
int main(void){
      int n,x,min,max,i,sum;
   scanf("%d",&n);
   0<n<=10000;
   for(i=0;i<n;i++){
      scanf("%d",&x);
       sum += x;
       if(i==0){
           max=x;
           min=x;
       }
       else if(x>=max){
           max=x;
       }
       else if(x<=min){
           min=x;
       }
   }
printf("%d %d %d\n",min,max,sum);

  return 0;

}
