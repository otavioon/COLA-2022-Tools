#include <stdio.h>

int main(void)
{
    int i, x;
    int max, min, sum;

    scanf("%d", i);
    
    int num[i-1];

    for(x=0;x<i;i++){
        scanf("%d ", &num[x]);
    
        if(num[x] > max){ max = num[x];}
        if(num[x] < min){ min = num[x];}
        
        sum += num[x];
    }

    printf("%d %d %d\n", min, max, sum);
    return 0;
}  