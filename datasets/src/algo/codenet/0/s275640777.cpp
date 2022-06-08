#include <cstdio>
#include <algorithm>
#include <utility>
#include <cstring>

#define FOR(i, n) for(int i = 0; i < n; i++) 

#define pow CHANGETHENAMESTUPID

using namespace std;

typedef pair<int,int> pii;
typedef long long ll;

const int MAXN = 101;

char s[MAXN];
int k;

void load() {
	scanf("%s", s);
	scanf("%d", &k);
}

void solve() {
	ll x = 0;
	int n = strlen(s);
	bool bl = false, bl1 = false;
	for (int i = 1; i < n; i++) {
		if (s[i] == s[i-1]) {
			if (i == 1) bl1 = true;
			if (i == n-1) bl = true;
			x++; i++;
		}
	}
	x *= k;
	if (!bl && bl1) {
		if (n < 3 || s[2] != s[1]) {
			x = x;
		} else {
			x += (k-1);
		}
		bl = true;
	}
	if (!bl) {
		if (s[n-1] == s[0]) x += (k-1);
	}
	if (n == 1) {
		x = k / 2;
	}
	printf("%lld\n", x);
}

int main() {
	load();
	solve();
	return 0;
}
