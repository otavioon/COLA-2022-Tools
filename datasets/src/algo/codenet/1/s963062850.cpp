#include <iostream>
#include <algorithm>
#include <iomanip>
#include <string>
#include <vector>
#include <math.h>
#include <queue>
#include <deque>
#include <stack>
#include <map>
#define PI 3.14159265359
typedef long long ll;
const int MOD = 1e9+7;
const ll LLINF = 7e18;
using namespace std;


int main(){
	int c[3][3];
	for (int i = 0; i < 3; i++){
		for (int j = 0; j < 3; j++){
			cin >> c[i][j];
		}
	}

	int a1 = 0;
	int b1 = c[0][0];
	int b2 = c[1][0];
	int b3 = c[2][0];
	int a2 = c[0][1] - b1;
	int a3 = c[0][2] - b1;
	if (c[1][1] == a2+b2 && c[2][1] == a2+b3 && c[1][2] == a3+b2 && c[2][2] == a3+b3){
		cout << "Yes" << endl;
	}else{
		cout << "No" << endl;
	}
	return 0;
}