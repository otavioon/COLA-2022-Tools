#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, j, n) for (ll i = j; i < n; i++)
#define all(x) (x).begin(),(x).end()
#define INF (1000000000)
#define MOD (1000000007)
#define MAX (500000)
#define pii pair<int, int>

/////////////////////////////////////////////////////////

class XY{
public:
  ll x, y;
  XY() {x = y = 0;}
  XY(ll u, ll v) {x = u; y = v;}
};

class e{
public:
  ll a, b;
  e() {a = b = -1;}
  e(ll u, ll v) {a = u; b = v;}
};

template<typename T1, typename T2>
void chmin(T1 &a, T2 b) {if(a > b) a = b;}
template<typename T1, typename T2>
void chmax(T1 &a, T2 b) {if(a < b) a = b;}

template<typename T1, typename T2>
ll mypow(T1 a, T2 n){
  if(n == 0) return 1;
  if(n == 1) return a;
  if(n % 2) return a * mypow(a, n - 1);
  ll tmp = mypow(a, n / 2);
  return tmp * tmp;
}

template<typename T>
int BS(vector<T> &V, int left, int right, T key){
  int mid = (left + right) / 2;
  if(V[mid] <= key) left = mid;
  else right = mid;
  if(right - mid == 1) return left;
  else return BS(V, left, right, key);
}

ll comb(ll n, ll r){
	ll res = 1;
  rep(i, 0, r){
    res *= n - i;
    res /= i + 1;
  }
  return res;
}

template<typename T>
T euclid(T a, T b){
  if(b == 0) return a;
  else return euclid(b, a % b);
}

vector<ll> fact(MAX, 0), fact_inv(MAX, 0);

ll pow_mod(ll a, ll b){
	ll res = 1;
	while(b > 0){
		if(b & 1) res = res * a % MOD;
		a = a * a % MOD;
		b >>= 1;
	}
	return res;
}

void prepare_comb_mod(ll n){
	fact[0] = 1LL;
	for(ll i = 0; i < n; i++) fact[i+1] = fact[i] * (i + 1) % MOD;
	fact_inv[n] = pow_mod(fact[n], MOD - 2);
	for(ll i = n - 1; i >= 0; i--) fact_inv[i] = fact_inv[i + 1] * (i + 1) % MOD;
}

ll comb_mod(ll n, ll r){
	return (fact[n] * fact_inv[r]) % MOD * fact_inv[n - r] % MOD;
}

/////////////////////////////////////////////////////////

void Main() {
  string S; cin >> S;
  string T = S + S;
  ll K; cin >> K;
  ll s = 0, t = 0;
  ll res = 0;

  bool same = true;
  rep(i, 0, S.size()){
    if(S[i] != S[0]) same = false;
  }
  
  rep(i, 0, S.size() - 1){
    if(S[i] == S[i + 1]){
      S[i + 1] = '?';
      s++;
    }
  }
  rep(i, 0, T.size() - 1){
    if(T[i] == T[i + 1]){
      T[i + 1] = '?';
      t++;
    }
  }
  res = s + (K - 1) * (t - s);
  
  if(same){
    if(S.size() % 2){
      if(K % 2) res = t * ((K - 1) / 2) + s;
      else res = t * (K / 2);
    }else{
      res = K * s;
    }
  }
  cout << res << endl;
}

/////////////////////////////////////////////////////////

int main(){
  cin.tie(nullptr);
  ios_base::sync_with_stdio(false);
  cout << std::fixed << std::setprecision(15);

  Main();
}
