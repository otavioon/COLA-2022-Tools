#include<stdio.h>

int main(void)
{
    int a, b, i;
    for (i=0; i<3000; i++) {
        scanf("%d %d", &a, &b);
        if ((a|b)==0) break;
        a+=b;
        b=a-b;
        a-=b;
        printf("%d %d\n", a, b);
    }
}

    
