#include<stdio.h>
int main(void){
  int n,data=0;
  scanf("%d",&n);
  if(0<n&&n<=10000){
    int a[n],i;
    for(i=0;i<n;i++){
      a[i]=0;
      if(scanf("%d",&a[i])==1){
        if(-1000000>a[i]||a[i]>1000000)
        return 0;
         data+=a[i];
      }
    }
    int key,j;
    for(i=1;i<n;i++){
      key=a[i];
      for(j=i-1;j>=0;j--){
        if(key>a[j])
          a[j+1]=a[j];
        else
          j--;
          break;
      }
      a[j+1]=key;
    }
    printf("%d %d %d\n",a[0],a[n],data);
  }
  return 0;
}