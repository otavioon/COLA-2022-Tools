
#include <vector>
#include <stdio.h>
#include <algorithm>
#include <iostream>
#include <string.h>
using namespace std;
typedef long long int ll;

int l[1000 + 10];
int sum[1000 + 10];
int main()
{
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        int temp;
        cin >> temp;
        l[temp]++;
    }
    for (int i = 1; i <= 1000; i++)
    {
        sum[i] = sum[i - 1] + l[i];
    }

    int ans = 0;
    for (int i = 1; i <= 1000; i++)
    {
        if (l[i] == 0)
            continue;
        for (int j = i + 1; j <= 1000; j++)
        {
            if (l[j] == 0)
                continue;
            int temp = i + j;
            temp--;
            int end;
            if (temp >= 1000)
                end = n;
            else
                end = sum[temp];

            ans += end - sum[j];
        }
    }

    cout << ans;

    return 0;
}