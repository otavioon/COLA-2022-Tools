#include<iostream>
#include<algorithm>
#include<cstdint>
using namespace std; // 575

int main() {
	int N;
	cin >> N;
	static int A[100000], B[100000], C[100000];
	for (int i = 0;i < N;++ i) cin >> A[i];
	for (int i = 0;i < N;++ i) cin >> B[i];
	for (int i = 0;i < N;++ i) cin >> C[i];
	sort(A, A+N);
	sort(B, B+N);
	sort(C, C+N);
	int l = 0, r = 0;
	int64_t ans = 0;
	for (int i = 0;i < N;++ i) {
		while (l < N && A[l] < B[i]) ++ l;
		while (r < N && B[i] >= C[r]) ++ r;
		ans += l * (N - r);
	}
	cout << ans;
	return 0;
}
/*
31536000のコメント解説欄
ここテンプレで用意してるから、A問題とかだとこの先空欄の危険あり
また、コンテスト後に https://31536000.hatenablog.com/ で解説していると思うので、良かったら読んでねー

*/