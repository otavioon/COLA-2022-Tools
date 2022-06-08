//#pragma GCC optimize("O3", "unroll-loops")
//#pragma GCC target("avx2")
#include<bits/stdc++.h>
#define FAST ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define FIXED cout << fixed << setprecision(12)
#define RANDOM srand(94385)
#define all(a) a.begin(), a.end()
#define shuffle(a) \
    for (int i = 0; i < sz(a); ++i) \
        swap(a[i], a[rand() % sz(a)]);
#define enter putchar('\n')
#define space putchar(' ')
#define Mem(a, x) memset(a, x, sizeof(a))
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

void debug_out() { cerr << '\n'; }
template<typename T, typename ...R>void debug_out(const T &f, const R &...r) {cerr << f << " ";debug_out(r...);}
#define debug(...) cerr << "[" << #__VA_ARGS__ << "]: ", debug_out(__VA_ARGS__);
inline ll read() {ll x = 0;int f = 0;char ch = getchar();while (ch < '0' || ch > '9') f |= (ch == '-'), ch = getchar();while (ch >= '0' && ch <= '9') x = (x << 3) + (x << 1) + ch - '0', ch = getchar();return x = f ? -x : x;}
inline void write(ll x) {if (x == 0) {putchar('0');return;}if (x < 0) {putchar('-');x = -x;}static char s[23];int l = 0;while (x != 0)s[l++] = x % 10 + 48, x /= 10;while (l)putchar(s[--l]);}
int lowbit(int x) { return x & (-x); }
template<class T>T big(const T &a1, const T &a2) { return a1 > a2 ? a1 : a2; }
template<typename T, typename ...R>T big(const T &f, const R &...r) { return big(f, big(r...)); }
template<class T>T sml(const T &a1, const T &a2) { return a1 < a2 ? a1 : a2; }
template<typename T, typename ...R>T sml(const T &f, const R &...r) { return sml(f, sml(r...)); }
template<class T, class U>inline void checkMin(T &x, U y) { if (y < x) x = y; }
template<class T, class U>inline void checkMax(T &x, U y) { if (y > x) x = y; }
template<class T, class U>inline bool ifMax(T &x, U y) {if (y > x) return x = y, true;return false;}
template<class T, class U>inline bool ifMin(T &x, U y) {if (y < x) return x = y, true;return false;}

const int M = 212345;// 2e5+5
const int inf = 0x3f3f3f3f;
const ll INF = 0x3f3f3f3f3f3f3f3f;
const int mod = 1000000007;// 1e9+7

// HAVE FREE OPEN IN MAIN FUNCTION

int n;
int a[M];
int b[M];


void init() {
    n=read();
    for (int i = 1; i <= n-1; ++i) {
        int tmp=read();
        b[i]=tmp;
        checkMax(a[i],tmp);
        checkMax(a[i+1],tmp);
    }
    for (int i = 1; i <= n-1; ++i) {
        checkMin(a[i],b[i]);
        checkMin(a[i+1],b[i]);
    }
    int ans=0;
    for (int j = 1; j <= n; ++j) {
        ans+=a[j];
    }
    write(ans),enter;
}

void solve() {

}

int main() {
    init();

    solve();

    return 0;
}