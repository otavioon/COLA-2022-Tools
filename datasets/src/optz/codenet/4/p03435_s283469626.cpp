#include<bits/stdc++.h>

#define INF 1000000007
#define LINF 1000000000000000007

using namespace std;

typedef long long Int;
typedef pair<Int, Int> P;

Int gcd(Int x, Int y){
	if(y == 0)
		return x;
	return gcd(y, x % y);
}

Int lcm(Int x, Int y){
	return x * y / gcd(x, y);
}

bool sosuu(int x){
	bool b = 1;
	if(x == 1) b = 0;
	for(int i = 2; i * i <= x; i++){
		if(x % i == 0) {
			b = 0;
			break;
		}
	}
	return b;
}

int c[3][3];

int main(){
	int d[3] = {101,101,101};
	for(int i = 0; i < 3; i++){
		for(int j = 0; j < 3; j++){
			cin >> c[i][j];
			d[i] = min(d[i], c[i][j]);
		}
	}
	
	bool b = 0;
	for(int i = 0; i <= d[0]; i++){
		for(int j = 0; j <= d[1]; j++){
			for(int k = 0; k <= d[2]; k++){
				if(c[0][0]-i == c[1][0]-j && c[2][0]-k == c[0][0]-i){
					if(c[0][1]-i == c[1][1]-j && c[2][1]-k == c[0][1]-i){
						if(c[0][2]-i == c[1][2]-j && c[2][2]-k == c[0][2]-i){
							b = 1;
						}
					}
				}
			}
		}
	}
	
	if(b) cout << "Yes" << endl;
	else cout << "No" << endl;
	
	return 0;
}