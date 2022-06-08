#include<stdio.h>
int main()
{
    int N,a[4][4],i,j;
    for(i=1;i<=3;i++)
    {
        for(j=1;j<=3;j++)
        {
            scanf("%d",&a[i][j]);
        }
    }
    if(a[1][1]+a[2][2]==a[1][2]+a[2][1]&&a[1][2]+a[2][3]==a[2][2]+a[1][3]&&a[2][1]+a[3][2]==a[3][1]+a[2][2]&&a[2][2]+a[3][3]==a[3][2]+a[2][3])
    {
        printf("Yes\n");
    }
    else
        printf("No\n");
}

