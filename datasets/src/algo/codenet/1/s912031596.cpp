#include <cstdio>
#include <cstring>
#include <cmath>
#include <cstdlib>
#include <iostream>
#include <algorithm>

using namespace std;

int map[4][4];
int tnt ,ans;

int main()
{
	for(int i = 1 ; i <= 3 ; i++){
		for(int j = 1 ; j <= 3 ;j++ ){
			cin >> map[i][j];
			tnt += map[i][j];
		}
	}
	ans = map[1][1] + map[2][2] + map[3][3];
	ans *= 3;
	if(ans != tnt )cout << "No" << endl;
	else cout << "Yes" << endl;
}

