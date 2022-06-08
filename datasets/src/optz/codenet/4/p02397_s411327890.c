#include<stdio.h>

int main(){
    int x,y;
    do{
    scanf("%d",&x);
    scanf("%d",&y);
    
    if(x == 0 && y == 0){
        break;
    }
    if(x > y){
       x = x - y;
       y = x + y;
       x = y - x;
    }
    printf("%d"" ""%d\n",x,y);
    }while(x != 0 || y!= 0);
  
    return 0;
}