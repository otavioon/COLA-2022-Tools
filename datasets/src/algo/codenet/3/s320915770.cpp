#include <iomanip>
#include <string>
#include <iostream>
#include <algorithm>
#include <math.h>
using namespace std;
int main()
{
	long long int n, a[100000], b[100000], c[100000];
	long long int cnt = 0, yan = 0, yojo = 0;
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
		for (int j = yan; j < n; j++) {
			if (a[i] < b[j]) {
				for (int k = yojo ; k < n; k++) {
					if (b[j] < c[k]) {
						cnt += n - k;
						break;
					}
					else {
						yojo = k;
					}
				}
			}
			else {
				yan = j;
			}
		}
		yojo = 0;
	}
	cout << cnt << endl;
	return 0;
}