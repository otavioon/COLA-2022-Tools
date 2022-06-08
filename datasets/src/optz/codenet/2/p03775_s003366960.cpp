#include <bits/stdc++.h>
#define rep(i,n) for(ll i=0;i<(n);++i)
#define all(a) (a).begin(),(a).end()
#define dunk(a) cout << (a) << endl
#define rall(a) (a).rbegin(),(a).rend()
const int INF = 2e9;
using namespace std;
using Graph = vector<vector<int>>;
typedef pair<int,int> P;
typedef long long ll;

int main(){
    ll n; cin >> n;
    ll a = ll(sqrt(n));
    vector<ll> und(0,0);

    rep(i,a+1){
        if(n % (i+1) == 0) und.push_back(i+1);
    }

    ll maxi = 0;

    rep(i,und.size()){
        maxi = max(maxi,und[i]);
    }

    ll semians = n/maxi;

    ll ans = 0;

    for(ll i=1; i <= semians; i*=10){
        ans++;
    }

    cout << ans << endl;
}