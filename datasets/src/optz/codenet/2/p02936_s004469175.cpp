#include <bits/stdc++.h>
using namespace std;
using ll = long long;
int N,Q;
vector<vector<int>> G(N);
vector<int> P(N);
vector<int> C(N);
vector<int> res(N);

void dfsP(int v,int p){
    P[v] = p;
    for(auto e: G[v]){
        if (e == 0 || P[e] != -1) continue;
        dfsP(e,v);
    }
}

void dfsQ(int p,int c){
    res[p] += c;
    for (auto e:G[p]){
        if (P[p] == e) continue;
        dfsQ(e,C[e] + c);
    }
};

int main() {
    cin >> N >> Q;
    G.assign(N,vector<int>());
    for (int i = 0;i < N - 1;i++){
        int a,b;cin >> a >> b;a--,b--;
        G[a].push_back(b);
        G[b].push_back(a);
    }
    P.assign(N,-1);dfsP(0,-1);
    //for (int i = 0;i < N;i++) cout << P[i] << endl;
    res.assign(N,0);C.assign(N,0);
    for (int i = 0;i < Q;i++){
        int p,x;cin >> p >> x;p--;
        C[p] += x;
    }
    dfsQ(0,C[0]);
    for (int i = 0;i < N;i++) {
        if (i != N - 1) cout << res[i] << " ";
        else cout << res[i] << endl;
    }
}