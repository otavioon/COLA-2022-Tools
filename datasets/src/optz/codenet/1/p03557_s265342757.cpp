#include <bits/stdc++.h>
 
using namespace std;
 
int n, a[3][100001], s;
 
int main()
{
    cin >> n;
    for (int i = 1; i <= 3; i++)
        for (int j = 1; j <= n; j++)
            cin >> a[i][j];
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
            for (int k = 1; k <= n; k++)
                if (a[1][i] < a[2][j] && a[2][j] < a[3][k]) s++;
    cout << s;
}