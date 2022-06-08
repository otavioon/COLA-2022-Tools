#include <iostream>
#include <stdio.h>
#include <string.h>
#include <algorithm>

using namespace std;
const int maxn = 1000005;
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
    int l = 0, r = 0;
    for(int i = 1; i <= n; i++)
    {
        while(l + 1 <= n && a[l + 1] < b[i])
            l++;
        while(r + 1 <= n && c[r + 1] <= b[i])
            r++;
        sum += l * (n - r);
    }
    printf("%lld\n", sum);
    return 0;
}
