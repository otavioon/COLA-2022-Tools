#include <bits/stdc++.h>
#define _GLIBCXX_DEBUG
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep2(i, s, n) for (int i = s; i < (int)(n); i++)
#define Clear(a) a = decltype(a)();
typedef long long ll;
typedef vector<vector<ll>> vvl;
typedef vector<ll> vl;
typedef vector<vector<char>> vvc;
typedef vector<char> vc;
typedef pair<ll,ll> pll;
typedef priority_queue<string> priquestring;
typedef priority_queue<int> priqueint;
typedef priority_queue<ll> priquell;
typedef priority_queue<char> priquechar;
typedef priority_queue<string,vector<string>,greater<string>> rpriquestring;
typedef priority_queue<int,vector<int>,greater<int>> rpriqueint;
typedef priority_queue<ll,vector<ll>,greater<ll>> rpriquell;
typedef priority_queue<char,vector<char>,greater<char>> rpriquechar;
ll max(ll x,ll y){
if(x>y)return x;
else return y;
}
ll min(ll x,ll y){
  return x+y-max(x,y);
}

const ll big=1000000007;
int exp(int x,int y){
    if(y==0)return 1;//0^0=1
    if(x==1||x==0)return x;
    if(y%2==1)return (exp(x,y-1)*x)%big;
    int t=exp(x,y/2);
    return (t*t)%big;
}
void chmin(ll a,ll b){
    if(a>b)a=b;
    return;
}

const int dx[4]={1,0,-1,0};
const int dy[4]={0,1,0,-1};


int main(){
    ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    cout << fixed << setprecision(10);
    /*--------------------------------*/
    
    ll k;string s;cin >> s >> k;
    if(s[0]==s[(int)s.size()-1])return 1;
    //aba →k-1
    //端から連続しないor端どうしが別々の部分:/2
    //端から連続しかつ端どうしが同じ:k-1回は和を/2
    //　　　　　　　　　　　　　　　 あとはそれぞれで/2
    if(s[0]!=s[(int)s.size()-1]){
        ll cnt=0;
        rep(i,s.size()-1){
            if(s[i]==s[i+1]){cnt++;i++;}
        }
        cout << cnt*k << '\n';
        return 0;
    }else{
        bool ok=true;
        ll frt=1;ll bck=1;
        ll in=1;
        rep(i,s.size()-1){
            if(s[i]==s[i+1]&&ok)frt++;
            else ok=false;
            if(!ok&&s[i]==s[i+1])in++;
        }
        for(int j=s.size()-1;j>0;j--){
            if(s[j]==s[j-1])bck++;
            else break;
        }
        if(frt==(int)s.size()){
            cout << (ll)s.size()*k/2 << endl;
            return 0;
        }
        
        in-=(bck-1);
        in/=2;
        ll ans=k*in;
        ans+=((frt+bck)/2)*(k-1);
        ans+=frt/2+bck/2;
        cout << ans << '\n';
    }
}