#include<stdio.h>
  
#define MAX_COUNT 10000
#define MIN_COUNT 1
  
#define MAX_VALUE 1000000
#define MIN_VALUE -1000000
  
#define IS_ERR_COUNT(n) (n < MIN_COUNT || n > MAX_COUNT)
#define IS_ERR_VALUE(n) (n < MIN_VALUE || n > MAX_VALUE)
  
int main(void)
{
  
    long long int n, i, d, min, max, sum;
    min = MAX_VALUE + 1;
    max = MIN_VALUE - 1;
    sum = 0;
  
    scanf("%lld", &n);
  
    if(IS_ERR_COUNT(n)) return -1;
  
    for(i=0;i<n;i++)
    {
        scanf("%lld", &d);
  
        if(IS_ERR_VALUE(d)) return -1;
  
        if(min > d) min = d;

        if(max < d) max = d;

        sum += d;
    }
  
    printf("%d %d %lld\n", min, max, sum);
  
    return 0;
}
