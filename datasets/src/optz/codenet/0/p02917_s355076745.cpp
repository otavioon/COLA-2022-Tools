#include<bits/stdc++.h>
using namespace std;
#define int long long
#define double long double
#define fo(a,b) for(int a=0;a<b;a++)
#define Sort(a) sort(a.begin(),a.end())
#define rev(a) reverse(a.begin(),a.end())
#define fi first
#define se second
#define co(a) cout<<a<<endl
#define sz size()
#define bgn begin()
#define en end()
#define pb push_back
#define pp() pop_back()
#define V vector
#define P pair
#define V2(a,b,c) V<V<int>> a(b,V<int>(c))
#define V2a(a,b,c,d) V<V<int>> a(b,V<int>(c,d))
#define incin(a) int a; cin>>a
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
#define Pi P<int,int>
#define elif else if
int low(V<int> a,int b){
  decltype(a)::iterator c=lower_bound(a.begin(),a.end(),b);
  int d=c-a.bgn;
  return d;
}
int upp(V<int> a,int b){
  decltype(a)::iterator c=upper_bound(a.begin(),a.end(),b);
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
  double b=sqrt(a);
  for(int i=3;i<=b;i+=2){
    if(a%i==0){
      return false;
    }
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
int lcm(int a,int b){
    return a/gcm(a,b)*b;
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
  int c=1;
  for(int i=a;i>=b;i--)
    c*=i;
  return c;
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
V<P<int,int>> mawari4={{0,-1},{0,1},{1,0},{-1,0}};
V<P<int,int>> mawari8={{0,-1},{0,1},{1,0},{-1,0},{-1,-1},{1,1},{1,-1},{-1,-1}};
// 最短距離の表:c
// スタート:sx,sy
// ゴール:gx,gy
/*int bfs(V<V<char>> a){
  Q<P<int,int>> b;
  fo(i,a.sz){
    fo(j,a[0].sz){
      c[i][j]==INF;
    }
  }
  b.push({sx,sy});
  c[sx][sy]=0;
  while(b.sz){
    P d=b.front();
    b.pop();
    if(d=={gx,gy})
      break;
    fo(i,4){
      int e=d.fi+mawari4[i],f=d.se+mawari4[i];
      if(naka(e,f,a)&&a[e][f]=='.'&&c[e][f]==INF){
        b.push({e,f});
        c[e][f]==c[d.fi][d.se]+1;
      }
    }
  }
  return c[gx][gy];
}*/

int inf=1000000000000000007;
/*
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
signed main(){
  int n;
  cin>>n;
  vector<int> b(n-1);
  fo(i,n-1){
    cin>>b[i];
  }
  string a;
  fo(i,n-2){
    a[i]==min(b[i],b[i+1]);
  }
  cout<<b[0]<<a<<b[n-2]<<endl;
}
