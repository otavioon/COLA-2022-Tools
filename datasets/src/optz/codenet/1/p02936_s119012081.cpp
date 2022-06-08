// includes
#include "bits/stdc++.h"
using namespace std;
// macros
#define ll long long
#define MOD  998244353 //1000000007 // 100000000  //
#define pii pair<ll, ll>
#define piii pair<ll, pii>
#define sz(x) ((ll)(x).size())
#define ft first
#define sd second
#define pb push_back
#define rep(i, n) for(ll i = 0; i < n; i++)
#define repr(i, n) for(ll i = n-1; i >= 0; i--)
#define itr(it, x) for(auto it = x.begin(); it != x.end(); it++)
#define mem(a, b) memset(a, (ll)b, sizeof(a))
#define all(v) v.begin(), v.end()
#define allr(v) v.rbegin(), v.rend()
#define edge(v, x, y) v[x].pb(y); v[y].pb(x);
#define popc __builtin_popcount
#define ANS(s) {cout << s << "\n"; return;}
// functions
template <typename T> void unique(T& c){c.erase(std::unique(c.begin(), c.end()), c.end());}
template <class T>bool chmax(T &a, const T &b){if(a < b){a = b; return 1;} return 0;}
template <class T>bool chmin(T &a, const T &b){if(a > b){a = b; return 1;} return 0;}
template <typename T> istream &operator>>(istream &is, vector<T> &vec){for(auto &v: vec)is >> v; return is;}
template <typename T> ostream &operator<<(ostream &os, const vector<T>& vec){for(int i = 0; i < vec.size(); i++){ os << vec[i]; if(i + 1 != vec.size())os << " ";} return os;}
template <typename T> ostream &operator<<(ostream &os, const set<T>& st){for(auto itr = st.begin(); itr != st.end(); ++itr){ os << *itr; auto titr = itr; if(++titr != st.end())os << " ";} return os;}
template <typename T> ostream &operator<<(ostream &os, const unordered_set<T>& st){for(auto itr = st.begin(); itr != st.end(); ++itr){ os << *itr; auto titr = itr; if(++titr != st.end())os << " ";} return os;}
template <typename T> ostream &operator<<(ostream &os, const multiset<T>& st){for(auto itr = st.begin(); itr != st.end(); ++itr){ os << *itr; auto titr = itr; if(++titr != st.end())os << " ";} return os;}
template <typename T> ostream &operator<<(ostream &os, const unordered_multiset<T>& st){for(auto itr = st.begin(); itr != st.end(); ++itr){ os << *itr; auto titr = itr; if(++titr != st.end())os << " ";} return os;}
template <typename T1, typename T2> ostream &operator<<(ostream &os, const pair<T1, T2> &p){os << "(" << p.first << ", " << p.second << ")"; return os;}
template <typename T1, typename T2> ostream &operator<<(ostream &os, const map<T1, T2> &mp){for(auto itr = mp.begin(); itr != mp.end(); ++itr){ os << "(" << itr->first << ", " << itr->second << ")"; auto titr = itr; if(++titr != mp.end())os << " "; } return os;}
template <typename T1, typename T2> ostream &operator<<(ostream &os, const unordered_map<T1, T2> &mp){for(auto itr = mp.begin(); itr != mp.end(); ++itr){ os << "(" << itr->first << ", " << itr->second << ")"; auto titr = itr; if(++titr != mp.end())os << " "; } return os;}
// constants
const ll N = 1e5+5;
const ll M = 1e6+5;
const ll A = 1e7+5;
const ll inf = 1e9;
const long long linf = 1LL << 60;
const double er = 1e-10;
const double pi = 3.141592653589793238463;
const ll lx[4] = {0, 1, -1, 0};
const ll ly[4] = {1, 0, 0, -1};
const ll dx[8] = {0, 0, 1, -1, 1, -1, 1, -1};
const ll dy[8] = {1, -1, 0, 0, 1, 1, -1, -1};
// io
struct fast_io{
  fast_io(){ios_base::sync_with_stdio(false); cin.tie(0); cout << fixed << setprecision(20);}
} fast_io_;

vector<ll> v[M];
ll a[M];

void dfs(ll u, ll p){
    a[u] += a[p];
    for(auto x: v[u])
    {
        if(x != p) dfs(x, u);
    }
}
void solve()
{
    ll n, m;
    cin >> n >> m;
    rep(i, n-1)
    {
        ll x, y; cin >> x >> y;
        edge(v, x, y);
    }
    rep(i, m)
    {
        ll p, x; cin >> p >> x; a[p] += x;
    }
    dfs(1, 0);
    rep(i, n) cout << a[i+1] << " ";
}

int main(int argc, char const* argv[])
{
    ll t = 1; //cin >> t;
    while(t--) {
        solve();
    }
    return 0;
}
