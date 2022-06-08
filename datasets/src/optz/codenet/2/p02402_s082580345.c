#include<stdio.h>
int main(void){
    long long int n,a[10000],i,z,k=0;
        scanf("%d",&n);
        i=0;
        while(1){
        scanf("%d",&a[i]);
        i++;
        if(i==n)break;
        }
        i=0;
    while(1){
        if(a[i]>a[i+1]){
            z=a[i];
            a[i]=a[i+1];
            a[i+1]=z;
            z=0;
        }else break;
        i++;
        }
        i=0;
        while(1){
            k=k+a[i];
            if(i==n)break;
            i++;
        }
        printf("%d %lld %lld\n",a[0],a[n-1],k);
    return 0;
}