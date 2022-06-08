#include <stdio.h>

int main()
{
    int v[1000][2];
    int i = 0, j;
    int temp;

    do{
       scanf("%d %d", &v[i][0], &v[i][1]);
       if (v[i][0] > v[i][1])
       {
           temp = v[i][0];
           v[i][0] = v[i][1];
           v[i][1] = temp;
       }
       i++;
    }while(v[i - 1][0] != 0 || v[i - 1][1] != 0);

    for (j = 0; j < i - 1; j++)
    {
         printf("%d %d\n", v[j][0], v[j][1]);
    }

    return 0;
}