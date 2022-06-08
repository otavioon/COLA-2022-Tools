#include<stdio.h>
#include<algorithm>
#include<stdlib.h>
using namespace std;

int main(void){
  int i,j,k,n,m,s=0;
  int *a,*b,*c;

  scanf("%d",&n);

 a = (int *)calloc(n,sizeof(int));
 b = (int *)calloc(n,sizeof(int));
 c = (int *)calloc(n,sizeof(int));

  for(i=0;i<n;i++){
    scanf("%d",&a[i]);
  }
  sort(a,a+n);

  for(i=0;i<n;i++){
    scanf("%d",&b[i]);
  }

  for(i=0;i<n;i++){
    scanf("%d",&c[i]);
  }
  sort(c,c+n);

  for(i=0;i<n;i++){
    printf("a[%d] = %d c[%d]=%d\n",i,a[i],i,c[i]);
  }

  for(j=0;j<n;j++){
    for(i=0;i<n;i++){
      if(b[j]<=a[i]) break;
    }
    for(k=0;k<n;k++){
      if(b[j]<c[k]){k=n-k; break;}
    }
    printf("i = %d k = %d s=%d\n",i,k,s);
    s+= i*k;
  }

  printf("%d\n",s);


  free(a); free(b); free(c);
  return 0;
}
