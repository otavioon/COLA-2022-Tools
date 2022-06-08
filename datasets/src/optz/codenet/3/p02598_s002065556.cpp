#include <bits/stdc++.h>
#define _GLIBCXX_DEBUG
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep2(i, s, n) for (int i = s; i < (int)(n); i++)
#define Clear(a) a = decltype(a)()
#define all(a) a.begin(),a.end()
#define vec vector
typedef long long ll;
typedef pair<int,int> p;
//const ll big=998244353;
const ll big=1000000007;
const int dx[4]={1,0,-1,0};
const int dy[4]={0,1,0,-1};
ll max(ll x,ll y){
if(x>y)return x;
else return y;
}
ll min(ll x,ll y){
if(x<y)return x;
else return y;
}
ll expm(ll x,ll y){
    if(y==0)return 1;//0^0=1
    if(x==1||x==0)return x;
    if(y%2==1)return (expm(x,y-1)*x)%big;
    ll t=expm(x,y/2);
    return (t*t)%big;
}
ll exp(ll x,ll y){
    if(y==0)return 1;//0^0=1
    if(x==1||y==0)return x;
    if(y%2==1)return exp(x,y-1)*x;
    ll t=exp(x,y/2);
    return t*t;
}
ll inv(ll x){
    return expm(x,big-2);
}

int main(){
    ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    cout << fixed << setprecision(10);
    /*--------------------------------*/

    int n,k;cin >> n >> k;
    vec<int> a(n);
    ll sum=0;
    rep(i,n)cin >> a[i];
    sort(all(a));
    if(k==0){cout << a[n-1] << endl;return 0;}
    function <int(int,int)>ans = [&](int l,int r){
        if(r-l==1)return r;
        int m=(l+r)/2;
        //答えをm以下にできるか判定
        //m以下にできるならもっと厳しい範囲に
        ll cnt=0;
        rep(i,n){
            cnt+=(a[i]+m-1)/m-1;
        }
        if(cnt<=k)return ans(l,m);
        else return ans(m,r);
        return 0;
    };
    cout << ans(0,a[n-1]) << endl;
}