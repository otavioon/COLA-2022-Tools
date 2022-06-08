#include <stdio.h>
int main(void){
    int i,a,b;
    for(i=0;i<3000;i++){
        scanf("%d %d",&a,&b);
        if(a*b==0){
                break;
        }else if(a<=b){
            printf("%d %d\n",a,b);
        }else{
            printf("%d %d\n",b,a);
        }
        
    }
    return 0;
}