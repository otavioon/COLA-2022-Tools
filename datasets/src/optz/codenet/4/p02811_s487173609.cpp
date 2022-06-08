#include<iostream>
#include<cstdio>
#include<vector>
#include<queue>
#include<map>
#include<unordered_map>
#include<stack>
#include<string>
#include<iomanip>
#include<algorithm>
#include<functional>
#include<cstring>
#include<utility>
#include<math.h>
using namespace std;


/**** Type Define ****/

typedef long long ll;
typedef pair<ll, ll> P;
typedef pair<ll, P> Q;

/**** Const List   ****/

const ll INF = 1LL << 60;
const ll mod = 1000000007;
const ll dx[4] = {1, 0, -1, 0};
const ll dy[4] = {0, -1, 0, 1};

/**** General Functions ****/
ll ketawa(ll n){
  ll a=0;
  while(n!=0){
    a+=n%10;
    n/=10;
  }
  return a;
}
ll RepeatSquaring(ll N, ll P, ll M){
    if(P==0) return 1;
    if(P%2==0){
        ll t = RepeatSquaring(N, P/2, M);
        return (t% M)*(t % M)%M;
    }
    return (N * RepeatSquaring(N, P-1, M))%M;
}
bool IsPrime(ll a){//order root a
  if(a==1)return false;
  for(int i=2;i*i<=a;i++){
    if(a%i==0&&a!=i){
      return false;
    }
  }
  return true;
}
ll gcd(ll a, ll b) {
  if (b == 0) return a;
  return gcd(b, a % b);
}
ll lcm(ll a, ll b){
    return a  / gcd(a, b)*b;
}

ll extgcd(ll a, ll b, ll& x, ll& y) {
  if (b == 0) {
    x = 1, y = 0; return a;
  }
  ll q = a/b, g = extgcd(b, a - q*b, x, y);
  ll z = x - q * y;
  x = y;
  y = z;
  return g;
}

ll invmod (ll a, ll m) { // a^-1 mod m
  ll x, y;
  extgcd(a, m, x, y);
  x %= m;
  if (x < 0) x += m;
  return x;
}

ll nCk(ll n, ll k, ll mod) {
  ll ans = 1;
  for (ll i = n, j = 1; j <= k; i--, j++) ans = (((ans * i) % mod) * invmod(j, mod)) % mod;
  return ans;
}

ll lmin(ll a, ll b) { return a > b ? b : a; };

ll lmax(ll a, ll b) { return a > b ? a : b; };

ll lsum(ll a, ll b) { return a + b; };

/**** Zip ****/

template <typename T>
class Zip {
  vector<T> d;
  bool flag;
public:
  Zip() {
    flag = false;
  }
  void add(T x) {
    d.push_back(x);
    flag = true;
  }
  ll getNum(T x) { // T need to have operator < !!
    if (flag) {
      sort(d.begin(), d.end());
      d.erase(unique(d.begin(), d.end()), d.end());
      flag = false;
    }
    return lower_bound(d.begin(), d.end(), x) - d.begin();
  }
  ll size() {
    if (flag) {
      sort(d.begin(), d.end());
      d.erase(unique(d.begin(), d.end()), d.end());
      flag = false;
    }
    return (ll)d.size();
  }
};

/**** Union Find ****/

class UnionFind {
  vector<ll> par, rank; // par > 0: number, par < 0: -par
public:
  void init(ll n) {
    par.resize(n, 1); rank.resize(n, 0);
  }
  ll getSize(ll x) {
    return par[find(x)];
  }
  ll find(ll x) {
    if (par[x] > 0) return x;
    return -(par[x] = -find(-par[x]));
  }
  void merge(ll x, ll y) {
    x = find(x);
    y = find(y);
    if (x == y) return;
    if (rank[x] < rank[y]) {
      par[y] += par[x];
      par[x] = -y;
    } else {
      par[x] += par[y];
      par[y] = -x;
      if (rank[x] == rank[y]) rank[x]++;
    }
  }
  bool isSame(ll x, ll y) {
    return find(x) == find(y);
  }
};

/**** Segment Tree ****/
class SegmentTree {
public:
  vector<pair<double, double>> node;//node[0]は使用しない
  ll n;//データの個数(nodeの最下層には何個並んでいるか)
  pair<double, double> initial_value;//初期値
public:
  void Init(ll n_,pair<double, double> initial_value_){
    n=1;
    while(n<n_)n*=2;
    node.resize(2*n);
    for(ll i=0;i<2*n;i++){
      node[i]=initial_value_;
    }
    initial_value=initial_value_;
  }
  void Update(ll k,pair<double, double> a){
    //node[k]をaにする
    //それに従って先祖も変わっていく
    k+=n;
    node[k]=a;
    while(k>1){
      k=k/2;
      node[k]=pair<double, double>(node[k*2].first*node[k*2+1].first,node[k*2].second*node[k*2+1].first+node[k*2+1].second);
    }
  }
  /*void Watch(){
    for(ll i=0;i<2*n;i++){
      cout<<node[i]<<endl;
    }
  }*/
  double Query(){//[a,b)
    return node[1].first+node[1].second;
  }
};


/**** LIS ****/
ll lis(ll* a, ll n, ll* dp) {
  fill(dp, dp + n, INF);//INFを代入
  for (ll i = 0; i < n; i++) *lower_bound(dp, dp + n, a[i]) = a[i];
  return (ll)(lower_bound(dp, dp + n, INF) - dp);
}


/**** main function ****/
ll k,x;
int main(){
  cin>>k>>x;
  if(500*k>=x){
    cout<<"Yes"<<endl;
  }else{
    cout<<"No"<<endl;
  }
}
