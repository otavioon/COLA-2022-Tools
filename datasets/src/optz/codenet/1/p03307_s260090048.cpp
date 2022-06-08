#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int t;
	long long n;
	t = 1;
	while(t--) {
	 cin >> n;
	 if(n % 2)
	  cout << 2 * n << endl;
	 else
	  cout << n << endl;
	}
	return 0;
}

