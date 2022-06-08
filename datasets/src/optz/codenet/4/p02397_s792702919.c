#include<stdio.h>

int main(void)
{
    int a, b;
    for (;;) {
        scanf("%d %d", &a, &b);
        if ((a|b)==0) break;
        a+=b;
        b=a-b;
        a-=b;
        printf("%d %d\n", a, b);
    }
}

    
