#include<bits/stdc++.h>
using namespace std;
int main() {
    int c[3][3];
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            cin >> c[i][j];
        }
    }

    int a[3], b[3];
    for (int i = 0; i < 3; i++)
    {
        b[i] = c[0][i];
    }
    for (int i = 0; i < 3; i++)
    {
        a[i] = c[i][0] - b[0];
    }

    bool ok = true;
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            if(a[i] + b[j] != c[i][j]) ok = false;
        }
    }

    if(ok) cout << "Yes" << endl;
    else cout << "No" << endl;
}