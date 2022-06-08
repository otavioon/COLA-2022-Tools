#include <bits/stdc++.h>
#define rep(i,n) for(int i=0;i<(n);++i)
using namespace std;
typedef long long ll;
typedef pair<int, int> P;

int c[3][3];

int main() {
	rep(i, 3)rep(j, 3) cin >> c[i][j];
	int res = 0;
	rep(i, 3)rep(j, 3) res += c[i][j];
	if (res % 3 == 0) puts("Yes");
	else puts("No");
	return 0;
}
