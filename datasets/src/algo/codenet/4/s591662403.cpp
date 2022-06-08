#include<iostream>
#include<vector>
#include<map>
#include<set>
#include<string>
#include<algorithm>
#include<numeric>
#include<cmath>
using namespace std;
typedef long long int ll;
#define rep(i,n) for(int i=0;i<(int)n;i++)
int main(void) {
	int n; cin >> n; int k; cin >> k;
	set<int> se;
	int x;
	rep(i, k) {
		cin >> x;
		se.insert(x);
	}
	bool f = 0;
	for (int i = n;; i++) {
		for (int s = i; s > 0; s /= 10) {
			if (se.count(s % 10)) {
				f = 1;
				break;
			}
		}
		if(!f) {
			cout << i << endl;
			return 0;
		}
		f = 0;
	}
	return 0;
}