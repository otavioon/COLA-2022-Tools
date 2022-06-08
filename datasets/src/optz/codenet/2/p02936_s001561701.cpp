#include <iostream>
#include <iomanip>
#include <algorithm>
#include <vector>
using namespace std;
using ll = long long;
using lll = __int128_t;
typedef pair<ll,ll> P;
#define REP(i,b,e) for(ll i=(ll)b;i<(ll)e;i++)
#define rep0(i,n) REP(i,0ll,n)
#define rep1(i,n) REP(i,1ll,n+1)
const ll longinf=1ll<<60;
const int inf=(1<<30)-1;

vector<int> child[200001];
int parent[200001];
int visited[200001];
vector<int> adj[200001];

ll ans[200001];
ll qu[200001];

void calc(int par){
      for(auto ch:adj[par]){
            if(!visited[ch]){
                  parent[ch]=par;
                  child[par].push_back(ch);
                  visited[ch]=true;
                  calc(ch);
            }
      }
}

void calc2(ll pos,int par){
      for(auto ch:child[par]){
            ans[ch]=(pos+qu[ch]);
            //cout<<ans[ch]<<" "<<ch<<endl;
            calc2(ans[ch],ch);
      }
}

int main(){
      ll n,q;
      cin>>n>>q;
      rep1(i,n-1){
            ll a,b;
            cin>>a>>b;
            adj[a].push_back(b);
            adj[b].push_back(a);
      }
      fill(visited,visited+n+1,false);
      visited[1]=true;
      calc(1);
      fill(qu,qu+n+1,0);
      rep0(i,q){
            ll p,x;
            cin>>p>>x;
            qu[p]+=x;
      }
      calc2(qu[1],1);
      ans[1]=qu[1];
      //cout<<ans[1]<<endl;
       rep1(i,n){
            cout<<ans[i]<<" ";
      }
      cout<<endl;
      return 0;
}