#include<stdio.h>        
int main() {
       
int a[3000], b[3000], i, t = 0;
          
for (i = 0; i < 3000; i ++)
 scanf ("%d" "%d", &a[i], &b[i]);
      
while (a[t] != 0 || b[t] != 0) {
      
if(a[t] >= b[t])
printf ("%d %d\n",a[t],b[t]);
      
if(b[t] > a[t])
 printf("%d %d\n",b[t],a[t]);
      
t = t + 1;
  
}
         
return 0;
          
}