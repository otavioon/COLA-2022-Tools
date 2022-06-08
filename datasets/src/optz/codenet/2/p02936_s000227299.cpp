#include<bits/stdc++.h>
#define REP(i,n) for(int i=0;i<n;i++)
#define RREP(i,n) for(int i=n;i>=0;i--)
#define FOR(i,m,n) for(int i=m;i<n;i++)
#define ALL(v) v.begin(), v.end()
#define RALL(v) v.rbegin(), v.rend()
using namespace std;
typedef long long ll;
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }
//const ll INF = 1LL << 60;
//const int INF = 1001001001;

vector<int> to[200005];
vector<int> ans;

void dfs(int v,int p=-1){
    for(int u: to[v]){
        if(u==p)continue;
        ans[u]+=ans[v];
        dfs(u,v);
    }
}


int main(void){
    int n,q;
    cin >> n >> q;
    REP(i,n-1){
        int a,b;
        cin >> a >> b;
        --a;--b;
        to[a].push_back(b);
        to[b].push_back(a);
    }
    ans.resize(n);
    REP(i,q){
        int p,x;
        cin >> p >> x;
        --p;
        ans[p]+=x;
    }
    dfs(0);
    REP(i,n){
        cout << ans[i] << endl;
    }
    return 0;
}