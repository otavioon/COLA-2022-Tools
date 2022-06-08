#include "iostream"

using namespace std;

long long int N;
long long int a=1;
long long int b;
long long int c;
int num;
int num2;
int f=20;

int main() {
	cin >> N;
	while (a*a <= N) {
		if (N%a == 0) {
			b = a;
			num = 0;
			while (b >= 10) {
				b /= 10;
				num++;
			}
			c = N / a;
			num2 = 0;
			while (c >= 10) {
				c /= 10;
				num2++;
			}
			if (num >= num2 && f > num)f = num+1;
			if (num<num2 && f>num2)f = num2+1;
		}
		a++;
	}
	cout << f << endl;
}