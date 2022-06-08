#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>
using namespace std;

const int MAX = 200000;
const int MAX2 = 2147483647;

int main() {
	static int N, A[MAX];
	cin >> N;
	for (int i = 0;i < N;++ i) cin >> A[i];
	sort(A, A+N);

	int ans = 0;
	for (int i = 1 << 30;i > 1;i >>= 1) {
		for (int j = 0, k = N - 1;j < k;) {
			if (A[j] < 0) {
				++ j;
				continue;
			}
			if (A[k] < 0) {
				-- k;
				continue;
			}
			if (A[j] + A[k] < i) ++ j;
			else if (A[j] + A[k] > i) -- k;
			else {
				A[j] = A[k] = -1;
				++ ans;
			}
		}
	}
	cout << ans;
	return 0;
}
/*
31536000のコメント解説欄
ここテンプレで用意してるから、A問題とかだとこの先空欄の危険あり
また、コンテスト後に https://31536000.hatenablog.com/ で解説していると思うので、良かったら読んでねー

一番大きい方から貪欲に確定でACという電波を受信した
*/