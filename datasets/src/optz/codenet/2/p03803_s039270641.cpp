#include <bits/stdc++.h>
using namespace std;


int n, e, cnt;
vector<int> adj[10];
bool isTaken[10];

void dfs(int u)
{
    for (int i = 0; i < adj[u].size(); i++){
        int v = adj[u][i];
        if (isTaken[v] == 0){
            isTaken[v] = 1;
            dfs(v);
        }
    }
    int tr = 1;
    for (int i = 1; i <= n; i++){
        if (isTaken[i] == 0) {
            tr = 0;
        }
    }
    if (tr == 1) ++cnt;
    isTaken[u] = 0;
    isTaken[1] = 1;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int u, v;
    cin>>n>>e;
    for (int i = 0; i < e; i++){
        cin>>u>>v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    isTaken[1] = 1;
    dfs(1);

    cout<<cnt<<endl;

}
