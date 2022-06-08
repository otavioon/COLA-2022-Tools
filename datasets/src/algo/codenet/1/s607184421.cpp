#include <stdio.h>
                                                                                                
  
int main(void){
                                                                                                
   
    int i, j;

    int a[3];

    int b[3];

    int c[3][3];
   
      
    for( i = 0 ; i < 3 ; i = i + 1){

        for( j = 0 ; j < 3 ; j = j + 1 ){

             scanf("%d", &c[i][j]);

             }

        }


    a[0] = 0;

    for( i = 0 ; i < 3 ; i = i + 1 ){

         b[i] = c[0][i];

         }

    for( i = 1 ; i < 3 ; i = i + 1 ){

         a[i] = c[i][0] - c[0][0];

         }


    for( i = 0 ; i < 3 ; i = i + 1 ){

        for( j = 0 ; j < 3 ; j = j + 1 ){

             if( c[i][j] != a[i] + b[j] ){

                 printf("No\n");

                 return 0;

                 }

             }

        }


    printf("Yes\n");


    return 0;
                                                          
}