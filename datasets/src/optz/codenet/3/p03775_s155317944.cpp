#include <bits/stdc++.h>

using namespace std ;
typedef long long ll;
typedef string str;
typedef pair<int, int> pii;
typedef pair<ll,ll> pll ;
typedef vector<int> vint;
typedef vector<double> vdou ;
typedef vector<ll> vll;
typedef vector<vint> vvint;
typedef vector<str> vstr;
typedef vector<pii> vpii ;
typedef vector<pll> vpll ;

#define REP(i, n) for (ll (i) = 0; (i) < (ll)(n); i++) 
#define FOR(i, a, b) for(ll (i) = a; (i) < (ll)b; i++)
#define ALL(v) (v).begin(),(v).end()
#define MOD 1000000007
#define CHI 1000000000000000003
#define NIL -1
#define FI first
#define SE second
#define MP make_pair
#define PB push_back
#define NP next_permutation
#define SZ(x)  (ll)x.size()
#define SP(x)  setprecision((ll)x)

const int INF = 1e9;
const ll LINF = 1e18;
const double EPS = 1e-9;
const double PI = M_PI;
const int dx[4] = {1, 0, -1, 0};
const int dy[4] = {0, 1, 0, -1};
ll gcd(ll a, ll b) {return b ? gcd(b, a % b) : a;} //最大公約数
ll lcm(ll a, ll b) {return a / gcd(a, b) * b;} //最小公倍数

void yes(){
  cout <<"Yes"<<endl ;
}
void no(){
  cout <<"No"<<endl ;
}
//-----------------------------------------

vll yakusuu(ll n){
    vll ret ;
    for(ll i=1;i*i<=n;i++){
        if(n%i==0){
            ret.push_back(i) ;
            if(i*i!=n){
                ret.push_back(n/i) ;
            }
        }
    }
    sort(ALL(ret)) ;
    return ret ;
}












//-----------------------------------------
int main()
{
  cin.tie(0);
  ios::sync_with_stdio(false);
  ll n ;
  cin >> n ;
  vll bnm = yakusuu(n) ;
  vll ans ;
  REP(i,SZ(bnm)){
    ans[i] = max(log10(bnm[i]),log10(n/bnm[i])) ;
  }
  sort(ALL(ans)) ;
  cout << ans[0] <<endl ;
  
  
  
  
  return 0 ;
}


