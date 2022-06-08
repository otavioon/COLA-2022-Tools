#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	int n;
	cin >> n;
	vector<string> s(n);
	for (int i = 0; i < n; i++) {
		cin >> s.at(i);
	}
	int m;
	cin >> m;
	vector<string> t(m);
	for (int i = 0; i < m; i++) {
		cin >> t.at(i);
	}
	vector<int> resultPoint(0);

	while (s.size() > 0) {
		string first = s.at(0);
		s.erase(s.begin());
		int count = 1;
		while (true) {
			auto it = find(s.begin(), s.end(), first);
			if (it != s.end()) {
				count++;
				s.erase(it);
			}
			else {
				break;
			}
		}
		while (true) {
			auto it = find(t.begin(), t.end(), first);
			if (it != t.end()) {
				count--;
				t.erase(it);
			}
			else {
				break;
			}
		}
		resultPoint.emplace_back(count);
	}
	while (t.size() > 0) {
		string first = t.at(0);
		t.erase(t.begin());
		int count = -1;
		while (true) {
			auto it = find(t.begin(), t.end(), first);
			if (it != t.end()) {
				count--;
				t.erase(it);
			}
			else {
				break;
			}
		}
		resultPoint.emplace_back(count);
	}
	
	int max = resultPoint.at(0);
	for (int i = 1; i < resultPoint.size();i++) {
		if (max < resultPoint.at(i)) {
			max = resultPoint.at(i);
		}
	}
	if (max < 0) {
		max = 0;
	}
	cout << max;

}