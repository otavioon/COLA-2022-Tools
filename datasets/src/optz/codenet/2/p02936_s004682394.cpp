#include<bits/stdc++.h>

#define rep(i,N) for(int i=0;i<N;i++)
#define rep2(i,N) for(int i=1;i<=N;i++)
using namespace std;
long long  INF=1e18;
long long mod=1e9+7;
long long weight[200010]={};
long long ans[200010];
bool reached[200010]={};
vector< vector<int>>edge(200010);

void bfs(int now, int before){
    reached[now]=true;

    if(before!=-1){
        ans[now]+=ans[before];
    }
    for(auto next:edge[now]){
        if(reached[next])continue;
        bfs(next,now);
    }

    return;
}

int main(){

    int n,q;
    cin>>n>>q;
    
    rep(i,n-1){
        int a,b;
        cin>>a>>b;
        a--,b--;
        edge[a].emplace_back(b);
        edge[b].emplace_back(a);

    }

    
    rep(i,q){
        int node,x;
        cin>>node>>x;
        node--;
        ans[node]+=x;
    }

    bfs(0,-1);

    rep(i,n){
        cout<<ans[i]<<" ";
    }
    return 0;

}
/*


*/
