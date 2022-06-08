#include<stdio.h>
       
int main() {
    
int a[3000], b[3000], i, t = 0;
       
for (i = 0; i < 3000; i ++)
 scanf ("%d" "%d",&a[i], &b[i]);
   
while (a[t] != 0 || b[t] != 0) {
   
if(a[i] >= b[i])
printf ("%d %d\n",a[i],b[i]);
   
if(b[i] > a[i])
 printf("%d %d\n",b[i],a[i]);
   
}
      
return 0;
       
}