#define _GLIBCXX_DEBUG//TLEの原因になるので注意！！！！！！！！！！！
#include<cmath>
#include <bits/stdc++.h>
typedef long long ll;
using namespace std;
vector<int> arr;
stack<int> st;
queue<int> qu;
queue<pair<int,int> > qu2;
priority_queue<int> pq;
#define rep(i,n) for(int i=0; i<(int)(n); i++)
#define rep2(i,n) for(int i=1; i<=(int)(n); i++)
typedef set<int> set_t;
typedef set<string> set_g;
typedef complex<double> xy_t;
static const int NIL = -1;
static const int INF = 1000000007;
#define mp make_pair

/*int P[10010];
void init(int n){//Union-find
    for(int i=0;i<n;++i)P[i]=i;
}
int root(int a) {
    if(P[a]==a)return a;
    return (P[a]=root(P[a]));
}
bool is_same_set(int a,int b){
    return root(a) == root(b);//代表元を求める
}
void unite(int a,int b){
    P[root(a)]=root(b);
}//対set,グラフ？
//セグメント木？？
*/

//Unionfind ,Disjointset
class UnionFind{
public:
//親の番号を格納する　親の場合-（その集合のサイズ）
    vector<int> Parent;
    //作るときはParentの値を全て-１にする
    UnionFind(int n){
        Parent = vector<int>(n,-1);
    }
    //Aがどのグループに属するか
    int root(int A){
        if(Parent[A] < 0)return A;
        return Parent[A]=root(Parent[A]);
    }
    //自分のグループの頂点数
    int size(int A){
        return -Parent[root(A)];
    }
    //AとBをくっつける
    int connect(int A,int B){
        //AとBを直接ではなくAのrootとBのrootをくっつける
        A = root(A);
        B = root(B);
        if(A==B){
            return false;//すでにくっついている
        }
        if(size(A)<size(B)) swap(A,B);
        //Aのサイズ更新
        Parent[A]+=Parent[B];
        //Bの親をAに変更する
        Parent[B]=A;

        return true;
    }
};

double dot_product(xy_t a, xy_t b) { return (conj(a)*b).real(); }//内積
double cross_product(xy_t a, xy_t b) { return (conj(a)*b).imag(); }//外積
xy_t projection(xy_t p, xy_t b) { return b*dot_product(p,b)/norm(b); }//投影
//対図形

#define mod 1000000007
/*ll f[2001];
//int n,k とかしておく

ll pw(ll x, ll y){//euclidの互除法より
    ll a= 1;
    while(y){
        if(y&1){//奇数なら
            a = a*x%mod;
        }
        x = x*x%mod;
        y /= 2;
    }
    return a;
}

ll modinv(ll x){//逆元を求める
    return pw(x, mod - 2 );
}

ll comb(int n,int r){
    if(n<r){
        return 0;
    }
    return f[n] * modinv(f[r])%mod*modinv(f[n-r])%mod;
}//対combination//ただしfは用意してね
*/

struct BIT{
    vector<int> dat;
    int sz;
    BIT(int n){
        for(sz=1;sz<n;sz *= 2);
        dat.resize(++sz);
    }
    int q(int n){
        int ret = 0;
        for(int i=n;i>0;i-=i&-i)ret +=dat[i];//和の計算　iから最後の１のbit(i&-i 多分＆はビット積)を減算
        for(int i=n;i<sz;i+=i&-i) dat[i]++;//値の加算　iから最後mの１のbitを加算
        return ret;
    }
};
/*
// auto mod int
// https://youtu.be/L8grWxBlIZ4?t=9858
// https://youtu.be/ERZuLAxZffQ?t=4807 : optimize
// https://youtu.be/8uowVvQ_-Mo?t=1329 : division
const int mod = 1000000007;
struct mint {
  ll x; // typedef long long ll;
  mint(ll x=0):x((x%mod+mod)%mod){}
  mint& operator+=(const mint a) {
    if ((x += a.x) >= mod) x -= mod;
    return *this;//thisポインター　thisで自分自身のアドレス
  }
  mint& operator-=(const mint a) {
    if ((x += mod-a.x) >= mod) x -= mod;
    return *this;
  }
  mint& operator*=(const mint a) {
    (x *= a.x) %= mod;
    return *this;
  }
  mint operator+(const mint a) const {
    mint res(*this);
    return res+=a;
  }
  mint operator-(const mint a) const {
    mint res(*this);
    return res-=a;
  }
  mint operator*(const mint a) const {
    mint res(*this);
    return res*=a;
  }
  mint pow(ll t) const {
    if (!t) return 1;
    mint a = pow(t>>1);
    a *= a;
    if (t&1) a *= *this;
    return a;
  }

  // for prime mod
  mint inv() const {
    return pow(mod-2);
  }
  mint& operator/=(const mint a) {
    return (*this) *= a.inv();
  }
  mint operator/(const mint a) const {
    mint res(*this);
    return res/=a;
  }
};
*/

int main(){
    int a,b;
    cin >> a>> b;
    cout<<(a-1)*(b-1)+1<<endl;
    return 0;
}