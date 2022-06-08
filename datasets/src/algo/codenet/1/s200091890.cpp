#include <iostream>

using namespace std;

int main() {
	int sum = 0;
	for (int i = 0; i < 9; i++) {
		int x;
		cin >> x;
		sum += x;
	}
	if ((sum % 3) == 0) {
		cout << "Yes\n";
	} else {
		cout << "No\n";
	}
}