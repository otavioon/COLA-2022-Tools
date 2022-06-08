#include "bits/stdc++.h"

#define MOD 1000000007
#define rep(i, n) for(ll i=0; i < (n); i++)
#define rrep(i, n) for(ll i=(n)-1; i >=0; i--)
#define ALL(v) v.begin(),v.end()
#define rALL(v) v.rbegin(),v.rend()
#define FOR(i, j, k) for(ll i=j;i<k;i++)
#define debug_print(var) cerr << #var << "=" << var <<endl;
#define DUMP(i, v)for(ll i=0;i<v.size();i++)cerr<<v[i]<<" "
#define fi first
#define se second

using namespace std;
typedef long long int ll;
typedef vector<ll> llvec;
typedef vector<double> dvec;
typedef pair<ll, ll> P;
typedef long double ld;
struct edge{ll x, c;};

ll mod(ll a, ll mod){
  ll res = a%mod;
  if(res<0)res=res + mod;
  return res;
}

ll modpow(ll a, ll n, ll mod){
  ll res=1;
  while(n>0){
    if(n&1) res=res*a%mod;
    a=a*a%mod;
    n>>=1;
  }
  return res;
}

ll modinv(ll a, ll mod){
  ll b=mod, u=1, v=0;
  while(b){
    ll t=a/b;
    a-=t*b; swap(a, b);
    u-=t*v; swap(u, v);
  }
  u%=mod;
  if(u<0)u+=mod;
  return u;
}

ll gcd(ll a, ll b){
  ll r = a%b;
  if(r==0) return b;
  else return gcd(b, a%b);
}

bool is_prime(ll n){
  ll i = 2;
  if(n==1)return false;
  if(n==2)return true;
  bool res = true;
  while(i*i <n){
    if(n%i==0){
      res = false;
    }
    i = i+1;
  }

  //if(i==1)res = false;
  if(n%i==0)res=false;
  return res;
}
/**************************************
** A main function starts from here  **
***************************************/
int main(){
  ll N, A, B;
  cin >> N >> A >> B;
  llvec h(N);
  rep(i, N)cin >> h[i];
  ll ok=1e9;
  ll ng= 0;
  while(abs(ok-ng)>1){
    ll m = (ok+ng)/2;
    ll ans = 0;
    rep(i, N){
      ans += max(0LL, (h[i]-m * B + A - B - 1)/(A-B));
    }
    //cerr << ok << " " << ng << " " << m << " " << ans <<endl;
    if(ans<=m){
      ok = m;
    }else{
      ng=m;
    }
  }
  cout << ok<<endl;
  return 0;
}
