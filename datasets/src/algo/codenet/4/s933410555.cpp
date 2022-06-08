#include <set>
#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n, k;
    cin >> n >> k;
    int tmp = n;
    int d[n];
    for (int i = 0; i < k; i++)
    {
        cin >> d[i];
    }
    while (1)
    {
        set<int> s;
        while (tmp != 0)
        {
            s.insert(tmp % 10);
            tmp /= 10;
        }
        bool flag = true;

        for (int i = 0; i < k; i++)
        {
            if (s.count(d[i]) == 1)
            {
                flag = false;
            }
        }
        if (flag)
        {
            cout << n << endl;
            break;
        }
        n++;
        tmp = n;
    }
    return 0;
}