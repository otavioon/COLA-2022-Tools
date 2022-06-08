#include <bits/stdc++.h>
using namespace std;

#define FOR(i,a,b)    for (int i=(a)  ;i<(b) ;i++)
#define RFOR(i,a,b)   for (int i=(b)-1;i>=(a);i--)
#define REP(i,n)      for (int i=0    ;i<(n) ;i++)
#define RREP(i,n)     for (int i=(n)-1;i>=0  ;i--)
#define EACH(i,a,b)   for (int i=(a)  ;i<=(b);i++)
#define REACH(i,a,b)  for (int i=(b)  ;i>=(a);i--)
#define ALL(a)        (a).begin(),  (a).end()
#define RALL(a)       (a).rbegin(), (a).rend()

const int MOD = 1e9 + 7;
const int INF = 1 << 29;
const double EPS = 1e-10;

using ll = long long;
using P = pair<int,int>;
template<class T = int> using V = vector<T>;

template<class T> bool inline chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }
template<class T> bool inline chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }
template<class T = int> T inline input() { T x; cin >> x; return (x); }
template<class T> void inline print(T& x) { cout << x << '\n'; }
#define debug(x) cerr << #x << ": " << x << endl;

signed main(){
  cin.tie(nullptr);
  ios::sync_with_stdio(false);

  int N,K;
  cin >> N >> K;
  priority_queue<double> pq;
  int tmp;
  REP(i,N) { cin >> tmp; pq.push(tmp); }

  map<double,int> cut_count;
  REP(i,K) {
    double pre = pq.top(); pq.pop();
    if (cut_count[pre] == 0) cut_count[pre] = 1;
    double pos = pre * cut_count[pre]/(cut_count[pre] + 1);
    pq.push(pos);
    cut_count.emplace(pos,cut_count[pre]+1);
    cut_count.erase(pre);
  }

  cout << (int)ceil(pq.top()) << endl;

  return 0;
}

