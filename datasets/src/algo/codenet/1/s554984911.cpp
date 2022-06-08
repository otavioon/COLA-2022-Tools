#include <bits/stdc++.h>
using namespace std;
double a[10][10];
int main()
{
    for(int k = 1;k <= 3;k++)
        for(int j = 1;j <= 3;j++)
            cin >> a[k][j];
    if(a[1][2] + a[2][3] + a[3][1] + a[1][3] + a[2][1] + a[3][2] == (a[1][1] + a[2][2] + a[3][3]) * 2)
        cout << "Yes";
    else
        cout << "No";
    return 0;
}