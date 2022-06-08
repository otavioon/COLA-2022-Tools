#include <stdio.h>

int main(void) {
    int n;
    int a[n];
    int min, max;
    long long int sum = 0;    
    scanf("%d", &n);
    for( int i = 0; i < n ; i++ ) {
        scanf("%d", &a[i]);
    }
    min = a[0];
    for( int i = 0; i < n ; i++ ) {
        if( min > a[i] )    min = a[i];
    }
    max = a[0];
    for( int i = 0; i < n ; i++ ) {
        if( max < a[i] )    max = a[i];
    }
    for( int i = 0; i < n ; i++ ) {
        sum = sum + a[i];
    }  
    printf("%d %d %lld\n", min, max, sum);
    return 0;
}
