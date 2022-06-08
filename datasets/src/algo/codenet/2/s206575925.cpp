#include <iostream>
#include <algorithm>
using namespace std;

bool check(long long a, long long b) {
	long long c = a + b;

	while (1) {
		if (c == 1) {
			return true;
		}
		else if (c % 2 == 1) {
			return false;
		}
		c /= 2;
	}
}

int main() {
	long long n;
	static long long a[200000];
	static bool b[200000];
	long long count = 0;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
		b[i] = true;
	}

	sort(a, a + n);

	for (long long i = n - 1; i >= 1; i--) {
		if (b[i]) {
			long long k = 2;
			for (int j = 1; j <= 30; j++) {
				if (k > a[i]) {
					break;
				}
				else {
					k *= 2;
				}
			}

			k = k - a[i];

			long long end = i - 1;
			long long start = 0;
			long long mid = (start + end) / 2;

			if (a[end] == k && b[end]) {
				//cout << a[i] << " " << a[end] << endl;
				count++;
				b[end] = false;
				b[i] = false;
			}
			else if (a[start] == k && b[start]) {
				//cout << a[i] << " " << a[start] << endl;
				count++;
				b[start] = false;
				b[i] = false;
			}
			else {
				while (1) {
					if (a[mid] > k) {
						end = mid;
					}
					else if (a[mid] < k) {
						start = mid;
					}
					else if (a[mid] == k) {
						if (b[mid]) {
							//cout << a[i] << " " << a[mid] << endl;
							count++;
							b[mid] = false;
							b[i] = false;
							break;
						}
						else {
							end--;
							if (a[end] == k && b[end]) {
								//cout << a[i] << " " << a[end] << endl;
								count++;
								b[end] = false;
								b[i] = false;
								break;
							}
						}
					}
					mid = (start + end) / 2;
					if (end - start <= 1) { break; }
				}
			}
		}
	}

	cout << count << endl;
}