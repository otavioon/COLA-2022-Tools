#include <bits/stdc++.h>
using namespace std;

int main() {
	string s, t;
	int k;
	cin >> s >> k;
	t = s + s;
	long c = 0, d = 0;
	for (int i = 1; i < s.length(); i++)
		if (s[i - 1] == s[i])
			s[i] = '!', c++;
	for (int i = 1; i < t.length(); i++)
		if (t[i - 1] == t[i])
			t[i] = '!', d++;
	c += (d - c)*(k - 1);
	cout << (s.length() < 2 ? k / 2 : c) << endl;
	return 0;
}
