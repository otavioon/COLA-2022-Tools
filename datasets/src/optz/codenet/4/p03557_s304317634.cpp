#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ld long double
#define rep(i,n) for(int i = 0; i < (int)(n); i++)
#define repo(i,n) for(int i = 1; i < (int)(n); i++)
#define pb push_back
#define mp make_pair
#define np next_permutation
#define umap unordered_map
#define lb lower_bound
#define ub upper_bound
#define fi first
#define se second
#define all(x) (x).begin(),(x).end()
#define mod 1000000007
#define pi acos(-1.0)
ll gcd(ll x, ll y) { return y ? gcd(y, x % y) : x; }
ll lcm(ll x, ll y) { return x / gcd(x, y) * y; }
ll jou(ll N, ll P){if(P==0) return 1;
    if(P%2==0){ll t = jou(N, P/2);return t*t % mod;
    }return (N * jou(N, P-1)) % mod;}  //jou(n,mod-2)で逆元
//intの最大値2147483647 ≒ 2×10^9
//long longの最大値9223372036854775807 ≒ 9×10^18
//'0'+=16;        で大文字に
//'大文字'+=32;    で小文字に
//  cout << fixed << setprecision (20);   小数点以下2０桁まで
//実行時間制約2秒では２×10^8回くらいまで計算できる



int main(){
  ll n;
  cin>>n;
  
  vector<ll> a(n);
  vector<ll> b(n);
  vector<ll> c(n);
  rep(i,n){
  cin>>a[i];
  }
  rep(i,n){
  cin>>b[i];
  }
  rep(i,n){
  cin>>c[i];
  }  
  
  sort(all(a));
  sort(all(c));
  
  ll ans=0;
  rep(i,n){
    auto x=lb(all(a),b[i]);
    auto y=ub(all(c),b[i]);
    ans+=(x-a.begin())*(c.end()-y); 
  }
  
  
  cout << ans << endl;
}
