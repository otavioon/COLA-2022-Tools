#include <bits/stdc++.h>
#define rep(i,n) for(int i=0;i<(n);++i)
#define ALL(A) A.begin(), A.end()

using namespace std;

typedef long long ll;
typedef pair<int, int> P;

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	char c[2][3] = {0};
	rep (i, 2) rep (j, 3) cin >> c[i][j];

	bool ok = true;
	rep (j, 3){
		if (c[0][j] != c[1][3-j-1]){
			ok = false;
			break;
		} // end if
	} // end rep

	cout << (ok ? "YES" : "NO") << endl;
	
	return 0;
}