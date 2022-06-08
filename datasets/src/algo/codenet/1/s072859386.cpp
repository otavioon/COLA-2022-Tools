#include<bits/stdc++.h>
using namespace std;
int mapp[3][3];
int main()
{
for(int i=0;i<3;i++)
{
    for(int j=0;j<3;j++)
    {  
       cin>>mapp[i][j];
    }
}
int sum1=mapp[0][0]+mapp[1][1]+mapp[2][2];
int sum2=mapp[0][1]+mapp[1][2]+mapp[2][0];
int sum3=mapp[1][0]+mapp[2][1]+mapp[0][2];
if(sum1==sum2&&sum2==sum3)
       cout<<"Yes"<<endl;
else
       cout<<"No"<<endl;
return 0;
}