#include<stdio.h>
int main(){
    int x[30000],y[30000],i=0;

     while(1){
        scanf("%d%d",&x[i],&y[i]);
        if(x[i]==0&&y[i]==0){
            break;
        }
        i++;
    }

    i=0;

    while(x[i]!=0&&y[i]!=0||x[i]!=0&&y[i]==0||x[i]==0&&y[i]!=0){
        if(x[i]>y[i]){
            printf("%d %d\n",y[i],x[i]);
        }else{
            printf("%d %d\n",x[i],y[i]);
        }
        i++;
    }

    return 0;
}