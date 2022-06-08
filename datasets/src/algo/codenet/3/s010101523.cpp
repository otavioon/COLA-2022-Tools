#include <bits/stdc++.h>

using namespace std;

typedef long long LL;
typedef unsigned long long ULL;
typedef pair<int, int> PII;

const int N = 100010, mod = 1e9 + 7;

int n;
int a[N], b[N], c[N];

int main()
{
    scanf("%d", &n);
    for(int i = 1; i <= n; i++) scanf("%d", a + i);
    for(int i = 1; i <= n; i++) scanf("%d", b + i);
    for(int i = 1; i <= n; i++) scanf("%d", c + i);
    sort(a + 1, a + 1 + n);
    sort(b + 1, b + 1 + n);
    sort(c + 1, c + 1 + n);

    LL res = 0;
    for(int i = 1; i <= n; i++)
    {
        int x, y;
        int l = 0, r = n;
        while(l < r)
        {
            int mid = l + r + 1 >> 1;
            if(a[mid] < b[i]) l = mid;
            else r = mid - 1;
        }
        x = r;

        l = 0, r = n;
        while(l < r)
        {
            int mid = l + r >> 1;
            if(c[mid] > b[i]) r = mid;
            else l = mid + 1;
        }
        y = n - r + 1;

        res += (LL)x * y;
    }

    printf("%lld\n", res);
    return 0;
}
