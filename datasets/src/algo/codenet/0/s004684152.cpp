#include <cstdio>
#include <vector>
#include <cstring>
#include <algorithm>
using namespace std;

typedef long long ll;
const int Maxn = 100;

char s[Maxn + 5];
int K;
pair<int,int> t;

int main() {
#ifdef LOACL
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
#endif
	scanf("%s %d", s + 1, &K);
	int len = strlen(s + 1);
	ll ans1 = 0, ans2 = 0;
	for(int i = 1; i <= len;) {
		int j = i;
		while(j < len && s[j + 1] == s[i])
			j++;
		if(i == 1 && j == len) {
			printf("%lld\n", 1LL * K * len / 2);
			return 0;
		}
		if(i == 1) t = make_pair(i, j);
		else if(j == len) {
			if(s[1] == s[len]) {
				if(((j - i + 1) & 1) && ((t.second - t.first + 1) & 1))
					ans2 = K - 1;
			}
		}
		ans1 += 1LL * (j - i + 1) / 2;
		i = j + 1;
	}
	ans1 *= K;
	printf("%lld\n", ans1 + ans2);
	return 0;
}