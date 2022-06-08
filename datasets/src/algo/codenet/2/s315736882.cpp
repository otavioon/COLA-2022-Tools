#include <bits/stdc++.h>
using namespace std;

int N;
multiset <int> S;

int get(int x) {
	int res = 1;
	while (res <= x)
		res *= 2;
	return res;
}

int main() {
	scanf("%d", &N);
	while (N--) {
		int x;
		scanf("%d", &x);
		S.insert(x);
	}
	
	int ans = 0;
	while (!S.empty()) {
		int x = *S.rbegin();
		S.erase(S.find(x));
		if (S.empty())
			break;
		int pot = get(x);
		auto it = S.find(pot - x);
		if (it != S.end()) {
			S.erase(it);
			ans++;
		}
	}
	
	printf("%d\n", ans);
	
	return 0;
}