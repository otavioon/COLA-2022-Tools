#include <iostream>
#include <stdio.h>
#include <string.h>
#include <algorithm>

using namespace std;
const int maxn = 1e5 + 5;
int a[maxn], b[maxn], c[maxn], nb[maxn];

int main()
{
    int n;
    long long sum = 0;
    scanf("%d", &n);
    for(int i = 0; i < n; i++)
        scanf("%d", &a[i]);
    sort(a, a + n);
    for(int i = 0; i < n; i++)
    {
        scanf("%d", &b[i]);
        nb[i] = n;
        for(int j = 0; j < n; j++)
        {
            if(a[j] >= b[i])
            {
                nb[i] = j;
                break;
            }
        }
    }
    for(int i = 0; i < n; i++)
    {
        scanf("%d", &c[i]);
        for(int j = 0; j < n; j++)
        {
            if(b[j] < c[i])
                sum += nb[j];
        }
    }
    printf("%lld\n", sum);
    return 0;
}
