#include <bits/stdc++.h>
#define ll long long
#define pq priority_queue
using namespace std;
const ll INF=(ll)1e9;
const ll MOD=(ll)1e9+7;
const ll MAX=510000;
vector<int> dx={1,0,-1,0},dy={0,1,0,-1};
template<class T> inline bool chmax(T& a, T b) { if (a<b) { a=b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a>b) { a=b; return 1; } return 0; }

ll N,Q;
vector<vector<ll>> G(200100);
vector<ll> ans(200100,0);
vector<ll> cnt(200100,0);

int main(){
    cin>>N>>Q;
    for(ll i=0;i<N-1;i++){
        ll a,b;
        cin>>a>>b;
        G[a-1].push_back(b-1);
    }
    for(ll i=0;i<Q;i++){
        ll p,x;
        cin>>p>>x;
        cnt[p-1]+=x;
    }
    for(ll i=0;i<N;i++){
        for(ll j=0;j<G[i].size();j++){
            cnt[G[i][j]]+=cnt[i];
        }
    }
    for(ll i=0;i<N;i++){
        cout<<cnt[i];
        if(i!=N-1) cout<<" ";
    }
    cout<<endl;
}