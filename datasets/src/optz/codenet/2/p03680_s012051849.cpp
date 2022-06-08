#include <iostream>
#include <map>
using namespace std;

int main() {
	int N, a[100001], out = -1;
	map<int, int> mp;
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> a[i+1];
	}
	int next = 1, min = 0;
	while (true) {
		if (mp[next] == 1) break;
		if (next == 2) {
			out = min;
			break;
		}
		mp[next] = 1;
		next = a[next];
		min++;
	}
	cout << out << endl;
}