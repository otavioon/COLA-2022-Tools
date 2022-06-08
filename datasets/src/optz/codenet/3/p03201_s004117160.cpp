#include <iostream>
#include <vector>
#include <list>
#include <algorithm>

using namespace std;

int main(int, char**)
{
	unsigned int n;
	vector<unsigned int> m;
	vector<unsigned int> p;
	list<int> d;
	unsigned long long ans = 0;
	std::cin >> n;

	unsigned int t = 2;
	p.push_back(t);
	while (t < 2000000000) {
		t *= 2;
		p.push_back(t);
	}

	m.resize(n);
	for (unsigned int i = 0; i < n; i++) {
		cin >> m[i];
	}
	
	sort(m.begin(), m.end());

	int i;
	for (i = n; i >= 0; i--) {
		for (int j = i - 1; j >= 0; j--) {
			for (list<int>::iterator k = d.begin(); k != d.end(); k++) {
				if (*k == j)
					j--;
			}
			for (int k = 0; k < p.size(); k++) {
				if (m[i] + m[j] == p[k]) {
					ans++;
					d.push_back(j);
					j = 0;
					break;
				}
			}
		}
	}

	cout << ans << endl;
	return 0;

}
