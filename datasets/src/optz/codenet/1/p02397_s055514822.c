
#include<stdio.h>

int main(){

    int a,b,i,j;

    for(i=0;i<3000;i++){
        scanf("%d %d",&a,&b);
        if((a==0)&&(b==0)) break;
        if(a>b){
            j = a;
            a = b;
            b = j;
        }
        printf("%d %d\n",a,b);


    }

        return 0;


}

