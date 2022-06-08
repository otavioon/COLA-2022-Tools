#include<bits/stdc++.h>
using namespace std;
typedef  long long ll;
using vll=vector<ll>;
using vi=vector<int>;
using vvi=vector<vector<int>>;
using vb=vector<bool>;
using pii=pair<int,int>;

template<class T> inline bool chmin(T& a, T b) {if (a > b) {a = b;return true;}return false;}
template<class T> inline bool chmax(T& a, T b) {if (a < b) {a = b;return true;}return false;}

//pow(llpow,modpow)
template<class T> ll llpow(ll x,T n){ll ans=1;if(x==0)ans=0;while(n){if(n&1)ans*=x;x*=x;n>>=1;}return ans;}
long long modpow(long long a, long long n, long long mod) {long long res = 1;while (n > 0) {if (n & 1) res = res * a % mod;a = a * a % mod;n >>= 1;}return res;}
//最大公約数
template<class T> inline T gcd(T x,T y){if(y==0)return x; else {return gcd(y,x%y);}}
//最小公倍数
template<class T> inline T lcm(T x,T y){return x/gcd(x,y)*y;}
//逆元
long long modinv(long long a, long long m) {long long b = m, u = 1, v = 0;while (b) {long long t = a / b;a -= t * b; swap(a, b);u -= t * v; swap(u, v);}u %= m;if (u < 0) u += m;return u;}

#define rep(i, begin_i, end_i) for (ll i = (ll)begin_i; i < (ll)end_i; i++)
template<class T>int digid(T x){
    if(x>=1&&x<10)return 1;
    else if(x>=10&&x<100)return 2;
    else if(x>=100&&x<1000)return 3;
    else if(x>=1000&&x<10000)return 4;
    else if(x>=10000&&x<100000)return 5;
    else if(x>=100000&&x<1000000)return 6;
    else if(x>=1000000&&x<10000000)return 7;
    else if(x>=1000000&&x<10000000)return 8;
    else if(x>=10000000&&x<100000000)return 9;
    else if(x>=100000000&&x<1000000000)return 10;
    else if(x>=1000000000&&x<10000000000)return 11;
    else return -1;
}
long long INF = 1LL<<60;
int main( ){
    ll n;
    cin>>n;
    ll candiv=-1;
    int res=1<<30;
    for(ll i=1;i*i<=n;i++){
        if(n%i==0)candiv=i;
        chmin(res,max(digid(candiv),digid(n/candiv)));
    }
    cout<<res<<endl;
    return 0;
}


