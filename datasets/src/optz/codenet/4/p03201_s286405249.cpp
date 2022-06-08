#include <bits/stdc++.h>

#define st first
#define nd second
#define all(x) (x).begin(), (x).end()

using namespace std;
using namespace placeholders;

typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

template <class T> void mini(T &l, T r){l = min(l, r);}
template <class T> void maxi(T &l, T r){l = max(l, r);}

template <class TH> void _dbg(const char *sdbg, TH h){cerr << sdbg << "=" << h << "\n";}
template <class TH, class ...TA> void _dbg(const char *sdbg, TH h, TA... a){
	while (*sdbg != ','){cerr << *sdbg++;}cerr << "=" << h << ","; _dbg(sdbg + 1, a...);
}
template <class T> ostream &operator <<(ostream &os, vector<T> V){
	os << "["; for (auto vv: V) os << vv << ","; return os << "]";
}
template <class L, class R> ostream &operator <<(ostream &os, pair<L, R> P){
	return os << "(" << P.st << "," << P.nd << ")";
}

#ifdef SFIC
	#define eput(...) _dbg(#__VA_ARGS__, __VA_ARGS__)
#else
	#define eput(...) 218
#endif

const int N = 2E5 + 10;

int n;
int a[N];

int main(){
	scanf("%d", &n);
	for (int i = 0; i < n; ++i)
		scanf("%d", a + i);
	sort(a, a + n);
	int ans = 0;
	set<pii> lst;
	for (int i = 0; i < n; ++i)
		lst.emplace(a[i], i);
	for (int i = n - 1; i >= 0; --i){
		if (a[i] == 0)
			continue;
		lst.erase(pii(a[i], i));

		int t = 1 << 32 - __builtin_clz(a[i]);
		eput(i, a[i], t);
		auto p = lst.lower_bound(pii(t - a[i], 0));
		if (p != lst.end() && p->st == t - a[i]){
			++ans;
			a[p->nd] = 0;
			lst.erase(p);
		}
	}
	printf("%d\n", ans);
	return 0;
}
