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
#define FOR(i,a,n) for(int i=(int)a;i<(int)n;++i)
#define TFOR(i,N)FOR(i,0,N)
#define ALL(x) x.begin(),x.end();
const int INF = 1LL << 30;
const ll LLINF = 1LL << 60;
ll A[1000000];
ll B[1000000];
ll C[1000000];
int n;
int main() {
	std::cin >> n;
	TFOR(i, n)std::cin >> A[i];
	TFOR(j, n)std::cin >> B[j];
	TFOR(k, n)std::cin >> C[k];
	std::sort(A,A+n); std::sort(B, B+n); std::sort(C, C+n);
	ll ans = 0;
	for (int i = 0; i < n;++i) {
		for (int j = n-1; j>= 0; --j) {
			if (B[j] > A[i]) {
				for (int k = n - 1; k >= 0;--k) {
					if (B[j] < C[k])++ans;
					else break;
				}
			}
			else 	break;
		}
	}
	std::cout << ans << std::endl;
	return 0;
}