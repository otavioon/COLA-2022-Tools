
#include <vector>
#include <iostream>
#include <algorithm>
#include <string>
#include <set>
#include <vector>
#include <queue>
using namespace std;


vector<int> dk;

bool check(int n) {
	bool flag = true;
	while (n > 0 && flag) {
		int v = n % 10;
		if (find(dk.begin(), dk.end(), v) != dk.end()) {
			flag = false;
		}
		n /= 10;
	}
	return flag;
}

int main(){
	int n, k;
	cin >> n >> k;
	for (int i = 0; i < k; ++i) {
		int d;
		cin >> d;
		dk.push_back(d);
	}
	int nn = n;
	while (!check(nn)) {
		nn++;
	}
	cout << nn << endl;
	return 0;
}