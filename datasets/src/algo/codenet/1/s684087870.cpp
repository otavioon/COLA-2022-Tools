#include <cstdio>

int main() {
    int a[3], b[3];
    int c[3][3];

    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            scanf("%d", &c[i][j]);
        }
    }
    a[0] = 0;
    for (int i = 0; i < 3; i++) {
        b[i] = c[0][i];
    }
    for (int i = 1; i < 3; i++) {
        a[i] = c[i][0]-b[0];
    }

    for (int i = 1; i < 3; i++) {
        for (int j = 1; j < 3; j++) {
            if (c[i][j] != a[i] + b[j]) {
                printf("No");
                return 0;
            }
        }
    }
    printf("Yes");
    return 0;
}