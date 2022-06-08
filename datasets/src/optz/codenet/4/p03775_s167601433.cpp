#include <bits/stdc++.h>
using namespace std;

/* REPmacro */
#define REP(i,n) for(int i=0,i##_len=(n);i<i##_len;++i)
#define REPR(i,n) for(int i=((int)(n)-1);i>=0;--i)
#define FOR(i,m,n) for(int i=(int)(m);i<(int)(n);++i)

/*alias*/
#define ALL(x) (x).begin(),(x).end()
#define SZ(x) ((int)(x).size())
#define F first
#define S second
#define PB push_back
#define EB emplace_back
#define MP make_pair 

#define y0 y3487465
#define y1 y8687969
#define j0 j1347829
#define j1 j234892
#define next asdnext
#define prev asdprev
#define itn int

/*using*/
using ll = long long;
using ull = unsigned long long;
using unsi = unsigned;
using vi = vector<int>;
using vvi = vector<vi>;
using vvvi = vector<vvi>;
using pii = pair<int, int>;
using db = double;
using plex = complex<double>;
using vs = vector<string>;

/*template*/
template<class T>inline bool amax(T &a, const T &b) { if (a<b) { a=b; return 1; } return 0; }
template<class T>inline bool amin(T &a, const T &b) { if (b<a) { a=b; return 1; } return 0; }

/*struct*/
struct aaa{
    aaa(){
        cin.tie(0); ios::sync_with_stdio(0); cout<<fixed<<setprecision(20);
    };
}aaaaaaa;

/* const */
const int INF = 1001001001;
const ll LINF = 1001001001001001001ll;
const int MOD = 1e9 + 7; //10^9
const db EPS = 1e-9;
const int dx[] = { 1, 1, 0, -1, -1, -1, 0, 1 }, dy[] = { 0, 1, 1, 1, 0, -1, -1, -1 };  //Counterclockwise from the 9o'clock direction
//Take the x-axis downward and the y-axis right

//#define int ll
//#define int long long

int n;

int f(int i, int j){
 
  string si = to_string(i);
  string sj = to_string(j);
  
  
  auto sis = si.size();
  auto sjs = sj.size();
  
  return max(sis,sjs);
  
  
}

  set<int> ans;
    
signed main()
{
  cin >> n;

  for(itn i = 1; i <= n; ++i){
    //j = n/i because n = i*j
    int j = n/i;
    ans.insert(f(i,j));
  }
  
  cout << *ans.begin() << endl;
  return 0;
}