#include<bits/stdc++.h>
#define mem(a,v) memset(a,v,sizeof a)
#define ll long long
#define max(a,b) (a>b?a:b)
#define min(a,b) (a<b?a:b)
#define max3(x,y,z) max(x,max(y,z))
#define min3(x,y,z) min(x,min(y,z))
#define f first
#define s second
#define fr(i,n) for(int j=i;j<n;j++)
#define rev(a) reverse(a.begin(),a.end())
#define all(a) a.begin(),a.end()
#define rall(a) a.rbegin(),a.rend()
#define lb(a,v) lower_bound(all(a),v)
#define ub(a,v) upper_bound(all(a),v)
#define ins(v) insert(v)
#define pb(v) push_back(v)
#define sz(x) (int)(x).size()
#define MOD 1000000007
#define sf1(a) scanf("%d",&a)
#define sf2(a,b) scanf("%d %d",&a,&b)
#define sf3(a,b,c) scanf("%d %d %d",&a,&b,&c)
#define sf4(a,b,c,d) scanf("%d %d %d %d",&a,&b,&c,&d)
using namespace std;
const int N=1e6+5,M=1e7+5,oo=0x3f3f3f3f;
vector<int>adj[N];
ll cost[N];
bool vis[N];
set<int>st,t;
void init(int n)
{
	for(int i=1;i<=n;i++)
		st.ins(i);
}
void dfs1(int u,int v)
{
	if(u==v)return;
	vis[u]=1;
	t.erase(u);
	for(int x:adj[u])
		if(!vis[x])	dfs1(x,v);
}
int main() {
	int u,v,n,q;
    sf2(n,q);
    init(n);
    for(int i=0;i<n-1;i++)
    {
        sf2(u,v);
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    for(int i=0;i<q;i++)
    {
    	mem(vis,0);
        sf2(u,v);
        t=st;
        dfs1(1,u);
        for(int x:t)
        	cost[x]+=v;
    }
    for(int i=1;i<=n;i++)
        printf("%lld ",cost[i]);
    puts("");
    return 0;
}
