#include <iostream>
#include <string>
#include <algorithm>
#include <iomanip>
#include <vector>
#include <map>
#include <cmath>

int main() {
	long long int n;
	std::cin >> n;
	std::string s = std::to_string(n);
	int ans = s.size();
	for (int i = 2;i <= 100000;i++) {
		if (n%i == 0) {
			if (i < n / i) {
				std::string t = std::to_string(n / i);
				if (ans > t.size()) {
					ans = t.size();
				}
			}
			else {
				std::string t = std::to_string(i);
				if (ans > t.size()) {
					ans = t.size();
				}
			}
		}
	}
	std::cout << ans << std::endl;
	return 0;
}