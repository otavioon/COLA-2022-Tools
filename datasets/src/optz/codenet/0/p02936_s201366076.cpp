/*Program from Luvwgyx*/
#include<cmath>
#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
#define int long long
#define write(x) printf("%lld\n",x)
using namespace std;
const int maxn=2e5+10;
int tot,head[maxn],f[maxn];
struct node{int to,nxt;}e[maxn<<1];
int read(){
    int x=0,f=1;char ch=getchar();
    while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
    while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
    return x*f;
}
void add(int u,int v){e[++tot].to=v;e[tot].nxt=head[u];head[u]=tot;}
void insert(int u,int v){add(u,v);add(v,u);}
void dfs(int x,int fa){
    for(int i=head[x],v=e[i].to;i;i=e[i].nxt,v=e[i].to)
        if(v!=fa)f[v]+=f[x],dfs(v,x);
}
signed main(){
    int n=read(),Q=read();
    for(int i=1;i<n;i++)insert(read(),read());
    while(Q--){int x=read(),y=read();f[x]+=y;}dfs(1,0);
    for(int i=1;i<=n;i++)printf("%lld ",f[i]);puts("");
    return 0;
}
