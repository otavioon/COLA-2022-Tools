#include <stdio.h>

int main() {
	int n, m;
	char s[100][10];
	char t[100][10];

	scanf("%d", &n);
	for (int i = 0; i < n; i++) scanf("%s", &s[i]);
	scanf("%d", &n);
	for (int i = 0; i < n; i++) scanf("%s", &s[i]);

	char memo[100][10];
	for (int i = 0; i < 100; i++) for (int j = 0; j < 10; j++) memo[i][j] = 0;
	int memonum[100];
	for (int i = 0; i < 100; i++) memonum[i] = 0;

	for (int i = 0; i < n; i++) {
		bool a = true;
		for (int j = 0; j < 100; j++) {
			if (s[i] == memo[j]) a = false;
		}
		int counter = 0;
		if (a) {//memoになかったら
			for (int j = 0; j < n; j++) {
				if (s[i] == s[j]) counter++;
			}
			counter--;//余分を引く
			for (int j = 0; j < 100; j++) {//memoにメモする
				if (memo[j] == 0) for (int k = 0; k < 10; k++) memo[j][k] = s[i][k];
				memonum[j] = counter;//数を記録
			}
		}
	}

	char memo2[100][10];
	for (int i = 0; i < 100; i++) for (int j = 0; j < 10; j++) memo2[i][j] = 0;
	int memonum2[100];
	for (int i = 0; i < 100; i++) memonum2[i] = 0;

	for (int i = 0; i < n; i++) {
		bool a = true;
		for (int j = 0; j < 100; j++) {
			if (t[i] == memo2[j]) a = false;
		}
		int counter = 0;
		if (a) {//memoになかったら
			for (int j = 0; j < n; j++) {
				if (t[i] == t[j]) counter++;
			}
			counter--;//余分を引く
			for (int j = 0; j < 100; j++) {//memoにメモする
				if (memo2[j] == 0) for (int k = 0; k < 10; k++) memo2[j][k] = t[i][k];
				memonum2[j] = counter;//数を記録
			}
		}
	}

	int answer = -100;
	for (int i = 0; i < 100; i++) {
		bool tmp = true;
		for (int j = 0; j < 100; j++) {
			if (memo[i] == memo2[j]) {
				if (memonum[i] - memonum2[j] > answer) {
					answer = memonum[i] - memonum2[j];
					tmp = false;
				}
			}
		}
		if (tmp) if (memonum[i] > answer) answer = memonum[i];
	}
	
	for (int i = 0;i < 100; i++) {
		bool tmp = true;
		for (int j = 0; j < 100; j++) {
			if (memo2[i] == memo[j]) {
				tmp = false;
			}
		}
		if (tmp) if (-memonum2[i] > answer) answer = -memonum2[i];
	}
  printf("%d\n",answer);
}