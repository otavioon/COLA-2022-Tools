#include <stdio.h>

int main() {
	int n, m;
	char s[100][10];
	char t[100][10];

	scanf("%d", &n);
	for (int i = 0; i < n; i++) scanf("%s", &s[i]);
	scanf("%d", &m);
	for (int i = 0; i < m; i++) scanf("%s", &t[i]);

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
			for (int j = 0; j < 100; j++) {//memoにメモする
				bool tmp = true;
				for (int k = 0; k < 100; k++) if (memo[j][k] != 0) tmp = false;
				if (tmp) {
					for (int k = 0; k < 10; k++) memo[j][k] = s[i][k];
					memonum[j] = counter;//数を記録
					break;
				}
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
			for (int j = 0; j < 100; j++) {//memoにメモする
				bool tmp = true;
				for (int k = 0; k < 100; k++) if (memo[j][k] != 0) tmp = false;
				if (tmp) {
					for (int k = 0; k < 10; k++) memo2[j][k] = t[i][k];
					memonum2[j] = counter;//数を記録
					break;
				}
			}
		}
	}
	//debug
	for (int i = 0; i < 100; i++) {
		printf("memo[%d]=%s\n", i, memo[i]);
	}
	for (int i = 0; i < 100; i++) {
		printf("memo2[%d]=%s\n", i, memo2[i]);
	}
	//debug
	int answer = -100;
	for (int i = 0; i < 100; i++) {
		bool tmp = true;
		for (int j = 0; j < 100; j++) {
			if (memo[i] == memo2[j]) {
				if (memonum[i] - memonum2[j] > answer) {
					answer = memonum[i] - memonum2[j];
					tmp = false;
					break;
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
				break;
			}
		}
		if (tmp) if (-memonum2[i] > answer) answer = -memonum2[i];
	}
	printf("%d", answer);
	
}