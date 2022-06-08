#include<iostream>
#include<algorithm>
using namespace std;
int main()
{
	int n,i,j,temp,A,C;
	cin >> n;
	int a[n], b[n], c[n];
	for (i = 0; i < n; i++)cin >> a[i];
	for (i = 0; i < n; i++)cin >> b[i];
	for (i = 0; i < n; i++)cin >> c[i];
	sort(a, a + n);
	sort(b, b + n);
	sort(c, c + n);
	temp = 0;
	for (i = 0; i < n; i++) {
		A = C = 0;
		for (j = 0; j < n and a[j] < b[i]; j++) {
			A++;
		}
		for (j = n - 1; j > -1 and b[i] < c[j]; j--) {
			C++;
		}
		temp += A*C;
	
	}

	cout << temp;

	return 0;
}