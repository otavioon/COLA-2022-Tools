#include <bits/stdc++.h>
using namespace std;
int main()
{
    int a[4][4];
    for(int i=1;i<=3;i++)
        for(int j=1;j<=3;j++)
        scanf("%d",&a[i][j]);
       int n1=a[3][1]-a[2][1];
       int n2=a[3][2]-a[2][2];
       int n3=a[3][3]-a[2][3];
       int n4=a[1][1]-a[2][1];
       int n5=a[1][2]-a[2][2];
       int n6=a[1][3]-a[2][3];
       bool flag=true;
       if(n1!=n2 || n2!=n3 || n3!=n4 || n4!=n5 || n5!=n6) flag=false;
//       cout<<n1<<" "<<n2<<" "<<" "<<n3<<" "<<n4<<" "<<n5<<" "<<n6<<endl;
       if(flag) cout<<"Yes"<<endl;
       else cout<<"No"<<endl;

}
