#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define all(v) v.begin(), v.end()
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }
using ll = long long;
const ll MOD = 1e9+7; int INF=INT_MAX; ll LLINF = 1LL << 60;
const vector<int> d8x = {1, 0, -1, 0, 1, -1, -1, 1}; vector<int> d8y = {0, 1, 0, -1, 1, 1, -1, -1};
const vector<int> d4x = {1, 0, -1, 0}; vector<int> d4y = {0, 1, 0, -1};

//


    int n,q;
    vector<vector<ll>> G(200010);
    vector<ll> cost(200010);
    vector<bool> visited(200010,false);

    void dfs(int v, int pv){
        visited[v] = true;
        if(v!=0) cost[v] += cost[pv];
        for(auto nv: G[v]){
                if(visited[nv]==false) dfs(nv,v);
        }
    }


int main(){
    cin >> n>>q;

    rep(i,n-1){
        int a,b; cin>>a>>b;
        a--; b--;
        G[a].push_back(b); 
    }

    rep(i,q){
        int a,b; cin>>a>>b;
        a--;
        cost[a]+=b;
    }

    dfs(0,0);
    rep(i,n-1) cout<<cost[i]<<" ";
    cout<<cost[n-1]<<endl;
}