#include<iostream>
#include<string>
using namespace std;
int main()
{
	string s;
	unsigned long k;
	cin >> s;
	cin >> k;
	unsigned long i, ans, len;
	len = s.length();

	if (k == 1) {
		ans = 0;
		for (i = 0; i < len - 1; i++) {
			if (s[i] == s[i + 1]) {
				ans++;
				s[i + 1] = '#';
			}
		}
		cout << ans << endl;
		return 0;
	}


	ans = 0;
	len = s.length();

	if (s[0] != s[len - 1]) {
		for (i = 0; i < len; i++) {
			if (s[i] == s[i + 1]) {
				ans++;
				s[i + 1] = '#';
			}
		}
		ans = ans * k;
		cout << ans << endl;
		return 0;
	}

	long sentou;
	for (i = 0; i < len - 1; i++) {
		if (s[0] != s[i])break;
	}
	sentou = i;

	long saigo;
	for (i = len - 1; i >0; i--) {
		if (s[0] != s[i])break;
	}
	saigo = i;

	if (sentou >= saigo) {
		ans = len * k / 2;
		cout << ans << endl;
		return 0;
	}

	for (i=sentou; i<saigo; i++) {
		if (s[i] == s[i + 1]) {
			ans++;
			s[i + 1] = '#';
		}
	}

	long sentousaigo = sentou + (len - saigo-1);

	ans = ans * k;
	ans += (sentousaigo / 2) * (k - 1);
	ans += sentou / 2 + saigo / 2;

	cout << ans << endl;
	return 0;
}
