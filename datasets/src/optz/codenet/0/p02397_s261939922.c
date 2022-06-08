#include <stdio.h>
int main(void){
    int a,b;
    while(1){
         scanf("%d %d",&a,&b);
         if(a!=0 && b!=0 && a>=b)
         printf("%d %d\n",a,b);
         else if(a!=0 && b!=0 && a<b)
         printf("%d %d\n",b,a);
         if(a==0 && b==0){
             printf("\n");
         break;}
}
return 0;

}
