#include <iostream>
#include <stdio.h>
#include <string.h>
#include <algorithm>

using namespace std;
const int maxn = 1e6 + 5;
int a[maxn], b[maxn], c[maxn];

int main()
{
    int n;
    long long sum = 0;
    scanf("%d", &n);
    for(int i = 1; i <= n; i++)
        scanf("%d", &a[i]);
    for(int i = 1; i <= n; i++)
        scanf("%d", &b[i]);
    for(int i = 1; i <= n; i++)
        scanf("%d", &c[i]);
    sort(a + 1, a + n + 1);
    sort(b + 1, b + n + 1);
    sort(c + 1, c + n + 1);
    int l = 1, r = 1;
    for(int i = 1; i <= n; i++)
    {
        while(l <= n && a[l] < b[i])
            l++;
        while(r <= n && c[r] <= b[i])
            r++;
        sum += (l - 1) * (n - r + 1);
    }
    printf("%lld\n", sum);
    return 0;
}
