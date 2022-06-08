#include<iostream>
#include<cstdio>
#include<vector>
#include<queue>
#include<map>
#include<unordered_map>
#include<stack>
#include<string>
#include<algorithm>
#include<functional>
#include<cstring>
#include<utility>
#include<bits/stdc++.h>
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

ll gcd(ll a, ll b) {
  if (b == 0) return a;
  return gcd(b, a % b);
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

template <typename T>
class SegmentTree {
  ll n;
  vector<T> node;
  function<T(T, T)> fun, fun2;
  bool customChange;
  T outValue, initValue;
public:
  void init(ll num, function<T(T, T)> resultFunction, T init, T out, function<T(T, T)> changeFunction = NULL) {
    // changeFunction: (input, beforevalue) => newvalue
    fun = resultFunction;
    fun2 = changeFunction;
    customChange = changeFunction != NULL;
    n = 1;
    while (n < num) n *= 2;
    node.resize(2 * n - 1, init);
    outValue = out;
    initValue = init;
  }
  void valueChange(ll num, T value) {
    num += n-1;
    if (customChange) node[num] = fun2(value, node[num]);
    else node[num] = value;
    while (num > 0) num = (num - 1) / 2, node[num] = fun(node[num * 2 + 1], node[num * 2 + 2]);
  }
  T rangeQuery(ll a, ll b, ll l = 0, ll r = -1, ll k = 0) { // [a, b)
    if (r == -1) r = n;
    if (a <= l && r <= b) return node[k];
    if (b <= l || r <= a) return outValue;
    ll mid = (l + r) / 2;
    return fun(rangeQuery(a, b, l, mid, 2*k+1), rangeQuery(a, b, mid, r, 2*k+2));
  }
};

/**** LIS ****/
ll lis(ll* a, ll n, ll* dp) {
  fill(dp, dp + n, INF);//INFを代入
  for (ll i = 0; i < n; i++) *lower_bound(dp, dp + n, a[i]) = a[i];
  return (ll)(lower_bound(dp, dp + n, INF) - dp);
}


/**** main function ****/
ll a;
int main(){
	cin>>a;
	if(a%2==0){
		cout<<a<<endl;
	}else{
		cout<<a*2<<endl;
	}
}
