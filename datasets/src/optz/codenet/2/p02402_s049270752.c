#include <stdio.h>
int main(){
    int n,i, data[1000], min, max, sum=0;
    scanf("%d",&n);
    min = data[1];
    max = data[1];
    for(i=1;i<=n;i++){
        scanf("%d",&data[i]);
        sum += data[i];
        min = data[1];
        max = data[1];
        if(data[i]>max){
            max=data[i];
        }
        if(data[i]<min){
            min=data[i];
        }
    }
    printf("%d %d %d\n",min,max,sum);
    return 0;
}