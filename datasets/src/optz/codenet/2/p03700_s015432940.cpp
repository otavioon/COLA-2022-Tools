#include<bits/stdc++.h>
using namespace std;
#define int long long
#define double long double
#define fo(a,b) for(int a=0;a<b;a++)
#define Sort(a) sort(a.begin(),a.end())
#define rev(a) reverse(a.begin(),a.end())
#define fi first
#define se second
#define sz size()
#define bgn begin()
#define en end()
#define pb push_back
#define pp() pop_back()
#define V vector
#define P pair
#define yuko(a) setprecision(a)
#define uni(a) a.erase(unique(a.begin(),a.end()),a.end())
#define Q queue
#define pri priority_queue
#define Pri priority_queue<int,vector<int>,greater<int>>
#define PriP priority_queue<P<int,int>,vector<P<int,int>>,greater<P<int,int>>>
#define ff first.first
#define fs first.second
#define sf second.first
#define ss second.second
#define all(a)  (a).begin(),(a).end()
#define elif else if
int low(V<int> &a,int b){
  auto c=lower_bound(a.begin(),a.end(),b);
  int d=c-a.bgn;
  return d;
}
int upp(V<int> &a,int b){
  auto c=upper_bound(a.begin(),a.end(),b);
  int d=c-a.bgn;
  return d;
}
template<class T>
 void cou(vector<vector<T>> a){
  int b=a.size();
  int c=a[0].size();
  fo(i,b){
    fo(j,c){
      cout<<a[i][j];
      if(j==c-1)
        cout<<endl;
      else
        cout<<' ';
    }
  }
}
int wari(int a,int b) {
  if(a%b==0)
    return a/b;
  else
    return a/b+1;
}
int keta(int a){
  double b=a;
  b=log10(b);
  int c=b;
  return c+1;
}
int souwa(int a){
  return a*(a+1)/2;
}
int gcm(int a,int b){
  if(a%b==0)
    return b;
  return gcm(b,a%b);
}
bool prime(int a){
  if(a<2)
    return false;
  else if(a==2)
    return true;
  else if(a%2==0)
    return false;
  for(int i=3;i<=sqrt(a)+1;i+=2){
    if (a%i==0)
      return false;
  }
  return true;
}
struct Union{
  vector<int> par;
  Union(int a){
  par=vector<int>(a,-1);
  }
  int find(int a){
    if(par[a]<0)
      return a;
    else
      return par[a]=find(par[a]);
  }
  bool same(int a,int b){
    return find(a)==find(b);
  }
  int Size(int a){
    return -par[find(a)];
  }
  void unite(int a,int b){
    a=find(a);
    b=find(b);
    if(a==b)
      return;
    if(Size(b)>Size(a))
      swap<int>(a,b);
    par[a]+=par[b];
    par[b]=a;
  }
};
int ketas(int a){
  string b=to_string(a);
  int c=0;
  fo(i,keta(a)){
    c+=b[i]-'0';
  }
  return c;
}
bool fe(int a,int b){
  a%=10;
  b%=10;
  if(a==0)
    a=10;
  if(b==0)
    b=10;
  if(a>b)
    return true;
  else
    return false;
}
int INF=1000000007;
struct edge{int s,t,d; };
V<int> mojisyu(string a){
  V<int> b(26,0);
  fo(i,a.sz){
    b[a[i]-'a']++;
  }
  return b;
}
int wa2(int a){
  if(a%2==1)
    return a/2;
  return a/2-1;
}
/*signed main(){
  int a,b,c;
  cin>>a>>b>>c;
  V<V<edge>> d(a);
  fo(i,b){
    edge e;
    cin>>e.s>>e.t>>e.d;
    d[e.s].pb(e);
  }
  V<int> e(a,INF);
  e[c]=0;
  priority_queue<P<int,int>,V<P<int,int>>,greater<P<int,int>>> f;
  f.push({0,c});
  int h=INF;
  while(!f.empty()){
    P<int,int> g;
    g=f.top();
    f.pop();
    int v = g.second, i = g.first;
    for(edge l : d[v]){
      if(e[l.t] > i + l.d){
        e[l.t] = i + l.d;
        f.push({i+l.d , l.t});
      }
    }
  }
  fo(i,a){
    if(e[i]==INF)
      cout<<"INF"<<endl;
    else
      cout<<e[i]<<endl;
  }
}
?*/
int nCr(int n,int r){
  int a=1;
  r=min(r,n-r);
  for(int i=n;i>n-r;i--){
    a*=i;
    a/=n-i+1;
  }
  return a;
}
/*void sea(int x,int y){
  if(x<0||a<=x||y<0||b<=y||c[x][y]=='#')
    return;
  if(d[x][y])
    return;
  d[x][y]++;
  sea(x+1,y);
  sea(x-1,y);
  sea(x,y+1);
  sea(x,y-1);
}*/
int kaijou(int a){
  int b=1;
  fo(i,a)
    b*=i+1;
  return b;
}
int nPr(int a,int b){
  if(a<b)
    return 0;
  if(b==0)
    return 1;
  int c=1;
  for(int i=a;i>a-b;i--){
    c*=i;
    c%=INF;
  }
  return c;
}
long long modpow(long long a, long long n, long long mod) {
    long long res = 1;
    while (n > 0) {
        if (n & 1) res = res * a % mod;
        a = a * a % mod;
        n >>= 1;
    }
    return res;
}

// a^{-1} mod を計算する
long long modinv(long long a, long long mod) {
    return modpow(a, mod - 2, mod);
}

int lcm(int a,int b){
  int c=modinv(gcm(a,b),INF);
  return ((a*c)%INF)*(b%INF)%INF;
}
int MOD=INF;
int fac[1000010], finv[1000010], inv[1000010]; 
// テーブルを作る前処理
//先にCOMinit()で前処理をする
//ABC145D
void COMinit() {
  fac[0]=fac[1]=1;
  finv[0]=finv[1]=1;
  inv[1]=1;
  for(int i=2;i<1000010;i++){
    fac[i]=fac[i-1]*i%MOD;
    inv[i]=MOD-inv[MOD%i]*(MOD/i)%MOD;
    finv[i]=finv[i-1]*inv[i]%MOD;
  }
}
// 二項係数計算
int COM(int n,int k){
  if(n<k)
    return 0;
  if(n<0||k<0)
    return 0;
  return fac[n]*(finv[k]*finv[n-k]%MOD)%MOD;
}
bool naka(int a,int b,V<V<char>> c){
  return (a>=0&&b>=0&&a<c.sz&&b<c[0].sz);
}

V<P<int,int>> mawari8={{0,-1},{0,1},{1,0},{-1,0},{-1,-1},{1,1},{1,-1},{-1,-1}};
int inf=1000000000000000007;

V<P<int,int>> mawari4={{0,-1},{0,1},{1,0},{-1,0}};
//最短経路の表 a(全部INFで初期化)
//縦横 x,y
//迷路 f
//スタートsx,sy
//ゴールgx,gy
//文字はgから使おうね
/*int bfs_haba(){
  Q<P<int,int>> b;
  a[sx][sy]=0;
  b.push({sx,sy});
  while(!b.empty()){
    P<int,int> c=b.front();
    b.pop();
    if(c.fi==gx&&c.se==gy){
      break;
    }
    fo(i,4){
      int d=c.fi+mawari4[i].fi;
      int e=c.se+mawari4[i].se;
      if(0<=d&&0<=e&&d<x&&e<y&&f[d][e]!='#'&&a[d][e]==INF){
        b.push({d,e});
        a[d][e]=1+a[c.fi][c.se];
      }
    }
  }
  return a[gx][gy];
}*/
V<int> onajibubun(string a){
  V<int> b(a.sz);
  for(int i=1,j=0;i<a.sz;i++){
    if(i+b[i-j]<j+b[j])
      b[i]=b[i-j];
    else{
      int c=max<int>(0,j+b[j]-i);
      while(i+c<a.sz&&a[c]==a[i+c])
        c++;
      b[i]=c;
      j=i;
    }
  }
  b[0]=a.sz;
  return b;
}
//各頂点ごとにどこに辺が出てるかの表がc
//各頂点ごとの色を表すV<int>(頂点数max)のcolorを用意する
//aはどこ塗るか、bは何で塗るかなので、(0,1,c)でよぶとおけ
V<int> color(200005);
bool nibu_hantei(int a,int b,V<V<int>> c){
  color[a]=b;
  fo(i,c[a].sz){
    if(b==color[c[a][i]])
      return false;
    if(color[c[a][i]]==0&&!nibu_hantei(c[a][i],-b,c))
      return false;
  }
  return true;
}
//aは頂点数
//nibu_hanteiの上にcolorを用意する
//各頂点ごとにどこに辺が出てるかの表がc
bool renketujanai_nibu_hantei(int a,V<V<int>> c){
  fo(i,a){
    if(color[i]==0){
      if(!nibu_hantei(i,1,c))
        return false;
    }
  }
  return true;
}
struct segmin{
  vector<int> seg;
  int b;
  segmin(V<int> a){
    b=1;
    while(b<a.sz)
      b*=2;
    seg=vector<int>(2*b-1,inf);
    fo(i,a.sz){
      seg[i+b-1]=a[i];
    }
    for(int i=b-2;i>=0;i--){
      seg[i]=min(seg[2*i+1],seg[2*i+2]);
    }
  }
  void update(int i,int a){
    i+=b-1;
    seg[i]=a;
    while(i){
      i=(i-1)/2;
      seg[i]=min(seg[2*i+1],seg[2*i+2]);
    }
  }
  //最初呼び出すときは要求区間x,y+1(yは添え字+1)とa=0,l=0,r=INFで
  //l,rは探すところ
  int getmin(int x,int y,int a,int l,int r){
    if(r==INF)
      r=b;
    if(r<=x||y<=l)
      return INF;
    if(x<=l&&r<=y)
      return seg[a];
    int a1=getmin(x,y,2*a+1,l,(l+r)/2);
    int a2=getmin(x,y,2*a+2,(l+r)/2,r);
    return min(a1,a2);
  }
};
struct segadd{
  vector<int> seg;
  int b;
  segadd(V<int> a){
    b=1;
    while(b<a.sz)
      b*=2;
    seg=vector<int>(2*b-1,0);
    fo(i,a.sz){
      seg[i+b-1]=a[i];
    }
    for(int i=b-2;i>=0;i--){
      seg[i]=seg[2*i+1]+seg[2*i+2];
    }
  }
  void update(int i,int a){
    i+=b-1;
    seg[i]=a;
    while(i){
      i=(i-1)/2;
      seg[i]=seg[2*i+1]+seg[2*i+2];
    }
  }
  //最初呼び出すときは要求区間x,y+1(yは添え字+1)とa=0,l=0,r=INFで
  //l,rは探すところ
  int getadd(int x,int y,int a,int l,int r){
    if(r==INF)
      r=b;
    if(r<=x||y<=l)
      return 0;
    if(x<=l&&r<=y)
      return seg[a];
    int a1=getadd(x,y,2*a+1,l,(l+r)/2);
    int a2=getadd(x,y,2*a+2,(l+r)/2,r);
    return a1+a2;
  }
};
struct sege{
  vector<P<int,V<int>>> seg;
  int b;
  sege(string a){
    b=1;
    while(b<a.sz)
      b*=2;
    seg=vector<P<int,V<int>>>(2*b-1);
    fo(i,a.sz){
      seg[i+b-1].fi=1;
      seg[i+b-1].se.pb(a[i]-'a');
    }
    for(int i=b-2;i>=0;i--){
      V<int> d=seg[2*i+1].se;
      fo(j,seg[2*i+2].se.sz){
        d.pb(seg[2*i+2].se[j]);
      }
      Sort(d);
      uni(d);
      seg[i].se=d;
      seg[i].fi=d.sz;
    }
  }
  V<int> mu;
  void update(int i,char a){
    i+=b-1;
    seg[i].se=mu;
    seg[i].se.pb(a-'a');
    seg[i].fi=1;
    while(i){
      i=(i-1)/2;
      V<int> d=seg[2*i+1].se;
      fo(j,seg[2*i+2].se.sz){
        d.pb(seg[2*i+2].se[j]);
      }
      Sort(d);
      uni(d);
      seg[i].se=d;
      seg[i].fi=d.sz;
    }
  }
  void unko(){
    fo(i,2*b-1)
    cout<<seg[i].fi<<' ';
  }
  //最初呼び出すときは要求区間x,y+1(yは添え字+1)とa=0,l=0,r=INFで
  //l,rは探すところ
  P<int,V<int>> gete(int x,int y,int a,int l,int r){
    if(r==INF)
      r=b;
    if(r<=x||y<=l)
      return {0,mu};
    if(x<=l&&r<=y)
      return seg[a];
    P<int,V<int>> a1=gete(x,y,2*a+1,l,(l+r)/2);
    P<int,V<int>> a2=gete(x,y,2*a+2,(l+r)/2,r);
    fo(i,a2.se.sz)
    a1.se.pb(a2.se[i]);
    Sort(a1.se);
    uni(a1.se);
    return {a1.se.sz,a1.se};
  }
};/*
signed main(){
  int a,b,c;
  cin>>a>>b>>c;
  V<V<edge>> d(a);
  fo(i,b){
    edge e;
    cin>>e.s>>e.t>>e.d;
    d[e.s].pb(e);
  }
  V<int> e(a,INF);
  e[c]=0;
  priority_queue<P<int,int>,V<P<int,int>>,greater<P<int,int>>> f;
  f.push({0,c});
  int h=INF;
  while(!f.empty()){
    P<int,int> g;
    g=f.top();
    f.pop();
    int v = g.second, i = g.first;
    for(edge l : d[v]){
      if(e[l.t] > i + l.d){
        e[l.t] = i + l.d;
        f.push({i+l.d , l.t});
      }
    }
  }
  fo(i,a){
    if(e[i]==INF)
      cout<<"INF"<<endl;
    else
      cout<<e[i]<<endl;
  }
}*/
//aのb乗mod c
int kurikaesijijou(int a,int b,int c){
  a%=c;
  b%=c;
  if(b==0)
    return 1;
  if(b%2==0){
    int d=kurikaesijijou(a,b/2,c);
    d%=c;
    return d*d%c;
  }
  return a*kurikaesijijou(a,b-1,c)%c;
}
int waINF(int a){
  if(a>=0)
    return a%INF;
  return (a+INF*INF)%INF;
}
signed main(){
  int a,b,c;
  cin>>a>>b>>c;
  V<int> d(a);
  fo(i,a)
  cin>>d[i];
  Sort(d);
  rev(d);
  int e,l=0,r=d[0]/c+1;
  int g=0;
  fo(i,1000) { //  cout<<l<<' '<<r<<endl;
    e=(l+r)/2;
  /*  if(e==l&&l==r-1){
      break;
    }*/
    int f=0;
    fo(i,a){
      f+=(d[i]-c*e+b-c-1)/(b-c);
    }
    if(f>e)
      l=e;
    else
      r=e;
  }
  cout<<r<<endl;
}