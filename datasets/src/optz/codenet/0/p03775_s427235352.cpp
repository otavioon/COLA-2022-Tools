#include<iostream>
#include<algorithm>
#include<math.h>
using namespace std;
using ll = long long;

int main() {
	ll n;
	cin >> n;
	int ans = n/2;
	for (int i = 1;i < sqrt(n);i++) {
		if (n%i == 0) {
			int j = n / i;
			int a = 0;
			for (int k = 0;k < 11;k++) {
				if (j / 10 == 0) {
					a++;
					ans = min(ans, a);
					break;
				}
				a++;
				j /= 10;
			}
		}
	}
	cout << ans << endl;
}