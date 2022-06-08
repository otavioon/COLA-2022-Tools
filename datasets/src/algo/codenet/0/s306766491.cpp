#include <bits/stdc++.h>
using namespace std;

#define rep(i, n) for (int i = (int)(0); i < (int)(n); ++i)
#define reps(i, n) for (int i = (int)(1); i <= (int)(n); ++i)
#define rrep(i, n) for (int i = ((int)(n)-1); i >= 0; i--)
#define rreps(i, n) for (int i = ((int)(n)); i > 0; i--)
#define irep(i, m, n) for (int i = (int)(m); i < (int)(n); ++i)
#define ireps(i, m, n) for (int i = (int)(m); i <= (int)(n); ++i)
#define FOR(e, c) for (auto &e : c)
#define SORT(v, n) sort(v, v + n);
#define vsort(v) sort(v.begin(), v.end());
#define rvisort(v) sort(v.begin(), v.end(), greater<int>());
#define all(v) v.begin(), v.end()
#define mp(n, m) make_pair(n, m);
#define cout(d) cout<<d<<endl;
#define coutd(d) cout<<std::setprecision(10)<<d<<endl;
#define cinline(n) getline(cin,n);
#define replace_all(s, b, a) replace(s.begin(),s.end(), b, a);
// #define int long long

using ll = long long;
using vi = vector<int>;
using vvi = vector<vi>;
using vll = vector<ll>;
using vvll = vector<vll>;
using pii = pair<int, int>;
using ul = unsigned long;

const int INF = 1e9;
const int MOD = 1e9+7;
const ll LINF = 1e18;

template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }

int GCD(int a, int b) { return b ? GCD(b, a%b) : a; }
int LCM(int a, int b) { return a * b / GCD(a, b); }


signed main()
{
  string s; ll k; cin>>s>>k;
  ll n=s.size();
  ll ans=0;
  
  if(n==1){
    ans=k/2;
    cout<<ans<<endl;
    return 0;
  }
  
  ll top=0;
  ll back=0;
  ll cnt=0;
  for(ll i=0;i<n;i+=cnt){
    cnt=1;
    for(ll j=i+1;j<n;j++){
      if(s[i]==s[j]) cnt++;
      else break;
    }
    if(i==0){
        top=cnt;
        continue;
    }
    if(i+cnt>=n){
        back=cnt;
        continue;
    }
    ans+=cnt/2;
  }
  
  ans*=k;
  
  if(top==n){
    ans=(n*k)/2;
  }else{
    if(s[0]==s[n-1]) ans+=(top+back)/2*(k-1)+top/2+back/2;
    else ans+=k*(top/2+back/2);
  }
  
  cout<<ans<<endl;
  return 0;
}