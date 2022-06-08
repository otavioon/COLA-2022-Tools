#include <bits/stdc++.h>

//d以上の数が使えるか？
bool usable(bool D[], int d) {
	for(int i = d; i < 10; ++i) {
		if(D[i]) return true;
	}
	return false;
}

//d以上の数で使えるもののうち，最も小さいものを返す
int minimum(bool D[], int d) {
	for(int i = d; i < 10; ++i) {
		if(D[i]) return i;
	}
	return -1;
}

int main(void) {
	int N, K;
	bool D[] = {true, true, true, true, true, true, true, true, true, true};
	std::vector<int> digits;
	std::cin >> N >> K;
	for(int i = 0; i < K; ++i) {
		int t;
		std::cin >> t;
		D[t] = false;
	}
	int n = N;
	for(int i = 0; n != 0; ++i) {
		digits.push_back(n % 10);
		n /= 10;
	}
	int overflow = -1;//その桁以上の数字が使えない最大(最左)の桁
	for(int i = digits.size() - 1; i != -1; --i) {
		if(!usable(D, digits[i])) {
			overflow = i;
			break;
		}
	}
	int result = 0;
	for(int i = 0; i <= overflow; ++i) {
		result += std::pow(10, i) * minimum(D, 0);
	}
	if(overflow != -1) {
		digits.push_back(0);
		digits[overflow + 1] += 1;
	}
	for(int i = overflow + 1; i < digits.size(); ++i) {
		//ここでは絶対にdigits[i] != 9
		if(!usable(D, digits[i])) {
			digits[i + 1] += 1;
			result += std::pow(10, i) * minimum(D, 0);
		} else {
			result += std::pow(10, i) * minimum(D, digits[i]);
		}
	}
	std::cout << result << '\n';
	return 0;
}

