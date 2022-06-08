#include<iostream>
#include<cstdio>
#include<string>
#include<algorithm>
#include<vector>
#include<cmath>
#include<map>
#include<set>
#include<queue>
#define ll long long
#define pii pair<int,int>
#define pll pair<ll,ll>
#define pb push_back
#define rep(i,n) for(ll i=0;i<n;i++)
#define INF 1e9+7
#define LLINF 1e18
using namespace std;
const ll MOD = 1e9 +7;




int main(){
    ll n,a[200010];
    cin>>n;
    rep(i,n)cin>>a[i];
    multiset<ll> set;
    rep(i,n) set.insert(a[i]);
    ll ans=0;
    while(!set.empty()){
        auto it=set.end();
        it--;
        ll x= *it;
        set.erase(it);
        for(int i=1;i<=2*x;i*=2){
            if(set.find(i-x) !=set.end()){
                set.erase(set.find(i-x));
                ans++;
            }
        }
    }
    cout<<ans<<endl;
    return 0;
}
