#include <iostream>
#include <string>
using namespace std;
typedef long long ll;

int main() {

	string S;
	cin >> S;

	ll k;
	cin >> k;

	int lng = S.size();

	int flag = 0;
	for (string::size_type i = 1; i < S.size(); i++) {
		if (S[i] != S[i - 1]) {
			flag = 1;
		}
	}

	ll cnt = 0;

	int flag2 = 0;
	if (flag == 0 && lng%2==1) {//奇数
		ll a = (lng * k) / 2;
		cout << a << endl;
	}
	else {
		if (lng == 1) cout << k / 2 << endl;
		else {
			for (string::size_type i = 1; i < S.size();) {
				if (S[i] == S[i - 1]) {
					cnt++;
					i += 2;
				}
				else {
					i++;
				}
			}

			if (S[0] == S[S.size() - 1] && S[S.size() - 1] != S[S.size() - 2]) {
				flag2 = 1;
			}

			if (flag2 == 1) {
				if (k == 1) cout << cnt << endl;
				else cout << cnt * k + k - 1 << endl;
			}
			else cout << cnt * k << endl;
		}
	}

	return 0;

}