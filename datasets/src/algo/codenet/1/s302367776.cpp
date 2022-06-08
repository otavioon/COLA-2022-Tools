#include <bits/stdc++.h>

#define pout(n)  printf ("%d\n", n)

#define rep(i,a,n) for (int i = a;i < n;i++)
#define per(i,n,a) for (int i = n-1;i >= a;i--)

const int d4x[4] = {1, 0, -1, 0};
const int d4y[4] = {0, 1, 0, -1};
const int d8x[8] = { 1,1,0,-1,-1,-1,0,1 };
const int d8y[8] = { 0,1,1,1,0,-1,-1,-1 };

#define MAX_N (int)2e5+20

typedef long long ll;
using namespace std;

int a[3][3];
int main() {
	rep(i,0,3){
        rep(j,0,3){
			cin >> a[i][j];
		}
	}
	if (a[1][0] - a[0][0] == a[1][1] - a[0][1] &&
		a[1][1] - a[0][1] == a[1][2] - a[0][2] &&
		a[2][0] - a[1][0] == a[2][1] - a[1][1] && 
		a[2][1] -a[1][1]==a[2][2]-a[1][2]){
		cout << "Yes" << endl;
	}
	else cout << "No" << endl;
    return 0;
}