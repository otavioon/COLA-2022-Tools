#include<iostream>
#include<vector>
#include<algorithm>
#include<cmath>
#include<string>
#include<stack>


using namespace std;


int main() {

	int c[10];
	int sum = 0;

	for (int i = 0; i < 9; i++) {
		cin >> c[i];
		sum += c[i];
	}

	if (sum % 3 == 0) cout << "Yes" << endl;
	else cout << "No" << endl;
	





	return 0;
}


