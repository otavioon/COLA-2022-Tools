#include <bits/stdc++.h>
#define trace1(x)                cout<<#x<<": "<<x<<endl
#define trace2(x, y)             cout<<#x<<": "<<x<<" | "<<#y<<": "<<y<<endl
#define trace3(x, y, z)          cout<<#x<<":" <<x<<" | "<<#y<<": "<<y<<" | "<<#z<<": "<<z<<endl
#define trace4(a, b, c, d)       cout<<#a<<": "<<a<<" | "<<#b<<": "<<b<<" | "<<#c<<": "<<c<<" | "<<#d<<": "<<d<<endl
#define trace5(a, b, c, d, e)    cout<<#a<<": "<<a<<" | "<<#b<<": "<<b<<" | "<<#c<<": "<<c<<" | "<<#d<<": "<<d<<" | "<<#e<< ": "<<e<<endl
#define trace6(a, b, c, d, e, f) cout<<#a<<": "<<a<<" | "<<#b<<": "<<b<<" | "<<#c<<": "<<c<<" | "<<#d<<": "<<d<<" | "<<#e<< ": "<<e<<" | "<<#f<<": "<<f<<endl
#define trace7(a, b, c, d, e, f , g) cout<<#a<<": "<<a<<" | "<<#b<<": "<<b<<" | "<<#c<<": "<<c<<" | "<<#d<<": "<<d<<" | "<<#e<< ": "<<e<<" | "<<#f<<": "<< f << " | "<< #g <<": "<<g<<endl
#define trace8(a, b, c, d, e, f , g , h) cout<<#a<<": "<<a<<" | "<<#b<<": "<<b<<" | "<<#c<<": "<<c<<" | "<<#d<<": "<<d<<" | "<<#e<< ": "<<e<<" | "<<#f<<": "<< f << " | " << #g <<": "<< g <<" | "<<#h<< ": " << h << endl
#define rep(i,a,b) for(int i=(int)(a);i<(int)(b);++i)
#define rrep(i,a,b) for(int i=(int)(a);i>=(int)(b);--i)
#define fore(x,a) for(auto &x:a)
#define all(a) (a).begin(),(a).end()
#define rall(a) (a).rbegin(),(a).rend()
#define isin(i,a,b) ((a) <= (i) && (i) <= (b))
#define uni(a) (a).erase(unique(all(a)),(a).end())
#define dup(x,y) (((x)+(y)-1)/(y))
#define fi first
#define se second
#define pb push_back
#define eb emplace_back
#define sz(a) ((int)(a).size())
#define v(T) vector<T>
#define vv(T) v(v(T))
using namespace std;
using ll  = long long;          using vi  = vector<int>;
using unit= unsigned;           using vl  = vector<ll>;
using ull = unsigned long long; using vvi = vector<vi>;
using P   = pair<int,int>;      using vvl = vector<vl>;
                                using vp  = vector<P>;
void _main(); int main(){ cin.tie(0); ios::sync_with_stdio(false); _main(); }
template<class T>string join(const v(T)&v){ stringstream s; rep(i,0,sz(v))s<<' '<<v[i]; return s.str().substr(1); }
template<class T>istream &operator>>(istream&i, v(T)&v){ fore(x,v){ i >> v; } return i; }
template<class T>ostream &operator<<(ostream&o, const v(T)&v){ o<<"["; fore(x,v)o<<x<<","; o<<"]"; return o; }
template<class T>ostream &operator<<(ostream&o, const deque<T>&v){ o<<"deq["; fore(x,v)o<<x<<","; o<<"]"; return o; }
template<class T>ostream &operator<<(ostream&o, const set<T>&v){ o<<"{"; fore(x,v)o<<x<<","; o<<"}"; return o; }
template<class T>ostream &operator<<(ostream&o, const unordered_set<T>&v){ o<<"{"; fore(x,v)o<<x<<","; o<<"}"; return o; }
template<class T>ostream &operator<<(ostream&o, const multiset<T>&v){ o<<"{"; fore(x,v)o<<x<<","; o<<"}"; return o; }
template<class T>ostream &operator<<(ostream&o, const unordered_multiset<T>&v){ o<<"{"; fore(x,v)o<<x<<","; o<<"}"; return o; }
template<class T1,class T2>ostream &operator<<(ostream &o, const pair<T1,T2>&p){ o<<"("<<p.fi<<","<<p.se<<")"; return o; }
template<class TK,class TV>ostream &operator<<(ostream &o, const map<TK,TV>&m){ o<<"{"; fore(x,m)o<<x.fi<<"=>"<<x.se<<","; o<<"}"; return o; }
template<class TK,class TV>ostream &operator<<(ostream &o, const unordered_map<TK,TV>&m){ o<<"{"; fore(x,m)o<<x.fi<<"=>"<<x.se<<","; o<<"}"; return o; }
template<class T>void YES(T c){ if(c) cout<<"YES"<<endl; else cout<<"NO"<<endl; }
template<class T>void Yes(T c){ if(c) cout<<"Yes"<< endl; else cout<<"No"<<endl; }
template<class T>void POSS(T c){ if(c) cout<<"POSSIBLE"<<endl; else cout<<"IMPOSSIBLE"<<endl; }
template<class T>void Poss(T c){ if(c) cout<<"Possible"<<endl; else cout<<"Impossible"<<endl; }
template<class T>void chmax(T &a, const T &b){ if(a<b) a=b; }
template<class T>void chmin(T &a, const T &b){ if(b<a) a=b; }
template<class T>T gcd(T a, T b){ return (b==0) ? a : gcd(b,a%b); }
template<class T>T lcm(T a, T b){ return a * (b / gcd(a,b)); }
const double  EPS = 1e-10;
const double  PI  = acos(-1.0);
const int     INF = 1001002003;
const ll      LINF= 1001002003004005006LL;
const int dx[] = { -1, 0, 1, 0 , -1,-1, 1, 1 };
const int dy[] = {  0, 1, 0,-1 , -1, 1,-1, 1 };

int N;
int ans;
vi L;
vi combination;

void func(const vi& a) {
  if (a[0] >= a[1] + a[2]) return;
  if (a[1] >= a[2] + a[0]) return;
  if (a[2] >= a[0] + a[1]) return;
  ++ans;
}

void comb(int offset, int k) {
  if (k == 0) {
    func(combination);
    return;
  }
  rep(i, offset, sz(L) - k + 1) {
    combination.push_back(L[i]);
    comb(i+1, k-1);
    combination.pop_back();
  }
}

void _main() {
  cin >> N;
  L.resize(N);
  fore(x, L) cin >> x;

  comb(0, 3);
  cout << ans << endl;
}