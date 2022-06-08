
#include <bits/stdc++.h>

#define all(x) (x).begin(), (x).end()
#define allp(x) (x)->begin(), (x)->end()

#define pb push_back


using namespace std;
void dout() { cerr << endl; }
//typedef long long ll;
template <typename Head, typename... Tail>
void dout(Head H, Tail... T) {
    cerr << H << ' ';
    dout(T...);
}

#define debug(x) cout << #x " = " << (x) << endl


using ll = long long;
using hll = __int128;
using pii = pair<ll, ll>;
using ld = double;
using pll = pair<long long, long long>;

template <typename T>
void do_uniq(vector<T> vec){
    sort(all(vec));
    vec.resize(unique(all(vec)) - vec.begin());
}


#ifdef _getchar_nolock
#else
#define _getchar_nolock getchar_unlocked
#endif

template <typename T>
void freadT(T &x) {
    x = 0;
    char ch = _getchar_nolock();
    ll sign = 1;

    while (!isdigit(ch)) {
        if (ch == '-')
            sign *= -1;
        ch = _getchar_nolock();
    }

    while (isdigit(ch)) {
        x = x * 10 + ch - '0';
        ch = _getchar_nolock();
    }

    x *= sign;
}

int fparse(string s, int start_indx) {
    int x = 0;

    while (isdigit(s[start_indx])) {
        x = x * 10 + s[start_indx] - '0';
        ++start_indx;
    }

    return x;
}

#define solvsh
//#define multi

#ifdef solvsh

//const int MAXN = 1e2 + 2;

//#define uint ll

ll mod = 998244353;

ll ml(ll a, ll b, ll mod){
    return (a * b) % mod;
}

ll add(ll a, ll b, ll mod){
    return (a + b) % mod;
}

ll b_p(ll b, ll p, ll mod) {
    if (p == 0)
        return 1;
    if (p % 2) return ml(b, b_p(b, p - 1, mod), mod);
    ll v = b_p(b, p >> 1, mod);
    return ml(v, v, mod);
}

ll get_b(ll e, ll mod){
    return b_p(e, mod - 2, mod);
}

clock_t timestamp_start = clock();
void time_calc()
{
    cerr << (ld)(clock() - timestamp_start) / CLOCKS_PER_SEC << "\n";
}

const int MAXN = 2e5 + 10;

const ld pi = acos(-1.0);

struct vec {
    ld x, y;

    vec(ld x, ld y) {
        this->x = x;
        this->y = y;
    }

    ld len() {
        return sqrt(x * x + y * y);
    }

    ld getang() {
        ld ret = acos(x / len());
        if (y < 0)
            return 2 * pi - ret;
        return ret;
    }

    vec operator*(ld coef) {
        return vec(x * coef, y * coef);
    }

    vec rotate(ld angle) {
        return vec(x * cos(angle) - y * sin(angle), x * sin(angle) + y * cos(angle));
    }

    vec operator-(vec other) {
        return vec(x - other.x, y - other.y);
    }
    vec operator+(vec other) {
        return vec(x + other.x, y + other.y);
    }
};


int parent[MAXN];
int rankk[MAXN];
int sz[MAXN];
bool usd[MAXN];

void make_set (int v) {
    parent[v] = v;
    rankk[v] = 0;
    sz[v] = 1;
    usd[v] = false;
}

int find_set (int v) {
    if (v == parent[v])
        return v;
    return parent[v] = find_set (parent[v]);
}

void union_sets (int a, int b) {
    a = find_set (a);
    b = find_set (b);
    if (a != b) {
        if (rankk[a] < rankk[b])
            swap (a, b);
        parent[b] = a;
        sz[b] += sz[a];
        if (rankk[a] == rankk[b])
            ++rankk[a];
    }
}
void prec() {

}

set<pair<int, pair<int, int>>> g[MAXN];

vector<int> verts[MAXN];
vector<pair<int, int>> e_primes[MAXN];


ll calc(int prime) {
    if (verts[prime].size() <= 1) return 0;
    ll ret = 0;

    for (auto e : verts[prime]) make_set(e);

    for (auto e : e_primes[prime]) {
        int x = e.second;
        int y = e.first;
        union_sets(x, y);
    }
    for (auto v : verts[prime]) {
        int s_n = find_set(v);
        if (usd[s_n]) {
            continue;
        }
        ret += sz[s_n] * (sz[s_n] - 1) / 2;
        usd[s_n] = true;
    }
    return ret;
}

#define minp(p) min((p).first, (p).second)

const int MAXROUND = 3e3 + 20;
const int MAXM = 550;

ll dp[MAXM][MAXM];
ll coef[MAXN];

void solve() {
    int n, k;
    cin >> n >> k;
    vector<int> v;
    ll maxx = 0;
    for (int i = 0; i < n; ++ i){
        ll curr;
        cin >> curr;
        maxx = max(maxx, curr);
        v.push_back(curr);
    }

    ld left = 0;
    ld right = maxx + 1;

    ld eps = 1e-6;

    while (right - left > eps) {
        ld mid = (left + right ) / 2;
        int cnt = k;
        for (auto e : v) {
            int curr = e / mid;
            cnt -= curr;
        }

        if (cnt >= 0) {
            right = mid;
        } else {
            left = mid;
        }
    }

    int answr = left;
    if (abs(left - answr) > 1e-4) ++ answr;

    cout << answr << "\n";
}

#else

void solve() {

}


#endif


void multisolve() {
//    prec();
    int t;
    cin >> t;
    prec();
//    scanf("%d", &t);

    int i = 1;
    while (t--) {
        printf("Case %d: \n", i++);
        solve();
//        cout << "\n";
    }
}

#define int int
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);
    cout << fixed << setprecision(5);
#ifdef multi
    multisolve();
#else
    solve();
//    gen();
#endif

}