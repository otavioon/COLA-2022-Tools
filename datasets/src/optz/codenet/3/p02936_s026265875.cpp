#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>
#include <string>
#include <queue>
#include <map>
#define ll long long

using namespace std;

int main(void){
    ll n, q;
    cin >> n >> q;
    vector<vector<ll>> g(n+1);
    for(ll i = 1; i <= n-1; i++){
        ll a, b;
        cin >> a >> b;
        g[a].push_back(b);
        g[b].push_back(a);
    }
    vector<ll> dist(n+1,-1);
    queue<ll> que;
    dist[1] = 0;
    que.push(1);
    vector<pair<ll, ll>> pairs(n);
    while(!que.empty()){
        int v = que.front();
        que.pop();
        for(ll nv : g[v]){
            if(dist[nv]!=-1) continue;
            dist[nv] = dist[v]+1;
            que.push(nv);
        }
    }

    vector<ll> ans(n+1, 0);
    for(ll i = 0; i < q; i++){
        ll a, b; cin >> a >> b;
        ans[a] += b;
    }
    for(ll i = 1; i <= n; i++){
        for(ll j = 0; j < g[i].size(); j++){
            ll c = g[i][j];
            if(dist[i] < dist[c]){
                ans[c] += ans[i];
            }
        }
    }
    for(ll i = 1; i <= n; i++)
        cout << ans[i] << " ";
    cout << endl;
    return 0;
}
