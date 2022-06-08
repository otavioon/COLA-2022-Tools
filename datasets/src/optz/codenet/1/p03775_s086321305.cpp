#include <iostream>
using namespace std;
int k(long n) {
	if (n < 10)return 1;
	else if (n < 100) return 2;
	else if (n < 1000) return 3;
	else if (n < 10000) return 4;
	else if (n < 100000) return 5;
	else if (n < 1000000) return 6;
	else if (n < 10000000) return 7;
	else if (n < 100000000) return 8;
	else if (n < 1000000000) return 9;
	else if (n < 10000000000) return 10;
}
int main() {
	long n;
	cin >> n;
	long ans = 1000000000;
	for (int i = 1; i <= 100000; i++) {
		if (n%i == 0) {
			long pre;
			long b;
			b = n / i;
			if (b > i) pre = k(b);
			else pre = k(i);
			if (ans > pre) ans = pre;
		}
	}
	cout<<ans<<endl;
	return 0;
}