#include<bits/stdc++.h>
using namespace std;

int main()
{
    int c[3][3],sum=0,s1,s2;
    for(int i=0;i<3;i++)
    {
        for(int j=0;j<3;j++)
        {
            cin>>c[i][j];
            sum=sum+c[i][j];
        }
    }
    s1=c[0][0]+c[1][1]+c[2][2];
    s2=c[0][2]+c[1][1]+c[2][0];
    if(sum==s1*3 && sum==s2*3) cout<<"Yes\n";
    else cout<<"No\n";
    return 0;
}
