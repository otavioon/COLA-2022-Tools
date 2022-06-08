#include <stdio.h>
#define N 10000
int main(void)
{
    int n, a[N], i, j, max, min, sum=0;
    
    scanf("%d", &n);
    
    for(i = 0; i < n; i++) {
        scanf("%d", &a[i]);
        sum = sum + a[i];
    }
    min = a[0];
    max = a[0];
    for(i = 0; i < n-1; i++) {
        if(a[i] > a[i+1]) {
            min = a[i+1];
        }
        if(a[i] < a[i+1]) {
            max = a[i+1];
        }
    }
    printf("%d %d %d\n", min, max, sum);
    return 0;
}