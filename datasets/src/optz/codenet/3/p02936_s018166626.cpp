#include <bits/stdc++.h>

using namespace std;
typedef long long ll;


const int N=2e5+100;

int cnt[N];
struct edge
{
    int to,next;
}ed[N*2];

int head[N];
int tot=1;

void add_edge(int u,int v)
{
    ed[tot].to=v;
    ed[tot].next=head[u];
    head[u]=tot++;
}

void bfs()
{
    queue<int>q;q.push(1);
    while(q.size()){
        int k=q.front();q.pop();
        for(int i=head[k];i;i=ed[i].next){
            int kk=ed[i].to;
            cnt[kk]+=cnt[k];
            q.push(kk);
        }
    }
}

int main()
{
    int n,m;
    int u,v;
    scanf("%d%d",&n,&m);
    for(int i=1;i<n;i++){
        scanf("%d%d",&u,&v);
        add_edge(u,v);
    }
    for(int i=1;i<=m;i++){
        scanf("%d%d",&u,&v);
        cnt[u]+=v;
    }
    bfs();
    for(int i=1;i<=n;i++){
        printf("%d ",cnt[i]);
    }
    return 0;
}
