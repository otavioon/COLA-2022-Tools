#include <stdio.h>

int main(){
    
    int i,j = 0;
    long x[20000],y[20000];
    
    for(i = 0; i < 20000;i++){
        scanf("%ld %ld",&x[i],&y[i]);
        j++;
        if(x[i] == 0){
            if(y[i]==0){
                break;
            }
        }
    }
    
    for(i = 0; i < j-1; i++){
        if(x[i] < y[i]){
            printf("%ld %ld\n",x[i],y[i]);
        }else{
            printf("%ld %ld\n",y[i],x[i]);
        }
    }
    
    return 0;
    
}