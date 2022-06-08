#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	vector<int> vec(2);
	while (1) {
		cin >> vec[0] >> vec[1];
		if (vec[0] == 0 && vec[1] == 0) break;
		sort(vec.begin(), vec.end());
		cout << vec[0] << " " << vec[1] << endl;
	}
	return 0;
}
