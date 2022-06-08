#include <bits/stdc++.h>
using namespace std;
#define IOS ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define rep(i,n) for(int i=0;i<n;i++)
#define rep1(i,n) for(int i=1;i<=n;i++)
#define rev(i,n) for(int i=n-1;i>=0;i--)
#define rev1(i,n) for(int i=n;i>0;i--)
#define pb push_back
#define vi vector<int>
#define vvi vector<vector<int>>
#define vpii vector<pair<int,int> >
#define vb vector<bool>
#define pii pair<int,int>
#define F first
#define S second
#define INF 1e9+7
typedef long long int ll;
const int N=2e5+7;
vi G[N];
int parent[N];
int cnt[N];
int tmp;

void dfs1(int v){
  for(auto x:G[v]){
    if(parent[x]==0) {parent[x]=v;dfs1(x);}
  }
}
void dfs(int v){
  cnt[v]+=tmp;
  for(auto x:G[v]){
    if(x!=parent[v]) dfs(x);
  }
}
void solve(){
  int n,q;cin>>n>>q;
  rep(i,n-1){
    int a,b;cin>>a>>b;
    G[a].pb(b);
    G[b].pb(a);
  }
  parent[1]=-1;
  dfs1(1);
  rep(i,q){
    int p;cin>>p>>tmp;
    dfs(p);
  }
  rep1(i,n) cout<<cnt[i]<<" ";
}
signed main() {
    // your code goes here
    IOS
    ll t=1;
    //cin>>t;
    rep1(i,t){
        solve(); 
    }
}