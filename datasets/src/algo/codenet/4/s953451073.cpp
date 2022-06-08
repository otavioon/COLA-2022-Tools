#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
#define all(v) v.begin(), v.end()
using namespace std;
typedef long long ll;

int main() {
	int n, k;
	cin >> n >> k;
	set<int> d;
	rep(i, k) {
		int tmp;
		cin >> tmp;
		d.insert(tmp);
	}
	for(int i = n; ; i++) {
		bool ok = true;
		set<int> now;
		int tmp = i;
		while(tmp) {
			now.insert(tmp%10);
			tmp /= 10;
		}
		for(int t: now) {
			if(d.count(t)) ok = false;
		}
		if (ok) {
			cout << i << endl;
			return 0;
		}
	}
	
	return 0;
}