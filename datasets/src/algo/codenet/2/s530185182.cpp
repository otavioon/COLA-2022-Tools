#include <bits/stdc++.h>
using namespace std;

int a[200005], vis[200005];

int main()
{
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
        scanf("%d", a + i);
    sort(a, a + n);
    int upper = 1, answer = 0;
    while (upper <= a[n - 1])
        upper <<= 1;
    for (int i = n - 1; ~i; i--)
    {
        while (upper > a[i])
            upper >>= 1;
        upper <<= 1;
        int t = lower_bound(a, a + i, upper - a[i]) - a;
        if (a[t] == upper - a[i])
        {
            while (a[t + 1] == upper - a[i] && vis[t] == true)
                t++;
            if (vis[t])
                continue;
            vis[t] = vis[i] = true;
            answer++;
        }
    }
    printf("%d\n", answer);
    return 0;
}