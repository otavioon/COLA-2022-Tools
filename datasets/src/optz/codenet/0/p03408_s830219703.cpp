#include<iostream>
#include<string>
using namespace std;

int main() {
	int n, m, cnt = -1, existNum = -1, cardP[200][2], max = 0;
	string name,card[200];

	cin >> n;

	for (int i = 1; i <= n; i++) {
		cin >> name;
		for (int j = 0; j <= cnt; j++) {
			if (name == card[j]) {
				existNum = j;
				break;
			}

		}
			if (existNum == -1) {
				cnt++;
				card[cnt] = name;
				cardP[cnt][0]++;
			}
			else {
				cardP[existNum][0]++;
				existNum = -1;
			}
	}

	cin >> m;

	for (int i = 1; i <= m; i++) {
		cin >> name;
		for (int j = 0; j <= cnt; j++) {
			if (name == card[j]) {
				existNum = j;
				break;
			}
		}
			if (existNum == -1) {
				cnt++;
				card[cnt] = name;
				cardP[cnt][1]++;
			}
			else {
				cardP[existNum][1]++;
				existNum = -1;
			}
	}
	for (int i = 0; i <= cnt; i++) {
		if (cardP[i][0] - cardP[i][1] > max)
			max = cardP[i][0] - cardP[i][1];
	}

	cout << max;

	return 0;

}