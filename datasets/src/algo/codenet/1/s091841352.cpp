#include<iostream>
#include<cstdio>
#include<string>
#include<cstring>
#include<algorithm>
#include<cmath>
#include<stack>
#include<set>
#include<map>
#include<vector>
#include<queue>
#define N 10
typedef long long ll;
using namespace std;
int a[N][N];
int main()
{
   int ans;
    for(int i=1;i<=3;i++)
        for(int j=1;j<=3;j++)
      cin>>a[i][j];
     ans=a[1][1]+a[2][2]+a[3][3];
    if(a[1][2]+a[2][3]+a[3][1]!=ans||a[1][3]+a[2][1]+a[3][2]!=ans)
    {
        cout << "No" << endl;
        return 0;
    }
    if(a[1][1]+a[2][3]+a[3][2]!=ans||a[1][2]+a[2][1]+a[3][3]!=ans||a[1][3]+a[2][2]+a[3][1]!=ans)
    {
        cout << "Yes" << endl;
        return 0;
    }
   cout << "Yes" << endl;
    return 0;
}
