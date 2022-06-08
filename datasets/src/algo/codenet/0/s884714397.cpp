#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<sstream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<climits>
#include<cmath>
#include<string>
#include<vector>
#include<set>
#include<map>
#include<queue>
#include<numeric>
#include<functional>
#include<algorithm>
#include<bitset>
#include<tuple>
#include<unordered_set>
#include<unordered_map>
#include<random>
#include<array>
#include<cassert>
using namespace std;
#define INF (1<<29)
#define rep(i,n) for(int i=0;i<(int)(n);i++)
#define all(v) v.begin(),v.end()
#define uniq(v) v.erase(unique(all(v)),v.end())



long long calc(const string &s) {
	int r = 0;
	for (int i = 1; i < s.size(); i++) {
		if (s[i - 1] == s[i]) {
			r++;
			i++;
		}
	}
	return r;
}


int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	string s;
	int k;
	cin >> s >> k;

	if (s.size() == 1) {
		cout << k / 2 << endl;
		return 0;
	}

	long long ans = 1LL << 60;

	if (s.front() == s.back()){
		char c = s.front();
		long long x = 0, y = 0;
		for (int i = 0; i < s.size(); i++) {
			if (s[i] != c)break;
			x++;
		}
		for (int i = s.size() - 1; i >= 0; i--) {
			if (s[i] != c)break;
			y++;
		}

		if (x == s.size()) {
			cout << 1LL * x * k / 2 << endl;
			return 0;
		}

		string r = s.substr(x);
		string t = s.substr(0, s.size() - y);
		string mid = s.substr(x, s.size() - y - x);

		long long ans = calc(r) + calc(t) + calc(mid) * (k - 2) + (x + y) / 2 * (k - 1);

		cout << ans << endl;
	}
	else {
		long long ans = 0;
		for (int i = 1; i < s.size(); i++) {
			if (s[i-1] == s[i]) {
				ans++;
				i++;
			}
		}
		cout << ans * k << endl;
	}




	return 0;
}