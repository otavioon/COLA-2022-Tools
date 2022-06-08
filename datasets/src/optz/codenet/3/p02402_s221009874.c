#include <stdio.h>
int main(void)
{
   
    int n,x,max,min,sum,i;
    scanf("%d",&n);
    for(i=1; i<=n; i++){
        scanf("%d",&x);
        sum += x;
        if(i==1){
            max = x;
            min = x;
        }
            else if(x>max){
                max = x;
            
            }
            else if(x<min){
                min = x;
            }
        
        
    }
    printf("%d %d %d",max,min,sum);
    return 0;
    
}

