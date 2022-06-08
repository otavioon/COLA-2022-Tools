#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<ll> V;
#define rep(a,j,n) for(ll i=a;i<j;i=i+n )
typedef pair<ll,ll> P;
const ll mod = 1000000007;
const ll INF = 1000000009;
ll i;

int main(){
    ll N,Q;
    cin>>N>>Q;
    V cnt(N+1,0);
    V kan(N-1),can(N-1);
    rep(0,N-1,1)cin>>kan.at(i)>>can.at(i);
    

    vector<V> sons(N+1);
    rep(0,N+1,1)sons.at(i).push_back(i);
    rep(0,N-1,1){
        sons.at(min(kan.at(i),can.at(i))).push_back(max(kan.at(i),can.at(i)));
    }

    V p(Q),x(Q);
    rep(0,Q,1)cin>>p.at(i)>>x.at(i);

    V getpoint(N+1,0);
    rep(0,Q,1){
        getpoint.at(p.at(i))+=x.at(i);
    }
    
    vector<bool> jud(N+1,true);

    rep(1,N+1,1){
        if(jud.at(i)&&getpoint.at(i)){
            queue<ll> po;
            po.push(i);
            while(!po.empty()){
                ll f=po.front();
                po.pop();
                ll np=getpoint.at(f);
                jud.at(f)=false;
                cnt.at(f)+=np;
                for(ll j=1;j<sons.at(f).size();j++){
                    po.push(sons.at(f).at(j));
                    getpoint.at(sons.at(f).at(j))+=np;
                }
            }
        }
    }

    rep(1,N+1,1){
        cout<<cnt.at(i)<<" ";
    }
    cout<<endl;
}
