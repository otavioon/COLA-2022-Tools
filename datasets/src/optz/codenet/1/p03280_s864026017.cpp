#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int t,a,b;
	t = 1;
	while(t--) {
	 cin >> a >> b;
	 cout << a * b - a - b + 1 << endl;
	}
	return 0;
}

