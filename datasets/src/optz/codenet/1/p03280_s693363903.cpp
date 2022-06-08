#include "bits/stdc++.h"
using namespace std;

/*第二引数で第一引数を割ったときの切り上げの計算*/
long long int maxtime(long long int x, long long int y) {
	return(x + y - 1) / y;

}
/*最大公約数*/
long long int lcm(long long int number1, long long int number2) {
	long long int m = number1;
	long long int n = number2;

	if (number2 > number1) {
		m = number2;
		n = number1;
	}
	long long int s = -1;
	while (s != 0) {
		s = m % n;
		m = n;
		n = s;
	}
	return m;
}
/*最大公倍数*/
long long int gcd(long long int number1, long long int number2) {
	long long int m = number1;
	long long int n = number2;
	return m / lcm(m, n) * n;
}
int main() {
	int A, B;
	cin >> A >> B;
	cout << (A - 1) * (B - 1);
}