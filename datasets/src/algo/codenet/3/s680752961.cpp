#include<iostream>
#include<algorithm>
using namespace std;
int main()
{
	int n,i,t,A,B,C;
	cin >> n;
	int a[n], b[n], c[n];
	for (i = 0; i < n; i++)cin >> a[i];
	for (i = 0; i < n; i++)cin >> b[i];
	for (i = 0; i < n; i++)cin >> c[i];
	sort(a, a + n);
	sort(b, b + n);
	sort(c, c + n);
	for (B=t=A=C=0; B < n; B++) {
		for (; A < n and a[A] < b[B];A++)
		for (; C < n and b[B] >= c[C];C++)
		t += A*(n-C);
	}
	cout << t;
	return 0;
}