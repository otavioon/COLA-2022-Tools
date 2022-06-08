#include <cstdio>
#include <cstring>
#include <cmath>
#include <cstdlib>
#include <iostream>
#include <algorithm>

using namespace std;

int ma[4][4];
int tnt ,ans;

int main()
{
	for(int i = 1 ; i <= 3 ; i++){
		for(int j = 1 ; j <= 3 ;j++ ){
			cin >> ma[i][j];
			tnt += ma[i][j];
		}
	}
	ans = ma[1][1] + ma[2][2] + ma[3][3];
	ans *= 3;
	if(ans != tnt )cout << "No" << endl;
	else cout << "Yes" << endl;
}
