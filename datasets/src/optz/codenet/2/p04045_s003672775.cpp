// scanf 等でエラーを出さないように追加
#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
#include <string.h>
#include <math.h>
#include <limits.h>
#include <iostream>
#include <string>
#include <vector>
#include <memory>
#include <algorithm>
#include <numeric>
#include <set>
#include <functional>


using namespace std;


typedef long long ll;


bool isContained(const int number, const vector<int> &numbers) {
	for (auto itr = numbers.begin(); itr != numbers.end(); ++itr) {
		if (number == (*itr)) return true;
	}
	return false;
}

int getIntegerPow(const int x, const int n) {
	int result = 1;
	for (int i = 0; i < n; i++) {
		result *= x;
	}
	return result;
}

int main() {

	const int max_money = 9999;

	int N, K;
	scanf("%d %d", &N, &K);

	vector<int> D;
	for (int i = 1; i <= K; i++) {
		int d;
		scanf("%d", &d);
		if (d == '\n') {
			break;
		}
		D.push_back(d);
	}

	const int start_digit = log10(N);
	
	for (int money = N; money <= max_money; money++) {
		
		int now_money = money;
		bool canBeUsed = true;

		for (int digit = start_digit; digit >= 0; digit++) {
			const int number = now_money % getIntegerPow(10, digit);
			if (isContained(number, D)) {
				canBeUsed = false;
			}
		}

		if (canBeUsed) {
			printf("%d\n", money);
			return 0;
		}
	}

	return 0;
}