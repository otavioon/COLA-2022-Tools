#include <iostream>
#include <cstdio>
#include <set>
using namespace std;

int n, s, x;
multiset<int> v;
int main()
{
	int i, t;
	multiset<int>::iterator it;
	cin >> n;
	for (i = 0; i < n; i++) {
		scanf ("%d", &t);
		v.insert(t);
	}
	while (!v.empty()) {
		x = *v.rbegin();
		v.erase(v.find(x));
		for (i = 1; i < x; i *= 2);
		it = v.find(i - x);
		if (it != v.end()) {
			s++;
			v.erase(it);
		}
	}
	cout << s;
    return 0;
}
