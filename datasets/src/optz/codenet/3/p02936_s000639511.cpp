#include <bits/stdc++.h>

using namespace std;

int n,m;
int a[200001][2];
long long ans[200001];
int flag[200001];
int pos,val;
queue<int>s;

struct node
{
    int l,r;
}e[200000];

bool cmp(node a,node b)
{
    if(a.l == b.l)
        return a.r < b.r;
    return a.l < b.l;
}

int main()
{
    scanf("%d%d",&n,&m);
    for(int i = 1;i <= n - 1;i++)
    {
        scanf("%d%d",&e[i].l,&e[i].r);
    }
    sort(e + 1,e + n,cmp);
    for(int i = 1;i <= n - 1;i++)
    {
        if(a[e[i].l][0] == 0)
            a[e[i].l][0] = e[i].r;
        else
            a[e[i].l][1] = e[i].r;
    }
    for(int i = 1;i <= m;i++)
    {
        scanf("%d%d",&pos,&val);
        ans[pos] += val;
    }
    s.push(1);
    while(!s.empty())
    {
        int t = s.front();
        s.pop();
        if(a[t][0] > 0)
        {
            ans[a[t][0]] += ans[t];
            s.push(a[t][0]);
        }
        if(a[t][1] > 0)
        {
            ans[a[t][1]] += ans[t];
            s.push(a[t][1]);
        }
    }
    for(int i = 1;i < n;i++)
        printf("%lld ",ans[i]);
    printf("%lld\n",ans[n]);
    return 0;
}
