#include<bits/stdc++.h>
using namespace std;
#define REP(i,m,n) for(int i=(m);i<(n);i++)
#define rep(i,n) REP(i,0,n)
#define pb push_back
#define mp make_pair
#define all(c) (c).begin(),(c).end()
#define rall(c) (c).rbegin(),(c).rend()
typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
const ll inf=1e9+7;
const ll mod=998244353;
int main(){
    ll n;
    ll k;
    cin>>n>>k;
    set<ll>s;
    rep(i,k){
        ll t;cin>>t;
        s.insert(t);
    }
    REP(i,n,100000){
        ll t=i;
        bool f=1;
        while(t){
            if(s.find(t%10)==s.end());
            else f=0;
            t/=10;
        }
        if(f){
            cout<<i<<endl;
            break;
        }
    }
}