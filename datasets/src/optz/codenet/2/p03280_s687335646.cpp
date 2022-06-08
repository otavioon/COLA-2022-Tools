#include <iostream>
#include <cstdio>
#include <string>
#include <sstream>
#include <algorithm>
#include <set>
#include <numeric>
#include <cmath>
#include <map>
#include <vector>
#include <queue>
#include <stack>
#include <cstring>
#include <queue>
#include <numeric>
#include <iomanip>
#define ll long long
using namespace std;
const int MAXN=5005;
int dist[MAXN],in[MAXN],out[MAXN];
vector<pair<int,int> > adj[MAXN];
int dikjstra(int *in,int *out){
    priority_queue<pair<int,int > > pq;
    memset(dist,0x3f3f3f,sizeof(dist));
     pq.push({0,1});
    dist[1]=0;
    
    while(!pq.empty()){
        int here=pq.top().second;
        int cost=-pq.top().first;
        if(here==1 && cost!=0)return cost;
        pq.pop();
        if(cost>dist[here])continue;
        for(int i=0;i<adj[here].size();i++){
            int there=adj[here][i].first;
            int w= adj[here][i].second;
            if(here == 1 && dist[there]>dist[here]+w && out[there]){
                dist[there]=dist[here]+w;
                pq.push({-dist[there],there});
            }
            else if(there==1 && in[here]){
                pq.push({-dist[here]-w,there});
            }
            else if(here!=1 && there!=1){
                if(dist[there] > dist[here]+w ){
                    dist[there]=dist[here]+w;
                    pq.push({-dist[there],there});
                }
            }
        }
    }
    return 2e9;
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n,m; cin>>n>>m;
    int ans=2e9;
    for(int i=1;i<=m;i++){
        int u,v,w1,w2;cin>>u>>v>>w1>>w2;
        adj[u].push_back({v,w1});
        adj[v].push_back({u,w2});
    //    if(u==1 || v==1)ans=min(ans,w1+w2);
    }
    for(int i=0;i<14;i++){
        memset(in,0,sizeof(in));
        memset(out,0,sizeof(out));
        for(int j=2;j<=n;j++){
            if(j&(1<<i)){
                in[j]=1;
            }
            else out[j]=1;
        }
        ans=min(ans,dikjstra(in,out));
        ans=min(ans,dikjstra(out,in));
    }
    cout<<ans;
    
    
    return 0;
}
