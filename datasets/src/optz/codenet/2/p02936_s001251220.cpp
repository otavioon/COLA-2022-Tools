//  ROAD TO GREEN
#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
#include <queue>

using namespace std;
typedef long long ll;
const ll MAXN = 2e5+2;
vector<bool> used(MAXN,false);
vector<vector<int>> v;
int path[MAXN];
int ans[MAXN];
ll sum = 0;

void dfs(int s){
    used[s] = true;
    ans[s] = sum;
    for(int i = 0; i < v[s].size(); i++){
        int to = v[s][i];
        if(!used[to]){
            sum += path[to];
            dfs(to);
            sum -= path[to];
        }
    }
}


int main(){
    int n,q;
    cin >> n >> q;
    v.resize(n+1);
    for(int i = 1; i < n; i++){
        int a,b;
        cin >> a >> b;
        v[a].push_back(b);
        // v[b].push_back(a);
    }
    for(int i = 1; i <= q; i++){
        int p,x;
        cin >> p >> x;
        path[p] += x;
    }
    sum += path[1];
    dfs(1);
    for(int i = 1; i <= n; i++){
        cout << ans[i] << " ";
    }
    // for(int i = 1; i <= n; i++){
    //     cout << i << ": ";
    //     for(int j = 0; j < v[i].size(); j++){
    //         cout << v[i][j] << " ";
    //     }
    //     cout << endl;
    // }
    return 0;
}