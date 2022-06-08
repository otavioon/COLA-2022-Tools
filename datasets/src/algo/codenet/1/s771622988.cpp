#include <bits/stdc++.h>
using namespace std;

int main()
{
	int mat[3][3];
	for ( int i = 0; i < 3; i++ ) {
		cin >> mat[i][0] >> mat[i][1] >> mat[i][2];
	}
	int diff1 = mat[0][1] - mat[0][0], diff2 = mat[0][2] - mat[0][1];
	if ( mat[1][1] - mat[1][0] == diff1 && mat[1][2] - mat[1][1] == diff2 &&
		 mat[2][1] - mat[2][0] == diff1 && mat[2][2] - mat[2][1] == diff2    ) {
		cout << "Yes" << endl;
	} else {
		cout << "No" << endl;
	}
	return ( 0 );
}
