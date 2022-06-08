#include<stdio.h>
#define DATA_NUM 3000
int main(){
    int i;
    int temp;
    int x[DATA_NUM],y[DATA_NUM];
    
    for(i=0;i<DATA_NUM;i++){
        scanf("%d %d",&x[i],&y[i]);
        if(x[i]==0 && y[i]==0){
            break;
        }
    }
    
    for(i=0;i<DATA_NUM;i++){
        if(x[i]==0 && y[i]==0){
            break;
        }
        if(x[i]>y[i]){
            temp = x[i];
            x[i] = y[i];
            y[i] = temp;
        }
    }
    
    for(i=0;i<DATA_NUM;i++){
        if(x[i]==0 && y[i]==0){
            break;
        }
        printf("%d %d\n",x[i],y[i]);
    }
    return 0;
}
