#include <bits/stdc++.h>

using namespace std;

typedef long long LL;
typedef unsigned long long ULL;
typedef pair<int, int> PII;

const int N = 100010, mod = 1e9 + 7;

int n;
int a[N], b[N], c[N];
LL sum[N], cnt[N];

int main()
{
    scanf("%d", &n);
    for(int i = 1; i <= n; i++) scanf("%d", a + i);
    for(int i = 1; i <= n; i++) scanf("%d", b + i);
    for(int i = 1; i <= n; i++) scanf("%d", c + i);
    sort(a + 1, a + 1 + n);
    sort(b + 1, b + 1 + n);
    sort(c + 1, c + 1 + n);

    for(int i = 1, j = 1; i <= n; i++)
    {
        while(j <= n && b[i] >= c[j]) j++;
//        if(j > n) break;
        cnt[i] = n - j + 1;
    }

    for(int i = 1; i <= n; i++) sum[i] = sum[i - 1] + cnt[i];

    LL res = 0;
    for(int i = 1, j = 1; i <= n; i++)
    {
        while(j <= n && a[i] >= b[j]) j++;
//        if(j > n) break;
        res += sum[n] - sum[j - 1];
    }

    printf("%lld\n", res);
    return 0;
}
