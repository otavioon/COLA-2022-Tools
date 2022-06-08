#include <bits/stdc++.h>
typedef long long ll;
using namespace std;
#define rep(i,n) for(int i= 0; i<n; i++)

vector<int> to[200005];
vector<int> ans;

void dfs(int v,int p=-1){
    for(int u : to[v]){
        if(u == p) continue;
        ans[u] += ans[v];
        dfs(u,v);
    }
}

int main(){
    int n,q;
    cin >> n >> q;
    rep(i,n-i){
        int a, b;
        cin >> a >> b;
        a--;
        b--;
        to[a].push_back(b);
        to[b].push_back(a);
    }
    ans.resize(n);
    rep(i,q){
        int p,x;
        cin >> p >> x;
        p--;
        ans[p] += x;
    }
    dfs(0);
    rep(i,n){
        cout << ans[i] << endl;
    }
    return 0;
}