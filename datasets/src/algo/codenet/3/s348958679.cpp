#include<stdio.h>
#include<algorithm>
#include<stdlib.h>
using namespace std;

int search(int a[],int x,int n,int c){
  int low=0;
  int hig=n-1;
  int mid;

  while(low<hig){
    mid=(low+hig)/2;
    if(a[mid]<x) low = mid+1;
    else hig = mid;
  }
 if(a[mid+1]==x) return mid+c;
  if(a[mid]>x) return mid -1;
  return mid;
}


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

  


  for(j=0;j<n;j++){
    if(a[n-1]<b[j]) i=n;
    else{
      i = search(a,b[j],n,0)+1;
    }
    if(b[j]<c[0]) k=n;
    else{
      k = n - search(c,b[j],n,1)-1;
    }
    s+= i*k;
  }

  printf("%d\n",s);


  free(a); free(b); free(c);
  return 0;
}
