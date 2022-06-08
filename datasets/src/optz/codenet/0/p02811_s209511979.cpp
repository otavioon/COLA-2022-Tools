#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef unsigned long long ULL;
#define rep(i,j,k) for(int i=j;i<k;i++)
#define all(x) (x).begin(),(x).end()
#define UNIQUE(v) v.erase( unique(v.begin(), v.end()), v.end() );
#define pb push_back
#define mp make_pair
#define BIG_NUM 2000000000
#define MOD 1000000007
#define EPS 0.000000001
const int  COMMAX = 510000;

long long fac[COMMAX], finv[COMMAX], inv[COMMAX];

int gcd(int a,int b){return b?gcd(b,a%b):a;}
int lcd(int a,int b){return a*b / gcd(a,b);}
// テーブルを作る前処理
void COMinit() {
  fac[0] = fac[1] = 1;
  finv[0] = finv[1] = 1;
  inv[1] = 1;
  for (int i = 2; i < COMMAX; i++){
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

struct UnionFind {
  vector<int> par; // par[i]:iの親の番号　(例) par[3] = 2 : 3の親が2
  vector<int> rank;
  int num;
  UnionFind(int N) : par(N) , rank(N) { //最初は全てが根であるとして初期化
    num = N;
    for(int i = 0; i < N; i++){
      par[i] = i;
      rank[i] = 0;
    }
  }

  int root(int x) { // データxが属する木の根を再帰で得る：root(x) = {xの木の根}
    if (par[x] == x) return x;
    return par[x] = root(par[x]);
  }

  void unite(int x, int y) { // xとyの木を併合
    int rx = root(x); //xの根をrx
    int ry = root(y); //yの根をry
    if (rx == ry) return; //xとyの根が同じ(=同じ木にある)時はそのまま
    if(rank[rx] < rank[ry]){
      par[rx] = ry;  
    }else{
      par[ry] = rx;
      if(rank[rx] == rank[ry])rank[rx]++;
    }
    num--;
  }

  bool same(int x, int y) { // 2つのデータx, yが属する木が同じならtrueを返す
    return root(x) == root(y);
  }
};

const int MS = 2;
const long long mod[] = {999999937LL, 1000000007LL}, base = 9973;
struct rolling_hash {
    int n;
    vector<long long> hs[MS], pw[MS];
    rolling_hash(){}
    rolling_hash(const string &s) {
        n = s.size();
        for (int i = 0; i < MS; i++) {
            hs[i].assign(n+1,0);
            pw[i].assign(n+1,0);
            hs[i][0] = 0;
            pw[i][0] = 1;
            for (int j = 0; j < n; j++) {
                pw[i][j+1] = pw[i][j]*base%mod[i];
                hs[i][j+1] = (hs[i][j]*base+s[j])%mod[i];
            }
        }
    }

    long long hash(int l, int r, int i) { return ((hs[i][r]-hs[i][l]*pw[i][r-l])%mod[i]+mod[i])%mod[i]; }

    bool match(int l1, int r1, int l2, int r2) {
        bool ret = 1;
        for (int i = 0; i < MS; i++) ret &= hash(l1,r1,i)==hash(l2,r2,i);
        return ret;
    }

    bool match(int l, int r, long long h[]) {
        bool ret = 1;
        for (int i = 0; i < MS; i++) ret &= hash(l,r,i)==h[i];
        return ret;
    }
};

int main(){
  int k,x;
  cin >> k >> x;
  cout << (500*k > x?"Yes":"No") << endl;
  return 0;
}
