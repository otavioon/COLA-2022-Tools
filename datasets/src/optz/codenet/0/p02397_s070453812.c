#include <stdio.h>

int main(){
    int i,x,y;
    for(i=1;i>0;i++){
        scanf("%d %d",&x,&y);
        if (x!=0 && y!=0 && x<=y) {
            printf("%d %d\n",x,y);
        }
        else if (x!=0 && y!=0 && x>y){
            printf("%d %d\n",y,x);
        }
        else break;
    }
    return(0);
}