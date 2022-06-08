#include <stdio.h>

int main(void){
    int i, j;
    int a[3], b[3];
    int c[3][3];
    for(i = 0;i < 3;i++) for(j = 0;j < 3;j++) scanf("%d", &c[i][j]);
    a[0] = c[0][0];
    a[1] = c[1][0];
    a[2] = c[2][0];
    b[0] = c[0][0] - a[0];
    b[1] = c[0][1] - a[0];
    b[2] = c[0][2] - a[0];
    if(c[1][1] == a[1] + b[1] && c[1][2] == a[1] + b[2] && c[2][1] == a[2] + b[1] && c[2][2] == a[2] + b[2]) puts("Yes");
    else puts("No");
    return 0;
}
