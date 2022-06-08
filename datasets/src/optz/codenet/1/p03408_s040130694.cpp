#include<stdio.h>
int main()
{
    int i, max=0,n,m,j,x,k,flag;
    char s[101][11], t[101][11],a[11];
    scanf("%d", &n);
    for (i = 0; i < n; i++) {
        for (j = 0; j < 10; j++)
            a[j] = '\0';
        scanf("%s", a);
        for (j = 0; j < 10; j++)
            s[i][j] = a[j];
    }
    scanf("%d", &m);
    for (i = 0; i < m; i++) {
        for (j = 0; j < 10; j++)
            a[j] = '\0';
        scanf("%s", a);
        for (j = 0; j < 10; j++)
            t[i][j] = a[j];
    }
    for (i = 0; i < n; i++)
    {
        x = 0;
        for (j = 0; j < n; j++)
        {
            flag = 1;
            for (k = 0; k < 10; k++) {
                if (s[i][k] != s[j][k])
                    flag = 0;
            }
            if(flag==1)
                x++;
        }
        for (j = 0; j < m; j++)
        {
            flag = 1;
            for (k = 0; k < 10; k++) {
                if (s[i][k] != t[j][k])
                    flag = 0;
            }
            if (flag == 1)
                x--;
        }
        if (x > max)
            max = x;
    }
    printf("%d", max);
    return 0;
}