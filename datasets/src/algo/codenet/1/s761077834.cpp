#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
    int a[3][3],i,j;
    bool c;
    for(j=0;j<3;j++)
        for(i=0;i<3;i++)
            cin>>a[i][j];
    c=(a[0][0]+a[1][1]==a[0][1]+a[1][0])&&(a[0][0]+a[2][2]==a[0][2]+a[2][0])&&(a[2][2]+a[1][1]==a[2][1]+a[1][2]);
    cout <<(c?"Yes":"No")<< endl;
    return 0;
}