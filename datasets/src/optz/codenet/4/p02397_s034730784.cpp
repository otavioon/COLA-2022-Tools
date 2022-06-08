#include<iostream>
using namespace std;

int main()
{
	long int x = 1, y = 1;
	while (x != 0 && y != 0) {
		int a, b;
		cin >> x >> y;
		if (x != 0 && y != 0) {
			if (x < y) {
				a = x, b = y;
			}
			else if (x >= y) {
				a = y, b = x;
			}
			cout << a << " " << b << endl;
		}
	}
	return 0;
}