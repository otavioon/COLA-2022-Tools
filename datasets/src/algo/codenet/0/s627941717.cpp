#include<bits/stdc++.h>
using namespace std;
typedef  long long ll;
using vll=vector<ll>;
using vi=vector<int>;

template<class T> inline bool chmin(T& a, T b) {if (a > b) {a = b;return true;}return false;}
template<class T> inline bool chmax(T& a, T b) {if (a < b) {a = b;return true;}return false;}

template<class T> ll llpow(T x,T n){ll ans=1;if(x==0)ans=0;while(n){if(n&1)ans*=x;x*=x;n>>=1;}return ans;}
template<class T> inline T gcd(T x,T y){if(y==0)return x; else {return gcd(y,x%y);}}
template<class T> inline T lcm(T x,T y){return x/gcd(x,y)*y;}

#define rep(i,n) for(ll i=0;i<(ll)n;i++)
#define rep2(i, begin_i, end_i) for (ll i = (ll)begin_i; i < (ll)end_i; i++)

long long INF = 1LL<<60;
int main(){
    string s;
    ll k;
    cin>>s>>k;
    ll ans=0;
    string tmp=s;
    rep(i,tmp.size()-1){
        if(tmp.at(i)==tmp.at(i+1)){
            tmp.at(i+1)='0';ans++;
        }
    }
    ans*=k;
    if(s.at(s.size()-1)==s.at(0)){
        char kind=s.at(0);
        int front=0,back=s.size()-1;
        int cfront=0,cback=0;
        while(front+cfront<s.size()&&s.at(front+cfront)==kind){
            cfront++;
        }
        while(back-cback>=0&&s.at(back-cback)==kind){
            cback++;
        }
        if(cfront==cback&&cfront==s.size()&&s.size()%2){
            ans+=k/2;
        }
        else ans+=(ll)((cfront+cback)/2-(cfront/2+cback/2))*(k-1);
    }
    cout<<ans<<endl;
    return 0;
}


