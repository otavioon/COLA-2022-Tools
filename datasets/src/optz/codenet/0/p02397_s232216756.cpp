#include<iostream>
#include<vector>
#include<string>
#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<algorithm>
using namespace std;
int a_1(int a) {//素数判定
	int x = 0;
	for (int i = 2; i < a; i++) {
		if (a % i == 0)x++;
	}
	if (x == 0) {
		return 0;//素数であるとき
	}
	if (x != 0) {
		return 1;//素数でないとき
	}
}
int yakusuu(int n) {
	int ans = 1;
	for (int i = 2; i <= sqrt(n); i++) {
		int cnt = 0;
		while (n % i == 0) {
			cnt++;
			n /= i;
		}
		ans *= (cnt + 1);
		if (n == 1) break;
	}
	if (n != 1) ans *= 2;
	return ans;
}
int gcd(int a, int b) {
	if (a < b) {
		a ^= b;
		b ^= a;
		a ^= b;
	}
	return b ? gcd(b, a % b) : a;
}
int lcm(int a, int b) {
	return a * b / gcd(a, b);
}
int main() {
	int x, y;
	for (int i = 0;; i++) {
		cin >> x >> y;
		if (x == 0 && y == 0)break;
		cout << min(x, y) << " " << max(x, y) << endl;
	}
	return 0;
}
