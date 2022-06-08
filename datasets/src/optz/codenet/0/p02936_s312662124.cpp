#include<bits/stdc++.h>

using namespace std;

#define S scanf
#define P printf
#define G getline
#define SZ size()
#define C clear()
#define B begin()
#define F front()
#define T top()
#define E end()
#define EM empty()
#define V vector
#define Q queue
#define DQ deque
#define PQ priority_queue
#define ST stack
#define FI first
#define SE second
#define PI acos(-1)
#define PS push
#define PP pop()
#define PSF push_front
#define PSB push_back
#define PPF pop_front()
#define PPB pop_back()
#define MP make_pair
#define LL long long int
#define ULL unsigned long long int
#define PII pair<int,int>
#define PSI pair<string,int>
#define PIS pair<int,string>
#define PLI pair<long long int,int>
#define PLL pair<long long int,long long int>
#define MII map<int,int>
#define MSI map<string,int>
#define MIS map<int,string>
#define MLI map<long long int,int>
#define FAST() ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)





//int dx[]={-1,1,0,0};
//int dy[]={0,0,-1,1};
//int dx[]= {-1,0,1,-1,1,-1,0,1};
//int dy[]= {1,1,1,0,0,-1,-1,-1};




LL time_cnt,tmp[200005];
LL node[800005];
LL lazy[800005];
V<LL>adj[200005];
PII discovery_time[200005];

void run_dfs(LL node)
{
    if(discovery_time[node].FI)
    {
        return;
    }
    discovery_time[node].FI=++time_cnt;
    tmp[time_cnt]=node;
    for(int i=0; i<adj[node].SZ; i++)
    {
        run_dfs(adj[node][i]);
    }
    discovery_time[node].SE=time_cnt;
}

void update(LL node_num,LL start,LL end,LL x,LL y,LL value)
{
    if(lazy[node_num] != 0)
    {
        node[node_num]+=(end-start+1)*lazy[node_num];
        if(start != end)
        {
            lazy[node_num << 1]+=lazy[node_num];
            lazy[(node_num << 1)+1]+=lazy[node_num];
        }
        lazy[node_num]=0;
    }
    if(y < start  ||  x > end  ||  start > end)
    {
        return;
    }
    if(start >= x  &&  end <= y)
    {
        node[node_num]+=(end-start+1)*value;
        if(start != end)
        {
            lazy[node_num  << 1]+=value;
            lazy[(node_num << 1)+1]+=value;
        }
        return;
    }
    LL mid=(start+end) >> 1;
    update(node_num << 1,start,mid,x,y,value);
    update((node_num << 1)+1,mid+1,end,x,y,value);
    node[node_num]=node[2*node_num]+node[2*node_num+1];
}

LL query(LL node_num,LL start,LL end,LL x,LL y)
{
    if(y < start  ||  x > end  ||  start > end)
    {
        return 0;
    }
    if(lazy[node_num] != 0)
    {
        node[node_num]+=(end-start+1)*lazy[node_num];
        if(start != end)
        {
            lazy[2*node_num]+=lazy[node_num];
            lazy[2*node_num+1]+=lazy[node_num];
        }
        lazy[node_num]=0;
    }
    if(start >= x  &&  end <= y)
    {
        return node[node_num];
    }
    LL mid=(start+end)/2;

    return (query(2*node_num,start,mid,x,y) + query(2*node_num+1,mid+1,end,x,y));
}

int main()
{
    FAST();

//    freopen("input.txt","r",stdin);
//    freopen("input.txt","w",stdout);

    LL i,n,q,x,y;
    cin >> n >> q;
    for(i=1; i<n; i++)
    {
        cin >> x >> y;
        adj[x].PSB(y);
        adj[y].PSB(x);
    }
    run_dfs(1);
    while(q--)
    {
        cin >> x >> y;
        update(1,1,n,discovery_time[x].FI,discovery_time[x].SE,y);
    }
    LL res[n+2];
    for(i=1; i<=n; i++)res[tmp[i]]=query(1,1,n,i,i);
    for(i=1;i<=n;i++)cout<<res[i]<<" ";
    return 0;
}
