#include "bits/stdc++.h"

#define debug(x) cout<<#x<<": "<<x<<endl
#define rep(i,n) for (int i=0;i<(n);i++)
#define FOR(i,a,b) for (int i=(a);i<=(b);i++)
#define all(a) (a).begin(),(a).end()
using namespace std;
typedef vector<int> VI;
typedef vector<vector<int>> VVI;
typedef long long ll;


void solve() {
#ifdef _WIN32
	istream &cin = ifstream("input.txt");
#endif

	int n, k;
	cin >> n >> k;
	set<char> s;
	rep(i, n) {
		char tmp;
		cin >> tmp;
		s.insert(tmp);
	}

	FOR(i, n, 100001) {
		string str = to_string(i);
		bool flag = true;
		for (auto x : s) {
			if (str.find(x) != string::npos) {
				flag = false;
				break;
			}
		}
		if (flag) {
			cout << i << endl;
			break;
		}
	}

}


int main() {
	cin.tie(0);
	ios::sync_with_stdio(false);


	solve();
	system("PAUSE");
	return 0;
}