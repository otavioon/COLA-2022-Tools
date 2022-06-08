#include <bits/stdc++.h>
using namespace std;

//repetition
#define FOR(i,a,b) for(ll i=(a);i<(b);++i)
#define rep(i, n) for(ll i = 0; i < (ll)(n); i++)

//container util
#define all(x) (x).begin(),(x).end()

//typedef
typedef long long ll;
typedef vector<int> VI;
typedef vector<VI> VVI;
typedef vector<ll> VLL;
typedef vector<VLL> VVLL;
typedef vector<string> VS;
typedef pair<int, int> PII;
typedef pair<ll, ll> PLL;

//const value
//const ll MOD = 1e9 + 7;
//const int dx[] = {0,1,0,-1};//{0,0,1,1,1,-1,-1,-1};
//const int dy[] = {1,0,-1,0};//{1,-1,0,1,-1,0,1,-1};

//conversion
inline int toInt(string s) {int v; istringstream sin(s);sin>>v;return v;}
inline ll toLL(string s) {ll v; istringstream sin(s);sin>>v;return v;}
template<class T> inline string toString(T x) {ostringstream sout;sout<<x;return sout.str();}


int main(){
  ios::sync_with_stdio(false);
  cin.tie(0);
  string s;
  ll k;
  ll ans = 0;


  deque<ll> len;
  ll cnt = 0;
  cin >> s >> k;
  bool endFlag = false;
  rep(i,s.size()-1){
    if(s[i] == s[i+1]) cnt++;
    else if(cnt > 0){
      len.push_back(cnt+1);
      cnt = 0;
    }
    if(i + 1 == s.size() - 1 && cnt > 0) {
      len.push_back(cnt+1);
      endFlag = true;
    }
  }
  // cerr << "len = "; for(ll x: len) cerr << x  << " "; cerr << endl;
  if(len.empty()){
    cout << 0 << endl;
    return 0;
  }

  if(len.back() == s.size()){
    cout << ((ll)(s.size()) * k) / 2LL << endl;
    return 0;
  }

  if(s[0] == s.back()){
    if(s[0] != s[1]) len.push_front(1);
    if(s.back() != s.at(s.size() - 2)) len.push_back(1);
    ans += len[0]/2LL + len.back()/2LL + (len[0] + len.back())*(k-1)/2LL;

    FOR(i,1,len.size()-1) ans += len[i]*k/2LL;
    cout << ans << endl;
    return 0;
  }

  for(ll x: len) ans += x/2LL;
  ans *= k;
  cout << ans << endl;

  return 0;
}
