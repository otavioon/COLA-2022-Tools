#include <iostream>
#include<algorithm>
using namespace std;

int main() {
	long long  n, a[10000],i;
	long long sum,min,max;

	cin >> n;

	sum = 0;
	for (i = 0; i < n; i++) {
		cin >> a[i];
		sum = sum+a[i];

		if (n == 1) {
			max = a[i];
			min = a[i];
		}
		else {
			if (i == 0);
			else if (a[i] < a[i - 1])
				min = a[i];
			else if (a[i] > a[i - 1])
				max = a[i];
		}
	}
	cout << min << endl;
	cout << max << endl;
	cout << sum << endl;

}