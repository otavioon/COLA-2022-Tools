#include <set>
#include <cstdio>
using namespace std;

const int N = 1 << 20;
int n;
int a[N];
multiset <int> st;

int main() {
	scanf("%d", &n);
	for (int i = 0; i < n; ++ i) {
		scanf("%d", &a[i]);
		st.insert(a[i]);
	}
	int ans = 0;
	while (!st.empty()) {
		int x = *st.rbegin();
		st.erase(-- st.end());
		for (int i = 30; i; -- i) {
			int y = (1 << i) - x;
			if (st.find(y) != st.end()) {
				multiset <int> :: iterator it = st.lower_bound(y);
				st.erase(it);
				++ ans;
				break;
			}
		}
	}
	printf("%d\n", ans);
	return 0;
}