#include <stdio.h>
int main(){
    int a[100], n,i,max,min,sum=0;
    max=a[0];
    min=a[0];
    scanf("%d",&n);
    for(i = 0; i<n; i++){
        scanf("%d",&a[i]);
    }
    for(i=1; i<n; i++){
        if(min > a[i]){
            min=a[i];
        }if(max < a[i]){
        max=a[i];
        }
        sum += a[i];
    }
    printf("%d %d %d",min,max,sum);
    return 0;
} 