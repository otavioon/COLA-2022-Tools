#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <iostream>
using namespace std;

/* Name        : ??2?N?? 
 * Version     : 1.0
 * Date        : 2012-12-24
 * New         : Null
 * Description : 
 * State       : Design
 */
int main()
{
    int a[33]={1},Bit[33]={0};                   //???a[33]?????????????????????Bit[33]??????????a[]?? 
    int N;
    cin>>N;
    for(int i=0;i<N;i++)
    {
        for(int j=0;j<32;j++)                    //????a[0]?????????????a[32]?Bit[32]???????Bit[33]??? 
        {
            a[j]=2*a[j]+Bit[j];                  //????????????????? 
            if(a[j]>9)                           //???????????????????????????Bit??1 
            {
                a[j]=a[j]-10;
                Bit[j+1]=1;
            }
            else Bit[j+1]=0;                     //????Bit??0??????????????????? 
        }
    }
    for(int i=31,Begin=0;i>=0;i--)               //????a[31]?????a[0]????????Begin?????????????0????? 
    {
        if(a[i]!=0)Begin=1;                      //???????0???Begin???1??????? 
        if(Begin==1)cout<<a[i];
    }
    cout<<endl;
    return 0;
}
