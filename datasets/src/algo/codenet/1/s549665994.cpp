#include <bits/stdc++.h>
using namespace std;
int main()
{
    int a = 0, s = 0;
    for (int i = 0; i < 9; i++)
    {
        cin >> a;
        s += a;
    }
    if (s % 3 == 0)
    {
        cout << "Yes" << endl;
    }
    else
    {
        cout << "No" << endl;
    }
    return 0;
}