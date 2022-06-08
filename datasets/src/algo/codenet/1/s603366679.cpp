#include <bits/stdc++.h>

using namespace std;

int c[5][5],s;

int main()
{
    for (int i = 1; i <= 3; i++)
        for (int j = 1; j <= 3; j++)
        {
            cin >> c[i][j];
            s+=c[i][j];
        }
    if (s==3*(c[1][2]+c[2][3]+c[3][1])) cout << "Yes";
    else cout << "No";
}