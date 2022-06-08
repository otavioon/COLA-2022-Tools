#include <bits/stdc++.h>
using namespace std;
#define _GLIBCXX_DEBUG
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define all(v) v.begin(), v.end()
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }
using ll = long long;
using vi = vector<int>;
using vvi = vector<vi>;
const ll MOD = 1e9+7;
const ll INF = 1LL << 60;
const vi d8x = {1, 0, -1, 0, 1, -1, -1, 1};
const vi d8y = {0, 1, 0, -1, 1, 1, -1, -1};
const vi d4x = {1, 0, -1, 0};
const vi d4y = {0, 1, 0, -1};

//---------------from here-----------------

int main(){
    ll n; cin>>n;
    ll ans=INF;
    for(ll i=1; i<=sqrt(n); i++){
        ll bigger=0;
        if(n%i==0){
            ll a=i;
            ll b=n/i;
            string s=to_string(max(a,b));
            ans=min(ans,(ll)s.size());
        }
    }
    cout<<ans<<endl;
}