#include<bits/stdc++.h>
using namespace std;
const  int maxn=2e5+7;
typedef long long ll;
struct Node
{
    int next,v;
}node[maxn];
struct Tree
{
    int l,r;
    ll w,f;
}tree[maxn*4];
int tot;
bool flag;
int rk[maxn];
int head[maxn];
int fa[maxn];
int son[maxn];
int siz[maxn];
int dep[maxn];
int tim;
int dfn[maxn];
int top[maxn],w[maxn];
void add(int u,int v)
{
    node[tot].next=head[u];
    node[tot].v=v;
    head[u]=tot++;
}
void dfs1(int u,int f)
{
    fa[u]=f;
    dep[u]=dep[f]+1;
    siz[u]=1;
    int maxsiz=-1;
    for(int i=head[u];~i;i=node[i].next)
    {
        int to=node[i].v;
        if(to==f) continue;
        dfs1(to,u);
        siz[u]+=siz[to];
        if(siz[to]>maxsiz||siz[to]==maxsiz&&to<son[u])
        {
            maxsiz=siz[to];
            son[u]=to;
        }
    }
}
void dfs2(int u,int f)
{
    dfn[u]=++tim;
    top[u]=f;
    //rk[tim]=u;
    if(!son[u]) return;

    dfs2(son[u],f);
    for(int i=head[u];~i;i=node[i].next)
    {
        int to=node[i].v;
        if(to==fa[to]||to==son[u]) continue;
            dfs2(to,to);
    }

}
int cot;
void build(int k,int l,int r)
{
    tree[k].l=l,tree[k].r=r;
    if(l==r)
    {
        tree[k].w=0;
        return ;
    }
    int mid=(l+r)/2;
    build(k<<1,l,mid);
    build(k<<1|1,mid+1,r);
    tree[k].w=tree[k<<1].w+tree[k<<1|1].w;
}
void down(int k)
{
    tree[k<<1].w+=tree[k].f*(tree[k<<1].r-tree[k<<1].l+1);
    tree[k<<1|1].w+=tree[k].f*(tree[k<<1|1].r-tree[k<<1|1].l+1);

    tree[k<<1].f+=tree[k].f;
    tree[k<<1|1].f+=tree[k].f;

    tree[k].f=0;
}
void update(int k,int l,int r,int w)
{
    if(tree[k].l>=l&&tree[k].r<=r)
    {
        tree[k].w+=w*(tree[k].r-tree[k].l+1);
        tree[k].f+=w;
        return;
    }
    if(tree[k].f) down(k);
    int mid=(tree[k].l+tree[k].r)>>1;
    if(l<=mid) update(k<<1,l,r,w);
    if(r>mid) update(k<<1|1,l,r,w);
    tree[k].w=(tree[k<<1].w+tree[k<<1|1].w);
}
void query(int k)
{
    if(tree[k].l==tree[k].r)
    {
        if(!flag)
            printf("%lld",tree[k].w);
        else
            printf(" %lld",tree[k].w);
        flag=true;
        return  ;
    }
    down(k);
    query(k<<1);
    query(k<<1|1);
}
int main()
{
    int n,m,u,v;
    scanf("%d%d",&n,&m);
    for(int i=0;i<=n+1;i++) head[i]=-1;
    for(int i=1;i<n;i++)
    {
        scanf("%d%d",&u,&v);
        add(u,v);
        add(v,u);
    }
    dfs1(1,1);
    dfs2(1,1);
    build(1,1,n);
    int x,w;
    for(int i=1;i<=m;i++)
    {
        scanf("%d%d",&x,&w);
        update(1,dfn[x],dfn[x]+siz[x]-1,w);
    }
    query(1);
}
