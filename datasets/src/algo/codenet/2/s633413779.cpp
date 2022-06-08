
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int n, ans;
multiset<int> st;//因为数据可能重复，所以用multiset

int main() {
	scanf("%d", &n);
	for (int i = 1; i <= n; ++i) {
		int x;
		scanf("%d", &x);
		st.insert(x);
	}
	while (!st.empty()) {
		ll v = *--st.end();//取st最后一位数据
		st.erase(--st.end());//将最后一位数据抹去，避免下面find找到自己
		for (int i = 0; i <= 30; ++i) {//2^32是int范围内的极限,循环int内的2的幂
			ll t = (1 << i) - v;
			if (st.find(t) != st.end()) {//如果t在st中存在，抹去，ans++，并且break
				++ans; st.erase(st.find(t)); break;
			}
		}
	}
	printf("%d", ans);
}
