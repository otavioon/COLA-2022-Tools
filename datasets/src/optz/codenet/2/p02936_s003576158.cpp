#include <bits/stdc++.h>
using namespace std;
const int N = 200005;

int n;
vector<int> a[N];
int g[N];

int ans[N];
void dfs(int x, int p, int gg)
{
    gg += g[x];
    ans[x] = gg;
    for (int i = 0; i < a[x].size(); ++i)
    {
        int h = a[x][i];
        if (h == p)
            continue;
        dfs(h, x, gg);
    }
}

int main()
{
    scanf("%d", &n);
    int q;
    scanf("%d", &q);
    for (int i = 0; i < n - 1; ++i)
    {
        int x, y;
        scanf("%d%d", &x, &y);
        a[x].push_back(y);
        a[y].push_back(x);
    }
    while (q--)
    {
        int x, y;
        scanf("%d%d", &x, &y);
        g[x] += y;
    }
    dfs(1, 1, 0);
    for (int i = 1; i <= n; ++i)
        printf("%d ", ans[i]);
    printf("\n");
    return 0;
}
