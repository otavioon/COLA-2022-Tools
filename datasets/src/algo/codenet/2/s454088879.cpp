#include <bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < (int)(n); i ++)
#define rep1(i, n) for(int i = 1; i <= (int)(n); i ++)
#define MP make_pair

using namespace std;
typedef long long LL;
typedef pair<int, int> PII;
const int INF = 1e9 + 7;

multiset<int> S;

int main()
{
	int n, x;
	scanf("%d", &n);
	rep(i, n) {
		scanf("%d", &x);
		S.insert(x);
	}
	int ans = 0;
	while(!S.empty()) {
		multiset<int>::iterator it = S.end();
		int cur = *(--it);
		S.erase(it);
		if(S.empty()) continue;
		int sum = 1;
		for(; sum <= cur; sum <<= 1); 
		it = S.find(sum - cur);
		if(it != S.end()) {
			S.erase(it);
			ans ++;
		}
	}
	printf("%d\n", ans);
	return 0;
}