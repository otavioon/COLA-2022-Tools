#include <iostream>
using namespace std;

int main() {
	int a;
	int b;
	cin >>  a;
	cin >> b;

	if (a == 1 && b != 1) {
		cout << "Alice" << endl;
		exit(1);
	}
	if (a != 1 && b == 1) {
		cout << "Bob" << endl;
		exit(1);
	}
	if (a == 1 && b == 1) {
		cout << "Draw" << endl;
		exit(1);
	}
	if (a > b){
		cout << "Alice" << endl;
	}
	if (a == b) {
		cout << "Draw" << endl;
	}
	if (a < b) {
		cout << "Bob" << endl;
	}

}