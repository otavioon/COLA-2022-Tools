#include <stdio.h>

int i, a, b;

int main() {
    while (1) {
        scanf("%d %d", &a, &b);
        if (a == 0 && b == 0) break;
        if (a > b) {
            a ^= b, b ^= a, a ^= b;
        }
        printf("%d %d\n", a, b);
    }
}
