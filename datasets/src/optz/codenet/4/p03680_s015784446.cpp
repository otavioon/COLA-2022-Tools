#include <iostream>
#include <vector>
#include<algorithm>
#include<string>
#include<stdio.h>
#include<map>
#include<math.h>
#include<queue>
using namespace std;
using ll = long long;
using ld = long double;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
const int MOD = 1000000007;
const int mod = 1000000007;
const int INF = 1000000001;
const long long LINF = 1e18;
const int MAX = 510000;

int main() {
	int n, cnt = 0, ans = -1;
	cin >> n;
	vector<int> a(n);
	vector<bool> s(n);
	s.at(0) = 1;
	for (int i = 0; i < n; i++) {
		cin >> a.at(i);
		
	}
	int d = a.at(0);
	for (int i = 0; i < n; i++) {
		d = a.at(d-1);
		cnt++;
		if (d == 2) {
			ans = cnt + 1;
			break;
		}
	}
	cout << ans << endl;
		return 0;

	}
