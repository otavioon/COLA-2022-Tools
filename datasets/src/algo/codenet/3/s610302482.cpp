#include <iostream>
#include <stdio.h>
#include <string.h>
#include <algorithm>

using namespace std;
const int maxn = 1e5 + 5;
int a[maxn], b[maxn], c[maxn];

int main()
{
    int n;
    long long sum = 0;
    scanf("%d", &n);
    for(int i = 0; i < n; i++)
        scanf("%d", &a[i]);
    for(int i = 0; i < n; i++)
        scanf("%d", &b[i]);
    for(int i = 0; i < n; i++)
        scanf("%d", &c[i]);
    sort(a, a + n);
    sort(b, b + n);
    sort(c, c + n);
    int l = 0, r = 0;
    for(int i = 0; i < n; i++)
    {
        while(l < n && a[l] < b[i])
            l++;
        while(r < n && c[r] <= b[i])
            r++;
        sum += l * (n - r);
    }
    printf("%lld\n", sum);
    return 0;
}
