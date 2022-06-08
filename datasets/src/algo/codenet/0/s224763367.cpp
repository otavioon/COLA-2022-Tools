#include <bits/stdc++.h>
#define rep(i,n) for(int i=0;i<n;++i)
#define all(x) (x).begin(),(x).end()
using namespace std;
const int INF=1145141919,MOD=1e9+7;
const int64_t LINF=8931145141919364364,LMOD=998244353;
// const int dy[]={0,-1,0,1,1,-1,-1,1};
// const int dx[]={1,0,-1,0,1,1,-1,-1};

int main() {
	string s; cin >> s;
	int64_t k; cin >> k;
	char only = s[0];
	bool flg = true;
	for(char c : s) {
		if(only != c) {
			flg = false;
		}
	}
	if(flg) {
		cout << s.size() * k / 2 << endl;
		return 0;
	}
	string ss = s;
	s += s;
	int n = s.size();
	s += '$';
	char pre = '0';
	int64_t cnt = 1;
	int64_t ans1 = 0, ans2 = 0;
	for(int i = 0; i < n; ++i) {
		if(s[i] != pre) {
			ans1 += cnt / 2;
			cnt = 1;
			pre = s[i];
			if(i >= n / 2) break;
		} else {
			cnt++;
		}
	}
	ss += '$';
	pre = '0';
	cnt = 1;
	for(int i = 0; i <= n / 2; ++i) {
		if(ss[i] != pre) {
			ans2 += cnt / 2;
			cnt = 1;
			pre = ss[i];
		} else {
			cnt++;
		}
	}
	cout << ans1 * (k - 1) + ans2 << endl;
	cerr << ans1 << " " << ans2 << endl;
	return 0;
}