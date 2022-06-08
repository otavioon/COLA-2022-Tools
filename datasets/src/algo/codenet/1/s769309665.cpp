#include<stdio.h>
#include <algorithm>
using namespace std;
int main()
{
    int a1,a2,a3,b1,b2,b3,flag,m[5][5];
   for(int i=1;i<=3;i++)
    for(int j=1;j<=3;j++)
    scanf("%d",&m[i][j]);
 
for(int a1=0;a1<100;a1++)
{
     int b1=m[1][1]-a1;
        int a2=m[2][1]-b1;
        int a3=m[3][1]-b1;
        int b2=m[1][2]-a1;
        int b3=m[1][3]-a1;
        if(a2+b2==m[2][2] 
            && a2+b3==m[2][3]
            && a3+b2==m[3][2] 
            && a3+b3==m[3][3])
        {
            flag = 1;
            break;
        }
}
if(flag)
printf("Yes");
else
printf("No");
    return 0;
}