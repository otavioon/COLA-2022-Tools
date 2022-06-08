#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    int c[3][3];
    for (int i=0;i<9;i++)
        cin>>c[i/3][i%3];
    int d[2]={c[0][1]-c[0][0],c[0][2]-c[0][1]};
    int f=1;
    for (int i=1;i<3;i++)
        for (int j=0;j<2;j++)
            f&=c[i][j+1]-c[i][j]==d[j];
    if (f)
        puts("Yes");
    else
        puts("No");
    return 0;
}