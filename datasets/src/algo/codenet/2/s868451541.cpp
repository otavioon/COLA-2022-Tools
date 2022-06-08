#include <iostream>
#include <cstdio>
#include <set>
using namespace std;

int n, c;
multiset<int> a;
int main()
{
	int t, i;
	multiset<int>::iterator it;
	cin >> n;
	while (n--) {
		scanf("%d", &t);
		a.insert(t);
	}
	while (!a.empty()) {
		t = *a.rbegin();
		a.erase(a.find(t));
		for (i = 1; i <= t; i *= 2);
		it = a.find(i - t);
		if (it != a.end()) {
			a.erase(it);
			c++;
		}
	}
    cout << c << endl;
    return 0;
}