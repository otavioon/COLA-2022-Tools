# include <iostream>
# include <algorithm>
# include <vector>
# include <string>
# include <set>
# include <map>
# include <cmath>
# include <iomanip>
# include <functional>
# include <utility>
# include <stack>
# include <queue>
# include <list>
# include <bitset>
# include <complex>
#include<limits.h>
#include<unordered_map>
#include<unordered_set>
#include<deque>
#include<cstdio>
typedef long long int ll;
#define FOR(i,a,n) for(int i=(ll)a;i<(ll)n;++i)
#define TFOR(i,n)FOR(i,0,n)
#define ALL(x) x.begin(),x.end();
const int INF = 1LL << 30;
const ll LLINF = 1LL << 60;
ll A[10000];
ll B[10000];
ll C[10000];
int n;
int main() {
	std::cin >> n;
	TFOR(i, n)std::cin >> A[i];
	TFOR(i, n)std::cin >> B[i];
	TFOR(i, n)std::cin >> C[i];
	std::sort(A,A+n); std::sort(B, B+n); std::sort(C, C+n);
	int ans = 0;
	int p = n-1;
	for (int i = 0; i < n;++i) {
		for (int j = p; j>= 0; --j) {
			if (B[j] > A[i]) {
				for (int k = n - 1; k >= 0;--k) {
					if (B[j] < C[k]) { ++ans;}
					else break;
				}
			}
			else {
				break;
			}
		}
	}
	std::cout << ans << std::endl;
	return 0;
}