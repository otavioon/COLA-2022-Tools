#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int,int> P;
typedef pair<ll,ll> l_l;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<ll> vl;
typedef vector<P> vp;
#define fi first
#define se second
#define rep(i,n) for(int i = 0; i < (n); ++i)
#define rrep(i,n) for(int i = 1; i <= (n); ++i)
#define drep(i,n) for(int i = (n)-1; i >= 0; --i)
const int INF=1001001000;
const int mINF=-1001001000;
const ll LINF=1010010010010010000;
template<class T> inline bool chmin(T& a, T b) {
if (a > b) {
a = b;
return true;
}
return false;
}
template<class T> inline bool chmax(T& a, T b) {
if (a < b) {
a = b;
return true;
}
return false;
}
int n;
ll a,b;
bool ok(ll mid,vl h){
    ll sum=0;
    rep(i,n){
        ll x=h[i]-mid*b;
        if(x>0){
            ll y=a-b;
            ll need=(x+y-1)/y;
            sum+=need;
        }
    }
    return sum<=mid;
}
int main(){
    cin >> n;
    cin >> a >> b;
    vl h(n);
    rep(i,n) cin >> h[i];
    vl ch=h;
    sort(ch.rbegin(),ch.rend());
    ll mx=ch[0];
    ll mx_cnt=(mx+b-1)/b;
    ll l=0,r=mx_cnt;
    while(r>l+1){
        ll mid=(r+l)/2;
        if(ok(mid,h)) r=mid;
        else l=mid;
        //cout << l << " " << r << endl;
    }
    cout << r << endl;
    return 0;
}