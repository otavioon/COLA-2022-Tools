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
    for(int i = 0; i < n; i++)
        scanf("%lld", &a[i]);
    for(int i = 0; i < n; i++)
        scanf("%lld", &b[i]);
    for(int i = 0; i < n; i++)
        scanf("%lld", &c[i]);
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