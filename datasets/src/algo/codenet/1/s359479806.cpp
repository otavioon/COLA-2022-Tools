#include <bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio( false );

	const int n = 3;

	int c[n][n] = {};
	for( int i = 0; i < n*n; ++i ) {
		cin >> c[i/n][i%n];
	}

	bool result = true;

	for( int i = 1; i < n; ++i ) {
		int x = c[i][0] - c[i-1][0];
		int y = c[i][1] - c[i-1][1];
		int z = c[i][2] - c[i-1][2];

		if( x != y || y != z ) {
			result = false;
			break;
		}
	}

	cout << (result ? "Yes" : "No") << endl;

	return 0;
}
