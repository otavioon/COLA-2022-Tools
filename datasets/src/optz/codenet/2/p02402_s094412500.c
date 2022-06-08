#include <stdio.h>
 int main (void){
 int i;
 int v;
 int a[v];
 int min;
 int max;
 int sum;
 int mem;
scanf ("%d",&i);
for (v=0; v<i; v++){
scanf ("%d",&a[v]);
}

for (v=0; v<i; v++){
if(v==0){
mem=a[v];
}if (v==i-1){
    if (mem>a[v]) mem=a[v];
}else
  if (mem>a[v+1]) mem=a[v+1];

} min=mem;


for (v=0; v<i; v++){
if(v==0){
mem=a[v];
}if (v==i-1){
    if (mem<a[v]) mem=a[v];
}else
  if (mem<a[v+1]) mem=a[v+1];

} max=mem;
sum=0;
for (v=0; v<i; v++){
sum=sum+a[v];
}
printf ("%d %d %d\n",min,max,sum);

return 0 ;
}