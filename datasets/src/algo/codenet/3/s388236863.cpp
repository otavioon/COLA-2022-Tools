#include <iomanip>
#include <string>
#include <iostream>
#include <algorithm>
#include <math.h>
using namespace std;
int main()
{
	long long int n, a[100000], b[100000], c[100000];
	long long int cnt = 0, yan[100000] = {};
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	for (int i = 0; i < n; i++) {
		cin >> b[i];
	}
	for (int i = 0; i < n; i++) {
		cin >> c[i];
	}
	sort(a, a + n);
	sort(b, b + n);
	sort(c, c + n);
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (a[i] < b[j]) {
				cnt +=n;
				yan[j]++;
			}
		}
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (b[i]>=c[j]) {
				cnt = cnt - yan[i];
			}
		}
	}
	cout << cnt << endl;
	return 0;
}