#include <iostream>
#include <stdio.h>

using namespace std;

int main()
{
    int c[5][5], sum = 0;
    for(int i = 1; i <= 3; i++)
    {
        for(int j = 1; j <= 3; j++)
        {
            scanf("%d", &c[i][j]);
            sum += c[i][j];
        }
    }
    int d;
    d = c[2][1] + c[3][1] + c[1][2] + c[1][3];
    if(3 * d == sum + 3 * c[1][1])
        printf("Yes\n");
    else
        printf("No\n");
    return 0;
}
