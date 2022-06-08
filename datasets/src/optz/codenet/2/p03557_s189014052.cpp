#include<bits/stdc++.h>
typedef long long ll;
typedef unsigned long long ull;
using namespace std;
#define pb push_back
int dy[]={0, 0, 1, -1, 1, 1, -1, -1};
int dx[]={1, -1, 0, 0, 1, -1, -1, 1};

#define FOR(i,a,b) for (int i=(a);i<(b);i++)
#define RFOR(i,a,b) for (int i=(b)-1;i>=(a);i--)
#define REP(i,n) for (int i=0;i<(n);i++)
#define RREP(i,n) for (int i=(n)-1;i>=0;i--)
#define mp make_pair
#define fi first
#define sc second
int n;
int a[3][100000];
ll dp[3][100000];
int main(){
	cin >> n;
	REP(i,3) {
		REP(j,n) {
			cin >> a[i][j];
		}
	}

	REP(i,3) {
		sort(&a[i][0],&a[i][0] + n);
	}

	REP(i,n) {
		dp[2][i] = 1;
	}

	RREP(i,2)  {
		int last = n - 1;
		RREP(j,n) {
			ll sum = 0;

			if(j + 1 < n) {
				sum += dp[i][j + 1];
			}
			while(last >= 0 && a[i + 1][last] > a[i][j]) {
				sum += dp[i + 1][last];
				last--;
			}
			dp[i][j] = sum;
		}
	}
	ll ans = 0;
	REP(i,n) {
		ans += dp[0][i];
	}
	cout << ans << endl;
	return 0;
}
