#include <stdio.h>

int main()
{
     int n, i;
     scanf("%d", &n);

     int a[n+1], b[i];
     for(i = 0; i < n; i++){
          scanf("%d", &a[i]);
          b[i] = -1;
     }

     int count = 1;
     int nx = a[0];
     b[0] = a[0];

     while(nx != 2)
     {
          nx = a[nx - 1];
          for(i = count; i >= 0; i--)
               if(b[i] == nx){
                    printf("-1\n");
                    return 0;
               }
          b[count] = nx;
          count++;
     } 
     printf("%d\n", count);
     return 0;
}