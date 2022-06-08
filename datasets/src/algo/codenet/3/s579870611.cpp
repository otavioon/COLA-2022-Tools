#include<iostream>
#include<algorithm>
using namespace std;
const int INF = 1145140000;
int a[114514], b[114514], c[114514];
int main() {
	int n; cin >> n;
	for (int i = 0; i < n; i++)cin >> a[i]; sort(a, a + n);
	for (int i = 0; i < n; i++)cin >> b[i]; sort(b, b + n); b[n] = INF;
	for (int i = 0; i < n; i++)cin >> c[i]; sort(c, c + n); c[n] = INF;
	int d[114514] = {}; int j = 0;
	for (int i = 0; i < n; i++) {
		while (c[j] <= b[i])j++;
		d[i] = n - j;
	}
	for (int i = n - 2; i >= 0; i--)d[i] += d[i + 1];
	int ans = 0; j = 0;
	for (int i = 0; i < n; i++) {
		while (b[j] <= a[i])j++;
		ans += d[j];
	}
	cout << ans << endl;
}