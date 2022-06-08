#include<stdio.h>
int main(){
    int i,n,a[10000],max,min;
    long sum=0;
    scanf("%d",&n);
    for(i=0;i<=n-1;i+=1){
        scanf("%d",&a[i]);
        sum=sum+a[i];
        if(i==0){
            max=a[0];
            min=a[0]; 
        }
        else if(min>a[i]){
            min=a[i];
        }
        else if(max<a[i]){
            max=a[i];
        }
    }
    printf("%d %d %ld\n",min,max,sum);
    return 0;
}