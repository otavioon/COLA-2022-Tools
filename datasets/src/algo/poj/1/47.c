#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() 
{ 
     int row, col, i, j, temp_i, *a[100][100]; 
     scanf("%d%d", &row, &col); 
     for(i=0;i<row;i++) 
          for(j=0;j<col;j++) 
               {a[i][j]= (int *)malloc(sizeof(int));
               scanf("%d", a[i][j]); }
     for(j=0;j<col;j++)
     {
           for(i=0;i<=j&&i<row;i++) 
                 printf("%d\n", *a[i][j-i]); 
     } 
     for(i=1;i<row;i++)
     { 
           for(j=col-1,temp_i=i;j>=0&&temp_i<row;j--, temp_i++)
          { 
                 printf("%d\n", *a[temp_i][j]); 
           } 
     } 
     return 0; 
} 