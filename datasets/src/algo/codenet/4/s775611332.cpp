#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;
typedef vector<vector<int>> Graph;
const int dx[4] = {1, 0, -1, 0};
const int dy[4] = {0, 1, 0, -1};
#define pi 3.14159265359
#define inf 2147483647
#define INF 9223372036854775807
#define mod 1000000007
#define mod2 998244353

int main() {
	int N, K; cin >> N >> K;
	set<char> D;
	for(int i = 0; i < K; i++) {
		char d; cin >> d;
		D.insert(d);
	}
	int ans = N;
	while(true) {
		string n = to_string(ans);
		bool flag = true;
		for(int i = 0; i < n.size(); i++) {
			if(D.count(n[i])) {
				flag = false;
				break;
			}
		}
		if(flag) {
			cout << ans << endl;
			return 0;
		}
		ans++;
	}
}