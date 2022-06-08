#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <string.h>
using namespace std;

const int N = 1e5+10;;
int a[N], b[N], c[N];
int main ()
{
    int n;
    scanf("%d", &n);
    for(int i = 0; i < n; i++)
    {
        scanf("%d", &a[i]);
    }
    for(int i = 0; i < n; i++)
    {
        scanf("%d", &b[i]);
    }
    for(int i = 0; i < n; i++)
    {
        scanf("%d", &c[i]);
    }
    sort(a, a+n);
    sort(b, b+n);
    sort(c, c+n);
    long long ans = 0;
    for(int i = 0, j = 0, k = 0; i < n; i++)
    {
        while(b[i]>a[j] && j <= n-1)
        {
            j++;
        }
        while(b[i]>=c[k] && k <= n-1)
        {
            k++;
        }
        ans += (long long )j * (n-k);
    }
    printf("%lld\n", ans);
    return 0;
}