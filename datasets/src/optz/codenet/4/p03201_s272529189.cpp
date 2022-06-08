#include <bits/stdc++.h>

#ifdef NON_SUBMIT
#define TEST(n) (n)
#else
#define TEST(n) ((void)0)
#endif

using namespace std;

vector<int> A;
set<pair<int, int>> P;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	TEST(freopen("input.txt", "r", stdin));
	TEST(freopen("output.txt", "w", stdout));
	TEST(freopen("debug.txt", "w", stderr));
	int N, ans = 0;
	cin >> N;
	A.resize(N);
	for (int i = 0; i < N; i++) {
		cin >> A[i];
		P.insert({ A[i],i });
	}
	for (int j = 1; j < 31; j++) {
		for (int i = 0; i < N; i++) {
			if (A[i] == -1) continue;
			auto it = P.lower_bound({ (1 << j) - A[i],0 });
			if (it != P.end() && it->first == (1 << j) - A[i]) {
				ans++;
				A[i] = A[it->second] = -1;
				P.erase(it);
				P.erase({ A[i],i });
			}
		}
	}
	cout << ans << '\n';
	return 0;
}