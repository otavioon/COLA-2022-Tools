#include<iostream>
#include<algorithm>
#include<queue>
#include<string>
#include<unordered_map>
#include<map>
#include<cassert>
#include<deque>
#include<vector>
#include<random>
#define int long long
#define rep(i,n) for(int i=0;i<n;i++)
using namespace std;
const long long inf = 1145141919810000;
typedef pair<int, int> P;
int a[200005];
bool b[200005];
unordered_map<int, int>M;
signed main() {
	int n; cin >> n;
	rep(i, n)cin >> a[i];
	rep(i, n)M[a[i]]++;
	int ans = 0;
	rep(i, n) {
		for (int j = 31; j >= 0; j--) {
			int x = 1ll << j;
			x -=a[i];
			if (M[x]) {
				if (a[i] == x) {
					if (M[a[i]] >= 2) {
						M[a[i]] -= 2; ans++;
					}
				}
				else {
					if (M[a[i]]) {
						M[a[i]]--; M[x]--; ans++;
					}
				}
			}
		}
	}
	cout << ans << endl;
}
