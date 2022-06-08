#include <iostream>
#include <string>
#include <algorithm>
#include <iomanip>
#include <vector>
#include <map>
#include <cmath>

int main() {
	int n, a[100000], b[100000], c[100000];
	std::cin >> n;
	for (int i = 0;i < n;i++) {
		std::cin >> a[i];
	}
	for (int i = 0;i < n;i++) {
		std::cin >> b[i];
	}
	for (int i = 0;i < n;i++) {
		std::cin >> c[i];
	}
	std::sort(a, a + n);
	std::sort(b, b + n);
	std::sort(c, c + n);
	int ans = 0;
	for (int i = 0;i < n;i++) {
		for (int j = 0;j < n;j++) {
			if (b[j] > a[i]) {
				for (int k = 0;k < n;k++) {
					if (c[k] > b[j]) {
						ans += n-k;
						break;
					}
				}
			}
		}
	}
	std::cout << ans << std::endl;
	return 0;
}