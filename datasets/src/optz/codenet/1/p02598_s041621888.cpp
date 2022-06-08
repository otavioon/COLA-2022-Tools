#include <bits/stdc++.h>
#define ll long long
#define ls id << 1
#define rs id << 1 | 1
#define mem(array, value, size, type) memset(array, value, ((size) + 5) * sizeof(type))
#define memarray(array, value) memset(array, value, sizeof(array))
#define pb(x) push_back(x)
#define st(x) (1LL << (x))
#define pii pair<int, int>
#define mp(a, b) make_pair((a), (b))
#define Flush fflush(stdout)
#define vecfirst (*vec.begin())
#define veclast (*vec.rbegin())
#define vecall(v) (v).begin(), (v).end()
#define vecupsort(v) (sort((v).begin(), (v).end()))
#define vecdownsort(v, type) (sort(vecall(v), greater<type>()))
#define veccmpsort(v, cmp) (sort(vecall(v), cmp))
using namespace std;
const int N = 500050;
const int inf = 0x3f3f3f3f;
const ll llinf = 0x3f3f3f3f3f3f3f3f;
const ll mod = 998244353LL;
const double PI = acos(-1.0);
clock_t TIME__START, TIME__END;
void program_end()
{
#ifdef ONLINE
    printf("\nTime used: %.6lf(s)\n", ((double)TIME__END - TIME__START) / 1000);
    system("pause");
#endif
}
int n, k;
int a[N];
ll cal(double up, double goal)
{
    ll ret = 0;
    ret += floor(up / goal - 1e-9);
    return ret;
}

bool check(double x)
{
    ll sum = 0;
    for (int i = 1; i <= n; ++i)
    {
        sum += cal(a[i], x);
        if (sum > k)
            return 0;
    }
    return 1;
}

void solve()
{
    cin >> n >> k;
    int ans = 0;
    for (int i = 1; i <= n; ++i)
        scanf("%d", &a[i]), ans = max(ans, a[i]);
    double l = 1e-9, r = ans;
    int tot = 100;
    while (tot--)
    {
        double mid = (l + r) / 2;
        if (check(mid))
            r = mid, ans = ceil(mid);
        else
            l = mid;
    }
    printf("%d\n", ans);
}

int main()
{
    TIME__START = clock();
    int Test = 1;
    // scanf("%d", &Test);
    while (Test--)
        solve();
    TIME__END = clock();
    program_end();
    return 0;
}