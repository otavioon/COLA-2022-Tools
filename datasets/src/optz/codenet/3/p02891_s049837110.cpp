#include <bits/stdc++.h>

using namespace std;

typedef long long LL;
typedef long long ULL;
typedef pair<int, int> pr;
typedef pair<LL, LL> lpr;
typedef pair<double, double> dpr;
typedef pair<long double, long double> ldpr;
//typedef complex<double> cp;

const int next_x[8] = {0, 1, -1, 0, 1, 1, -1, -1};
const int next_y[8] = {1, 0, 0, -1, 1, -1, -1, 1};
const int inf = 2147483647;
const LL linf = 1e18 + 5;
const double PI = acos(-1.0);

// #define DEBUG 1  //调试开关
struct IO
{
#define MAXSIZE (1 << 20)
#define isdigit(x) (x >= '0' && x <= '9')
    char buf[MAXSIZE], *p1, *p2;
    char pbuf[MAXSIZE], *pp;
#if DEBUG
#else
    IO() : p1(buf), p2(buf), pp(pbuf)
    {
    }
    ~IO() { fwrite(pbuf, 1, pp - pbuf, stdout); }
#endif
    inline char gc()
    {
#if DEBUG //调试，可显示字符
        return getchar();
#endif
        if (p1 == p2)
            p2 = (p1 = buf) + fread(buf, 1, MAXSIZE, stdin);
        return p1 == p2 ? -1 : *p1++;
    }
    inline bool blank(char ch)
    {
        return ch == ' ' || ch == '\n' || ch == '\r' || ch == '\t';
    }
    template <class T>
    inline void read(T &x)
    {
        register double tmp = 1;
        register bool sign = 0;
        x = 0;
        register char ch = gc();
        for (; !isdigit(ch); ch = gc())
            if (ch == '-')
                sign = 1;
        for (; isdigit(ch); ch = gc())
            x = x * 10 + (ch - '0');
        if (ch == '.')
            for (ch = gc(); isdigit(ch); ch = gc())
                tmp /= 10.0, x += tmp * (ch - '0');
        if (sign)
            x = -x;
    }
    inline void read(char *s)
    {
        register char ch = gc();
        for (; blank(ch); ch = gc())
            ;
        for (; !blank(ch); ch = gc())
            *s++ = ch;
        *s = 0;
    }
    inline void read(char &c)
    {
        for (c = gc(); blank(c); c = gc())
            ;
    }
    inline void push(const char &c)
    {
#if DEBUG //调试，可显示字符
        putchar(c);
#else
        if (pp - pbuf == MAXSIZE)
            fwrite(pbuf, 1, MAXSIZE, stdout), pp = pbuf;
        *pp++ = c;
#endif
    }
    template <class T>
    inline void write(T x)
    {
        if (x < 0)
            x = -x, push('-'); // 负数输出
        static T sta[35];
        T top = 0;
        do
        {
            sta[top++] = x % 10, x /= 10;
        } while (x);
        while (top)
            push(sta[--top] + '0');
    }
    template <class T>
    inline void write(T x, char lastChar)
    {
        write(x), push(lastChar);
    }
} io;

#define dbgs(x) #x << " = " << x
#define dbgs2(x, y) dbgs(x) << ", " << dbgs(y)
#define dbgs3(x, y, z) dbgs2(x, y) << ", " << dbgs(z)
#define dbgs4(w, x, y, z) dbgs3(w, x, y) << ", " << dbgs(z)

#define heap priority_queue
#define mst(s, x) memset(s, x, sizeof(s))
//#define mid ((l + r) >> 1)
#define fi first
#define se second
#define pb push_back
#define pf push_front
#define ppb pop_back
#define ppf pop_front
#define mp make_pair
#define all(x) x.begin(), x.end()
#define unq(x) x.erase(unique(x.begin(), x.end()), x.end())
#define rg register
#define fp(i, a, b) for (rg int i = (a), I = (b) + 1; i < I; ++i)
#define fd(i, a, b) for (rg int i = (a), I = (b)-1; i > I; --i)
#define go(u) for (rg int i = pre[u], v = e[i].v; i; i = e[i].next, v = e[i].v)
#define gow(u) for (rg int i = pre[u], v = e[i].v, w = e[i].w; i; i = e[i].next, v = e[i].v, w = e[i].w)
#define dbga(a, len)                       \
    {                                      \
        cout << #a << ": ";                \
        fp(i, 1, len) cout << a[i] << " "; \
        cout << endl;                      \
    }
#define ub upper_bound
#define lb lower_bound

const double eps = 1e-10;
const int MAXN = 1e6 + 5;
//const int N = 200 + 5;
const LL MAX = 1e10;

/*----------head----------*/

int n;
LL k,ans=0;
char s[MAXN];
deque<int> a;
int work()
{
    scanf("%s",s+1);
    scanf("%lld",&k);
    n=strlen(s+1);
    int cnt=1;
    fp(i,2,n+1)
        if(s[i]!=s[i-1])
            a.pb(cnt),cnt=1;
        else cnt++;
    if(a.size()==1) ans=(n*k)/2;
    else
    {
        if(s[1]==s[n])
        {
            ans+=a.front()/2;
            ans+=a.back()/2;
            ans+=(a.front()+a.back())/2*(k-1);
            a.ppb(),a.ppf();
        }
        for(auto x:a) ans+=k*(x/2);
    }
    return printf("%lld\n",ans);
}

// vector+lower_bound常数 < map/set
// map.find不会创建新元素 map[]会 注意空间
// 别对指针用memset
// 用位运算表示2^n注意加LL  1LL<<20
// 注意递归爆栈
// 注意边界
// 注意memset 多组样例会T

#define ONLINE_JUDGE

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
#ifdef ONLINE_JUDGE
    //freopen("invazia.in", "r",stdin );
    //freopen("invazia.out","w",stdout);
#endif // ONLINE_JUDGE
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
#endif
    work();
#ifndef ONLINE_JUDGE
    freopen("CON", "r", stdin);
    fflush(stdout);
    system("pause");
#endif
    return 0;
}