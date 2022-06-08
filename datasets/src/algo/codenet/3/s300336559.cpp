#include <iostream>
#include <stdio.h>
#include <string.h>
#include <algorithm>

using namespace std;
const int maxn = 1e6 + 5;
long long a[maxn], b[maxn], c[maxn];

int main()
{
    long long n;
    long long sum = 0;
    scanf("%lld", &n);
    for(int i = 1; i <= n; i++)
        scanf("%lld", &a[i]);
    for(int i = 1; i <= n; i++)
        scanf("%lld", &b[i]);
    for(int i = 1; i <= n; i++)
        scanf("%lld", &c[i]);
    sort(a + 1, a + n + 1);
    sort(b + 1, b + n + 1);
    sort(c + 1, c + n + 1);
    long long l = 0, r = 0;
    for(int i = 1; i <= n; i++)
    {
        while(a[l + 1] < b[i] && l + 1 <= n)
            l++;
        while(c[r + 1] <= b[i] && r + 1 <= n )
            r++;
        sum += l * (n - r);
    }
    printf("%lld\n", sum);
    return 0;
}
