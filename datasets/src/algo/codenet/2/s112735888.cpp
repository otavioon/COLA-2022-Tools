#include <cstdio>
#include <set>
int n, ans;
std::multiset<int> st;

int main() {
	int i, a, x, y;
	scanf("%d", &n);
	for(i=0; i<n; i++) scanf("%d", &a), st.insert(a);
	while(!st.empty()) {
		x = *st.rbegin();
		st.erase(st.find(x));
		for(y=1; y<=x; y<<=1);
		std::multiset<int>::iterator it = st.find(y-x);
		if(it != st.end()) ans++, st.erase(it);
	}
	printf("%d", ans);
	return 0;
}