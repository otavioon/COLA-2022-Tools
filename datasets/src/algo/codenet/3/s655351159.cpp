#include <iostream>
#include <algorithm>
using namespace std;

int main() {
	int n;
	cin >> n;
	int A[n],B[n],C[n];
	int a[n],b[n],c[n];
	int ans = 0;
	for (int i = 0;i < n;i++) {
		cin >> A[i];
	}
	for (int i = 0;i < n;i++) {
		cin >> B[i];
	}
	for (int i = 0;i < n;i++) {
		cin >> C[i];
	}
	sort(A,A + n);
	sort(B,B + n);
	sort(C,C + n);
	for (int i = 1;i < n + 1;i++) {
		for (int j = 1;j < n + 1;j++) {
			if (B[n - i] < C[n - j]) {
				c[i - 1] = j;
			}
		}
	}
	for (int i = 1;i < n + 1;i++) {
		for (int j = 1;j < n + 1;j++) {
			if (A[n - i] < B[n - j]) {
				ans += c[n - j];
			}
		}
	}
	cout << ans;
}