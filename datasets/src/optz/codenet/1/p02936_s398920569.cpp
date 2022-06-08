#include<iostream>
#include<vector>
#include<sstream>
#include<string>
#include<numeric>
#include <algorithm>
#include<math.h>
#include<cstdio>
#include<string.h>
#include<unistd.h>
#include <array>
#include <map>
#include<stdio.h>
#include<queue>
#include<set>
#include<tuple>
#include <iomanip>
#include<stack>
#define ALL(a)  (a).begin(),(a).end()
const long long MOD = 1000000007;

//いろんなstlの使い方　https://qiita.com/tukejonny/items/f4013547df761a0b3523
//http://y-mazun.hatenablog.com/entry/20111202/1322840281



using namespace std;
struct point{
    int x;
    int y;

};
//https://ei1333.github.io/luzhiled/snippets/structure/union-find.html
template< typename T >
struct WeightedUnionFind {
  vector< int > data;
  vector< T > ws;

  WeightedUnionFind() {}

  WeightedUnionFind(int sz) : data(sz, -1), ws(sz) {}

  int find(int k) {
    if(data[k] < 0) return k;
    auto par = find(data[k]);
    ws[k] += ws[data[k]];
    return data[k] = par;
  }

  T weight(int t) {
    find(t);
    return ws[t];
  }

  bool unite(int x, int y, T w) {
    w += weight(x);
    w -= weight(y);
    x = find(x), y = find(y);
    if(x == y) return false;
    if(data[x] > data[y]) {
      swap(x, y);
      w *= -1;
    }
    data[x] += data[y];
    data[y] = x;
    ws[y] = w;
    return true;
  }

  T diff(int x, int y) {
    return weight(y) - weight(x);
  }
};



long long gcd(long long a, long long b)
{
    if(a>b){
        return gcd(b,a);
    }
    return a == 0 ? b : gcd(b % a, a);
}
long long lcm( long long m, long long n )
{
    // 引数に０がある場合は０を返す
    if ( ( 0 == m ) || ( 0 == n ) )
        return 0;

    return ((m / gcd(m, n)) * n); // lcm = m * n / gcd(m,n)
}//lcm
int input(){
    int x;
    cin>>x;
    return x;
}

int moji(char in)
{
    int ans = (int)in-(int)'a';
    if((ans < 0) || (ans > 25)){
        ans = 26;
    }
    return ans;
}
const int VV=1;//場合に応じてVVの値のみ変更する必要あり
//dijkstra(s)sがスタート地点でそこからの最短距離を配列dで表す。正の重みのみ使用可能
int cost[VV][VV];
int d[VV];
bool used[VV];
void dijkstra(int s){

    fill(d,d+VV,100000);
    fill(used,used+VV,false);
    d[s]=0;
    while(true){
        cout<<"Hello"<<endl;
        int v=-1;
        for(int u=0;u<VV;u++){
            if(!used[u]&&(v==-1||d[u]<d[v]))v=u;
        }
        if(v==-1)break;
        used[v]=true;
        for(int u=0;u<VV;u++){
            d[u]=min(d[u],d[v]+cost[v][u]);
        }
    }

}

int compare_int(const void *a, const void *b)//qsort(quick sort利用時に使用)
{
    return *(int*)a - *(int*)b;
}

int binary_searchh(long long x,long long k[],int n){
    int l=0;
    int r=n;
    while(r-l>=1){
        int i=(l+r)/2;
        if(k[i]==x)return i;
        else if(k[i]<x)l=i+1;
        else r=i;
    }
    return -1;
}

struct File {
    int aa;
    int bb;

    File(const int& aa, const int& bb)
            : aa(aa), bb(bb) {}
};

/*bool operator<(const File& a, const File& b)
{
    // ファイル種別、ファイル名の順番で優先順位を付けて比較
    return std::tie(a.aa, a.bb) < std::tie(b.aa, b.bb);
}*/

long long kaijo(long long x){
    long long l=10*10*10*10*10*10*10*10*10+7;
    long long sum=1;
    for(int i=x;i>0;i--){
        sum*=i;
        if(sum>l){
            sum%=l;
        }
    }
    return sum;
}


template<class T>void chmin(T &a,T b){
    if(a>b){
        a=b;
    }
}

//formerは前方のindex(自分自身を含んで良い)
template<class T>int former(const vector<T>&v,T x){
    return upper_bound(v.begin(),v.end(),x)-v.begin()-1;
}
//latterは後方のindex(自分自身を含んで良い)
template<class T>int latter(const vector<T>&v,T x){
    return lower_bound(v.begin(),v.end(),x)-v.begin();
}

struct UnionFind{
    //par[i]データiの属する木の親の番号。i==par[i]のときデータiは木の根ノードである
    vector<int>par;
    //sizes[i]:根ノードiの木に含まれるデータ数、iが根ノードでないときは無意味な値になる
    vector<int>sizes;

    UnionFind(int n):par(n),sizes(n,1){
        //最初は全てのデータiがグループiに存在するものとして初期化
        for(int i=0;i<n;i++){
            par[i]=i;
        }
    }
    //データxが属する木の根を得る
    int find(int x){
        if(x==par[x]){
            return x;
        }
        return par[x]=find(par[x]);

    }
    //2つのデータx,yが属する木をマージする
    void unite(int x,int y){
        //データの根ノードを得る
        x=find(x);
        y=find(y);
        //もしすでに同じ木に属しているならマージの必要はない
        if(x==y){
            return;
        }
        //xの木がyの木よりも大きくなるようにする
        if(sizes[x]<sizes[y]){
            swap(x,y);
        }
        //xがyの親になるように連結する
        par[y]=x;
        sizes[x]+=sizes[y];

    }
    //2つのデータx,yが属する木が同じならtrueを返す
    bool same(int x,int y){
        return find(x)==find(y);
    }
    //データxが含まれる木の大きさを返す
    int size(int x){
        return sizes[find(x)];
    }

};

//クラスカル法
//頂点a,bをつなぐコストcostの（無向）辺
struct Edge{
    int a,b,cost;
    //コストの大小で順序定義
    bool operator<(const Edge& o)const{
        return cost<o.cost;
    }
};
//頂点数と辺集合の組として定義したグラフ
/*struct Graph{
    int n;//頂点数
    vector<Edge>es;//辺集合
    //クラスカル法で無向最小全域木のコストの和を計算する
    //グラフが非連結の時は最小全域森のコストの和になる
    //使い方http://dai1741.github.io/maximum-algo-2012/docs/minimum-spanning-tree/
    int kruskal(){
        //コストが小さい順にソーと
        sort(es.begin(),es.end());
        UnionFind uf(n);
        int min_cost=0;
        for(int ei=0;ei<es.size();ei++){
            Edge& e=es[ei];
            if(!uf.same(e.a,e.b)){
                //その辺によって2つの木が連結される
                min_cost+=e.cost;
                uf.unite(e.a,e.b);

            }
        }
        return min_cost;
    }
};*/
//標準入力からグラフを読み込む
/*Graph input_graph(){
    Graph g;
    int m;
    cin>>g.n>>m;
    for(int i=0;i<m;i++){
        Edge e;
        cin>>e.a>>e.b>>e.cost;
        g.es.push_back(e);
    }
    return g;
}*/
long long labs(long long x){
    if(x<0){
        return -x;
    }
    return x;
}
// a^n mod を計算する
long long modpow(long long a, long long n, long long mod) {
    long long res = 1;
    while (n > 0) {
        if (n & 1) res = res * a % mod;
        a = a * a % mod;
        n >>= 1;
    }
    return res;
}
//indexを用いてvectorから要素削除
template<typename T>
void remove(std::vector<T>& vector, unsigned int index)
{
    vector.erase(vector.begin() + index);
}

void modadd(long long &a,long long b){
    a+=b;
    if(a>=MOD){
        a%=MOD;

    }
}

const int MAX = 100001;
long long fac[MAX], finv[MAX], inv[MAX];

// テーブルを作る前処理
void COMinit() {
    fac[0] = fac[1] = 1;
    finv[0] = finv[1] = 1;
    inv[1] = 1;
    for (int i = 2; i < MAX; i++){
        fac[i] = fac[i - 1] * i % MOD;
        inv[i] = MOD - inv[MOD%i] * (MOD / i) % MOD;
        finv[i] = finv[i - 1] * inv[i] % MOD;
    }
}

// 二項係数計算
long long COM(int n, int k){
    if (n < k) return 0;
    if (n < 0 || k < 0) return 0;
    return fac[n] * (finv[k] * finv[n - k] % MOD) % MOD;
}
//木の直径
const int maxV = 2;
vector<int> G[maxV]; // 頂点情報のみのグラフ

// treeDFS(親, 現在地, 根から現在地までの距離, 根からの最大の距離, 根から最大の距離となる頂点
void treeDFS(int from, int current, int dist, int &maxDist, int &maxVertex) {
    // 距離と終点を更新
    if (dist > maxDist) {
        maxDist = dist;
        maxVertex = current;
    }

    for (auto to : G[current]) {
        // 逆流を防ぐ
        if (to == from) continue;
        treeDFS(current, to, dist + 1, maxDist, maxVertex);
    }
}

int getTreeDiameter() {
    int start = 0, end = 0, maxDist = 0;
    treeDFS(-1, start, 0, maxDist, end);
    start = end, end = 0, maxDist = 0;
    treeDFS(-1, start, 0, maxDist, end);
    return start;
}


vector< long long> divisor(long long n) {
  vector< long long > ret;
  for(long long i = 1; i * i <= n; i++) {
    if(n % i == 0) {
      ret.push_back(i);
      if(i * i != n) ret.push_back(n / i);
    }
  }
  sort(begin(ret), end(ret));
  return (ret);
}

int main(){
    long long N;
    long long Q;
    cin>>N>>Q;
    vector<vector<long long> >v(N+1);
    UnionFind uf(N+1);
    for(int i=0;i<N-1;i++){
        long long a,b;
        cin>>a>>b;
        v[a].push_back(b);
        uf.unite(a,b);
    }
    long long p[Q],x[Q];
    for(int i=0;i<Q;i++){
        cin>>p[i]>>x[i];
    }
    long long xx[N+1];
    for(int i=0;i<N+1;i++){
        xx[i]=0;
    }
    for(int i=0;i<Q;i++){
        xx[p[i]]+=x[i];
    }
    long long kon=uf.find(1);
    queue<long long>l;
    l.push(1);
    //cout<<"HELLO"<<endl;
    while(l.size()>0){
        long long tmp=xx[l.front()];
        long long k=l.front();
        //cout<<k<<endl;
        l.pop();
        for(int i=0;i<v[k].size();i++){
            xx[v[k][i]]+=tmp;
            l.push(v[k][i]);
        }



    }
    for(int i=1;i<N+1;i++){
        cout<<xx[i]<<endl;
    }


    

    






}
    












