#include<algorithm>
#include<string>
#include<stdio.h>
#include<iostream>
#include<vector>
#include<queue>
#include<utility>
#include<functional>
#include<cassert>
using namespace std;

int main(void) {
	string s;
	long long int k, cnt = 0, ans = 0, front = 0, back = 0;
	cin >> s >> k;

	for (int i = 0; i < s.size()-1; i++) {
		if (s[i] == s[i + 1]) {
			for (i; (s[i] == s[i + 1]) && (i < s.size() - 1); i++) {
				cnt++;
			}
			cnt++;
			if (cnt == s.size()) {
				cout <<cnt/2 * k;
				return 0;
			}
			ans += cnt / 2;
			cnt = 0;
		}
	}

	if (s[0] == s[s.size()-1]) {
		for (int i = 0; s[i] == s[i + 1]; i++) {
			front++;
		}
		front++;

		for (int i = s.size()-1; s[i] == s[i -1]; i--) {
		back++;
		}
		back++;
		if (back % 2 == 1 && front % 2 == 1) {
			cout << (ans+1) * k- 1 << endl;
			return 0;
		}
	}

	cout << ans * k << endl;
	return 0;
}