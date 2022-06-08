#include<stdio.h>
int a[5][5];
int row[5],col[5];
int main()
{
    int i,j;
    int sum = 0;
    for(i=1;i<=3;i++)
        for(j=1;j<=3;j++){
            scanf("%d",&a[i][j]);
            row[i]+=a[i][j];
            col[j]+=a[i][j];
        }
    sum = row[1] + row[2] + row[3];
    if(sum%3)return printf("No")*0;
    int a1a2a3b1b2b3 = sum/3;
    int a1_a2 = row[1] - row[2];
    int a1_a3 = row[1] - row[3];
    int b1_b2 = col[1] - col[2];
    int b1_b3 = col[1] - col[3];
    if(a1_a2%3 + a1_a3%3 + b1_b2%3 + b1_b3%3)return printf("No")*0;
    printf("Yes");
}