#include<stdio.h>

int main() {
   
   int x,y,z,i=0;
   
   for (i=0; i<3000; i++) {
      scanf("%d%d\n",&x,&y);
      if (x == 0 && y == 0) {
         break;
      }
      if (x<y) {
         x=z;
         x=y;
         y=z;
      } 
         printf("%d %d\n",x,y);
      
   }

   return 0;
} 