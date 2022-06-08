#include<bits/stdc++.h>
using namespace std;

#define lli long long
#define all(i) i.begin(),i.end()
#define rall(i) i.rbegin(),i.rend()
#define rep0(i,j) for(int i=0;i<j;i++)
#define rep1(i,j) for(int i=1;i<=j;i++)
#define rep0d(i,j) for(int i=j-1;i>=0;i--)
#define MOD 1000000007
#define MAX (lli)1e12 
typedef pair<lli, lli> p; 
class Graph{
  int V;
  list<p> *adj; 
  const int INF = (int)1e6;

  public: 
  Graph(int V){ 
    this->V = V; 
    adj = new list<p> [V]; 
  } 

  void addEdge(int u, int v, int w){ 
    adj[u].push_back(make_pair(v, w)); 
  } 

  lli edgeNum(){
    lli sum=0;
    rep0(i,V)sum+=adj[i].size();
    return sum;
  }

  bool route(lli from, lli to){//vec[i]==j: j->iっていうもとに戻れる道がある
    vector<lli> vec(V, -1);
    dfs(1,from,vec);
    return vec[to] >= 0;
  }

  void dfs(lli ed, lli num, vector<lli>& vec){
    for(auto e: adj[num]){
      if(vec[e.first] != -1)continue;
      vec[e.first] = num;
      dfs(ed+1, e.first, vec);
    }
  }

  vector<int> bfs(int n){
    queue<int> q;
    vector<int> vec(V,-1);

    q.push(n);
    vec[n]=0;
    while(!q.empty()){
      int p=q.front();
      q.pop();
      for(auto e:adj[p]){
        if(vec[e.first]==-1){
          q.push(e.first);
          vec[e.first] = e.second + vec[p];
        }
      }
    }
    return vec;
  }

  vector<int> shortestPath(int src){ 
    priority_queue< p, vector <p> , greater<p> > pq; 
  
    vector<int> dist(V, INF); 
    pq.push(make_pair(0, src)); 
    dist[src] = 0; 
  
    while (!pq.empty()) { 
        int u = pq.top().second; 
        pq.pop(); 
  
        list< pair<int, int> >::iterator i; 
        for (auto i = adj[u].begin(); i != adj[u].end(); ++i) { 
            int v = (*i).first; 
            int weight = (*i).second; 
  
            if (dist[v] > dist[u] + weight) { 
                dist[v] = dist[u] + weight; 
                pq.push(make_pair(dist[v], v)); 
            } 
        } 
    } 
    for(int i=0;i<V;i++)if(dist[i]==INF)dist[i]=-1;
    return dist;
  } 
};
 
p operator-(const p & l,const p & r) {   
    return {l.first-r.first,l.second-r.second};                                    
}
bool cmpf(const pair<lli, lli> left, const pair<lli, lli> right) {
    return left.first < right.first;
}
bool cmps(const pair<lli, lli> left, const pair<lli, lli> right) {
    return left.second < right.second;
}
 
void dfs(lli ed, lli num, vector<map<lli,lli>>& vec){
    lli n=1;
    for(auto e: vec[num]){
        if(n == ed)n++;
        if(e.second != -1)continue;
        vec[num][e.first] = n;
        vec[e.first][num] = n;   
        dfs(n, e.first, vec);
        n++;
    }
}
 
lli gcd(lli a, lli b){
    if(a < b)return gcd(b, a);
    lli temp;
    while((temp = a%b)){
        a=b;
        b=temp;
    }
    return b;
}

struct nCr{
  vector<lli> f, rf;
  lli count=0;
  nCr(lli num): f(num), rf(num){
      count = num;
      f[0] = 1;
      rep1(i, num) f[i] = (f[i - 1] * i) % MOD;
      rep0(i, num+1) rf[i] = inv(f[i]);
  }
    
  lli inv(lli x) {
      lli res = 1;
      lli k = MOD - 2;
      lli y = x;
      while (k) {
          if (k & 1) res = (res * y) % MOD;
          y = (y * y) % MOD;
          k /= 2;
      }
      return res;
  }
  lli C(lli n, lli k) {
      lli a = f[n];
      lli b = rf[n-k];
      lli c = rf[k];
   
      lli bc = (b * c) % MOD;
   
      return (a * bc) % MOD;
  }
};

struct UF{
    vector<int> par,size;

    UF(int N) : par(N), size(N, 1){
        rep0(i,N)par[i] = i;
    }

    int root(int x){
        if (par[x] == x) return x;
        return par[x] = root(par[x]);
    }

    void unite(int x, int y){
        int rx = root(x);
        int ry = root(y);
        if(rx == ry) return;
        par[rx] = ry;
        size[rx] += size[ry];
    }

    bool same(int x, int y){
        int rx = root(x);
        int ry = root(y);
        return rx == ry;
    }

    int getSize(int x){
        return size[x];
    }
};

int main(){
  int tab[3][3];
  rep0(i,3)rep0(j,3)cin >> tab[i][j];

  rep1(i,2){
    rep0d(j,3)tab[i][j]-=tab[i][0]-tab[0][0];
  }
  rep1(i,2){
    rep0d(j,3)tab[j][i]-=tab[0][i]-tab[0][0];
  }

  int num=tab[0][0];
  rep0(i,3){
    rep0(j,3){
      if(num!=tab[i][j]){
        cout << "No";
        return 0;
      }
    }
  }
  cout << "Yes";

}