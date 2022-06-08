#include <stdio.h>

int main(void){
    int n,i;
    long num,min,max,sum=0;
    scanf("%d",&n);
    for(i=0;i<n;i++){
        scanf("%ld",&num);
        sum+=num;
        if(i==0){
            min=num;
            max=num;
            continue;
        }
        if(num<min)
            min=num;
        else if(num>max)
            max=num;
    }
    printf("%ld %ld %ld\n",min,max,sum);
    return 0;
}