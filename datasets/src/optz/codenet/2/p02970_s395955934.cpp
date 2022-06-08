#include<bits/stdc++.h>
using namespace std;

#define fastio ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL); 

#define ll long long
#define ff first
#define ss second
#define pb push_back
#define pf push_front
#define mp make_pair
#define pu push
#define pp pop_back
#define in insert
#define ld long double
#define forn(low,high,i) for(i = low;i < high;i++)
#define forrev(high,low,i) for(i = high; i >= low;i--)
#define trace(x) cerr << #x << ": " << x << " " << endl;
#define all(v) v.begin(),v.end()
#define sz(v) (int)v.size()
#define line cout << __LINE__;
#define prv(a) for(auto x : a) cout << x << ' ';cout << '\n';
#define decimal_digits cout << fixed << setprecision(15);
#define dbg2(a,b) cerr << #a << " = " << a << " " << #b << " = " << b << '\n';        
#define debug(x) cerr << __LINE__ << ' ' << #x << " = " << x << '\n';
#define dln cerr << '\n';
#define dsp cerr << ' ';
#define pln cout << '\n';
#define psp cout << ' ';

typedef unordered_map<int,int> umi;
typedef unordered_map<ll,ll> uml;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef vector<vi> vvi;
typedef vector<vl> vvl;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
typedef vector<pii> vpii;
typedef vector<pll> vpll;
mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());
const int inf = 1e9;
const ll INF = 1e18;
const ll mod = 1e9 + 7;

clock_t time_p = clock();

void ktj(){
  time_p = clock() - time_p;
  cerr << "Time elapsed : " << (float)(time_p)/CLOCKS_PER_SEC << "\n";
}

int main(){
  fastio
  ll n,i,j,k;
  string s, t;

  ll ans = 0;
  cin >> n >> k;

  ll span = 2*k + 1;

  for(i = 1; i <= n;){
    i += span;
    ans++;
  }

  cout << ans << '\n';

  ktj();
}
