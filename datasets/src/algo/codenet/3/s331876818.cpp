#include <bits/stdc++.h>
using namespace std;

//#pragma GCC optimize("O3")
//#pragma GCC target("sse4")

#define FOR(i, a, b) for(int i = (a); i < (b); ++i)
#define RFOR(i, b, a) for(int i = (b) - 1; i >= (a); --i)
#define ITER(it, a) for(__typeof(a.begin()) it = a.begin(); it != a.end(); it++)
#define FILL(a, value) memset(a, value, sizeof(a))

#define SZ(a) (int)((a).size())
#define ALL(a) a.begin(), a.end()
#define PB push_back
#define MP make_pair

typedef long long LL;
typedef pair<int, int> PII;

const double PI = acos(-1.0);
const int INF = 1000 * 1000 * 1000 + 7;
const LL LINF = (LL)INF * INF;

const int MAX = 1 << 17;

int a[MAX], b[MAX], c[MAX];

int main()
{
	//ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	int n;
	cin >> n;
	FOR(i, 0, n)
		cin >> a[i];
	FOR(i, 0, n)
		cin >> b[i];
	FOR(i, 0, n)
		cin >> c[i];
	sort(a, a + n);
	sort(b, b + n);
	sort(c, c + n);
	int ptr1 = 0, ptr2 = 0;
	LL ans = 0;
	FOR(i, 0, n)
	{
		while(ptr1 < n && a[ptr1] < b[i])
			ptr1++;
		while(ptr2 < n && c[ptr2] <= b[i])
			ptr2++;
		ans += (LL)ptr1 * (n - ptr2);
	}
	cout << ans << "\n";
	return 0;
}