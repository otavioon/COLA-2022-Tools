#include <iostream>
#include <vector>
#include <map>
#include <set>
#include <algorithm>
#include <queue>
#include <stack>

using namespace std;
typedef long long ll;
typedef vector<ll> vl;
typedef vector<vl> vvl;
typedef pair<ll,ll> P;
typedef vector<P> vpl;
#define rep(i,n) for(ll i=0; i<(n); i++)
#define REP(i,a,b) for(ll i=(a); i<(b); i++)
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
const int inf = 1<<30;
const ll linf = 1LL<<62;
const int mod = 1e9 + 7;
const int MAX = 510000;
const int V = 100005;
ll dy[8] = {1,0,-1,0,1,-1,1,-1};
ll dx[8] = {0,1,0,-1,1,-1,-1,1};

int main(){
    ll n; cin >> n;
    multiset<ll> se;
    rep(i,n){
        ll a; cin >> a;
        se.insert(a);
    }
    ll ans = 0;
    while(se.size()>1){
        auto itr = se.end();
        itr--;
        ll x = *itr;
        se.erase(itr);
        ll cur = 1;
        while(cur <= x*2){
            auto itr2 = se.find(cur-x);
            if(itr2 != se.end()){
                se.erase(itr2);
                ans++;
                break;
            }
            cur *= 2;
        }
    }
    cout << ans << endl;
}
